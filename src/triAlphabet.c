#include "triAlphabet.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

extern short alphabetSize;
// "private" funcs 
void huffmanAux(BinaryTree* tree, ResList* list);
void getHuffmanRes(BinaryTree*);
void printRes(ResList*);
void addToRes(ResList * res, char chara);

short resSize = 1;

void huffman(ChainedList* list){
	while(list->next != NULL){//make tree from node list

		BinaryTree * head1 = getHead(&list);//get 2 first elt
		BinaryTree * head2 = getHead(&list);
		BinaryTree * tree = createTreeNode(head1, head2); //make tree
		
		addToChainedList_tree(list, tree);//add tree to chain and sort


	}
	ResList * resList = NULL;

	printBinaryTree(list->node);

	while(!(list->node->nextL == NULL && list->node->nextR == NULL) && alphabetSize != resSize){ //get res from tree
		huffmanAux(list->node, resList);
		printRes(resList);
	}

	printf("----------------- RES --------------\n");
	//printBinaryTree(list->node);
	printRes(resList);
	//printf("\n------------------------\n");
}

void huffmanAux(BinaryTree* tree, ResList* list){//TODO free tree
	if(tree == NULL) 
		exit(1);//error so exit
	

	else if(tree->nextL != NULL){
		list = malloc(sizeof(ResList));//NOTE wait wtf
		list->isLeft = 0;
		list->next = NULL;

		printf("0");

		if(tree->nextL->nextL == NULL && tree->nextL->nextR == NULL){//if leaf
			printf(" : %c\n", tree->nextL->chara);
			free(tree->nextL);
			tree->nextL = NULL;
			resSize++;
		}

		else 
			huffmanAux(tree->nextL, list->next);//should return from aux, not that bs
	}

	else if(tree->nextR != NULL){
		list = malloc(sizeof(ResList));
		list->next = NULL;
		list->isLeft = 1;

		printf("1");

		if(tree->nextR->nextL == NULL && tree->nextR->nextR == NULL){//if leaf
			printf(" : %c\n", tree->nextR->chara);
			free(tree->nextR);
			tree->nextR = NULL;
			resSize++;
			//huffmanAux(tmp, list->next);
		}

		else 
			huffmanAux(tree->nextR, list->next);
	}

	else{//if left and right are null, but tree is not
		//printf("Chara : %c\n", tree->chara); ?
		free(tree);
	}
}

void printRes(ResList * res){
	printf("%s", res->isLeft?"0":"1");
	if(res->next != NULL)
		printRes(res->next);
}

void addToRes(ResList * list, char c){//not doing the right thing oopsie
	//read branch from root to leaf, and add chara at end
}
