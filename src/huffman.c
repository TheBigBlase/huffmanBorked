#include "triAlphabet.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

extern short alphabetSize;
// "private" funcs 
void huffmanAux(BinaryTree*, ResList*, char*);
void getHuffmanRes(BinaryTree*);
void addToRes(ResList *, char);


void huffman(ChainedList* list, char * file){
	while(list->next != NULL){//make tree from node list

		BinaryTree * head1 = getHead(&list);//get 2 first elt
		BinaryTree * head2 = getHead(&list);
		BinaryTree * tree = createTreeNode(head1, head2); //make tree
		
		addToChainedList_tree(list, tree);//add tree to chain and sort
	}
	printChainedList(list);
		printBinaryTree(list->node);

	ResList * resList = malloc(sizeof(ResList));
	resList->path = "";
	resList->next = NULL;

	char * fileNoExt = malloc(strlen(file) + 1);
	strcpy(fileNoExt, file);
	strtok(fileNoExt, ".");

	char * fileCodex = malloc(strlen(fileNoExt) + 10);
	strcpy(fileCodex, fileNoExt);
	strcat(fileCodex, "_codex.txt");

	//freopen(fileCodex, "w+", stdout); //resume to stdout

	while(!(list->node->nextL == NULL && list->node->nextR == NULL)){ //get res from tree
		char * path = malloc(sizeof(char));
		path[0] = '\0';
		huffmanAux(list->node, resList, path);
	}

	printResList(resList);
	char* fileBin = malloc(strlen(fileNoExt) + 4);//9 new chars in name
	strcpy(fileBin, fileNoExt); 
	strcat(fileBin, ".bin"); 

	//freopen(fileBin, "w+", stdout);//print to file bin

	FILE *tmp = fopen(file, "r");
	char c;
	while(1) {
		c = fgetc(tmp);
		if(feof(tmp)){break;} //ugly but has to check after 
		printf("%s", getPathFromChara(resList, c));
	}
	fclose(tmp);
	printf("\n");

	freopen("/dev/tty", "w", stdout); //resume to stdout
}

void huffmanAux(BinaryTree * tree, ResList * res, char * path){
	if(!tree)	return;

	if(tree->nextL != NULL){
		char * pathNext = malloc(sizeof(char) * (strlen(path) + 2));//counting nullbyte
		strcpy(pathNext, path);

		pathNext[strlen(path)] = '0';//counting to \0 so taking path
		pathNext[strlen(path)+1] = '\0';//ends with nullbyte

		huffmanAux(tree->nextL, res, pathNext);
		free(pathNext);
		tree->nextL = NULL;
	}
	if(tree->nextL == NULL && tree->nextR == NULL){
		printf("%s : %c\n", path, tree->chara);
		addToResList(res, path, tree->chara);
	}

	if(tree->nextR != NULL){
		char * pathNext = malloc(sizeof(char) * (strlen(path) + 2));//counting nullbyte
		strcpy(pathNext, path);

		pathNext[strlen(path)] = '1';
		pathNext[strlen(path)+1] = '\0';//ends with nullbyte

		huffmanAux(tree->nextR, res, pathNext);
		free(pathNext);
		tree->nextR = NULL;
	}
		free(tree);
		tree->nextL = NULL;
		tree->nextR = NULL;
}
