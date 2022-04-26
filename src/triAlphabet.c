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
void printRes(ResList*);
void addToRes(ResList *, char);


void huffman(ChainedList* list){
	while(list->next != NULL){//make tree from node list

		BinaryTree * head1 = getHead(&list);//get 2 first elt
		BinaryTree * head2 = getHead(&list);
		BinaryTree * tree = createTreeNode(head1, head2); //make tree
		
		addToChainedList_tree(list, tree);//add tree to chain and sort
	}

	ResList * resList = NULL;

	while(!(list->node->nextL == NULL && list->node->nextR == NULL)){ //get res from tree
		char * path = malloc(sizeof(char));
		path[0] = '\0';
		huffmanAux(list->node, resList, path);
	}
}

void printRes(ResList * res){
	printf("%s", res->isLeft ? "0" : "1");
	if(res->next != NULL)
		printRes(res->next);
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
}
