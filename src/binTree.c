#include "triAlphabet.h"
#include <stdio.h>
#include <malloc.h>


//"private" funcs
void printBinaryTreeAux(BinaryTree *, short);

void printBinaryTree(BinaryTree* tree){
	printf("[BEGIN PRINT TREE]\n");
	printBinaryTreeAux(tree, 0);
	printf("[END PRINT TREE]\n");
}

void printBinaryTreeAux(BinaryTree* tree, short depth){
	if(tree == NULL) return;

	printBinaryTreeAux(tree->nextL, depth + 1);

	if(tree->nextL == NULL && tree->nextR == NULL){//if letter
		for(short i = 0 ; i < depth ; i++)// one letter 
			printf(i == depth - 1 ? "|-" : "  ");
		printf("%c\n", tree->chara);
	}

	printBinaryTreeAux(tree->nextR, depth + 1);
}

BinaryTree* getHead(ChainedList ** list){
	if(*list == NULL) return NULL;

	ChainedList tmp = **list;
	if((*list)->next != NULL){
		*list = (*list)->next;
	}
	else {
		(*list)->node = NULL;
	}

	//free(tmp);//not a pointer so no free
		
	return tmp.node;
}

BinaryTree* createTreeNode(BinaryTree* l, BinaryTree * r){
	BinaryTree * res = malloc(sizeof(BinaryTree));
	//printf("chara l : %c chara r : %c\n", l->chara, r->chara);
	res->nextL = l;
	res->nextR = r;
	res->count = l->count + r->count;
	if(l->count > r->count)
		res->chara = l->chara;
	else if(r->count > l->count)
		res->chara = r->chara;
	else 
		r->chara > l->chara ? (res->chara = l->chara) : (res->chara = r->chara);
	return res;//Drake this seems to work
}
