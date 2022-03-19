#include "triAlphabet.h"
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>


void addEltToLeft(DataTree* ptr, int chara){//useless ?
	if(ptr->nextL == NULL){
		ptr->nextL = (DataTree*)malloc(sizeof(DataTree));
		ptr->nextL->chara = chara;
		ptr->nextL->count = 0;
		ptr->nextL->nextL = NULL;
		ptr->nextL->nextR = NULL;
	}
	else
		addEltToLeft(ptr->nextL, chara);
}

void addToChainedList_char(ChainedList* list, char c){
	if(list->node && list->node->chara == c){
		list->node->count++;
		return;
	}
	if(list->next == NULL){
		list->next = (ChainedList*)malloc(sizeof(ChainedList));
		list->node = (DataTree*)malloc(sizeof(DataTree));
		list->node->chara = c;
		list->node->count = 1;
	}
	else{
		addToChainedList_char(list->next, c);
	}
}

void addToChainedList_tree(ChainedList* list, DataTree * tree){
	if(list->node && list->node->chara == tree->chara){
		list->node->count++;
		return;
	}
	if(list->next == NULL){
		list->next = (ChainedList*)malloc(sizeof(ChainedList));
		list->node = (DataTree*)malloc(sizeof(DataTree));
		list->node->chara = tree->chara;
		list->node->count = 1;
	}
	else{
		addToChainedList_char(list->next, tree->chara);
	}
}

void printDataTree(DataTree* tree){
	if(tree == NULL) return;
	if(!(tree->nextL == NULL && tree->nextR == NULL)){
		printDataTree(tree->nextL);
		printf("%c", tree->chara);
		printDataTree(tree->nextR);
	}
}

void printChainedList(ChainedList* l){
	if(l == NULL || l->node == NULL) return;
	printf("%c ; %d\n",l->node->chara, l->node->count);
	if(l->next != NULL){
		printChainedList(l->next);
	}
}

ChainedList loadFile(char* file){
	DataTree * node = malloc(sizeof(DataTree));
	ChainedList res = { node, next:NULL};
	unsigned int counter = 0;
	FILE *tmp =fopen(file, "r");
	int c;
	while(1) {
		c = fgetc(tmp);
		addToChainedList_char(&res, c);//Do we count EOL / EOF ?
		if(feof(tmp)){break;} //ugly but has to check after 
		counter++;
	}

	//printf("\n");
	fclose(tmp);
	//printDataTree(&res);
	//printChainedList(&res);
	return res;
}

void insertNode(DataTree * tree, char c, int count){//TODO
	
}

//TODO mege sort (greenend.org.uk)
void swap(ChainedList * x, ChainedList *y){
	//printf("old next %p, old root %p\n", x, y);
	ChainedList * tmp = malloc(sizeof(ChainedList));
	tmp->node->count = x->node->count;//TODO do that better
	tmp->node->chara = x->node->chara;
	x->node->count = y->node->count;
	x->node->chara = y->node->chara;
	y->node->count=tmp->node->count;
	y->node->chara=tmp->node->chara;
	free(tmp);
	//printf("new next %p, new root %p\n", x, y);
}


void bubbleSort(ChainedList *list){
	bool shouldContinue = true;
	ChainedList *i;
	ChainedList *j = NULL;

	if (list == NULL || list->node == NULL) return;

	while(shouldContinue){
		shouldContinue = false;
		i = list;

		while (i->next != j){
			if (i->next->node && i->node->count > i->next->node->count){
				swap(i, i->next);
				shouldContinue = true;
			}
			i = i->next;
		}
		j = i;
	}
}

