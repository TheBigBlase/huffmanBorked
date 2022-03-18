#include "triAlphabet.h"
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>


void addEltToLeft(DataTree* ptr, int chara){
	if(ptr->nextL == NULL){
		ptr->nextL = (struct DataTree*)malloc(sizeof(struct DataTree));
		ptr->nextL->chara = chara;
		ptr->nextL->count = 0;
		ptr->nextL->nextL = NULL;
		ptr->nextL->nextR = NULL;
	}
	else
		addEltToLeft(ptr->nextL, chara);
}

void addToChainedList(struct ChainedList* list, char c){
	if(list->chara == c){
		list->count++;
		return;
	}
	if(list->next == NULL){
		list->next = (struct ChainedList*)malloc(sizeof(struct ChainedList));
		list->next->next = NULL;
		list->next->chara = c;
		list->next->count=1;
	}
	else 
		addToChainedList(list->next, c);
}

void printDataTree(struct DataTree* tree){
	if(tree == NULL) return;
	if(!(tree->nextL == NULL && tree->nextR == NULL)){
		printDataTree(tree->nextL);
		printf("%c", tree->chara);
		printDataTree(tree->nextR);
	}
}

void printPointers(struct ChainedList* l){
	if(l == NULL) return;
	if(l->next != NULL){
		printf("*list: %p\n",l);
		printPointers(l->next);
	}
}

void printChainedList(struct ChainedList* l){
	if(l == NULL) return;
	if(l->next != NULL){
		printf("char : %c ; occurence : %d\n",l->chara, l->count);
		printChainedList(l->next);
	}
}

ChainedList loadFile(char* file){
	ChainedList res = { chara:0, count:0, next:NULL};
	unsigned int counter = 0;
	FILE *tmp =fopen(file, "r");
	int c;
	while(1) {
		c = fgetc(tmp);
		//printf("%c", c);//inc c
		//addEltToLeft(&res, c);
		addToChainedList(&res, c);
		if(feof(tmp)){break;} //ugly but has to check after 
		counter++;
	}

	//printf("\n");
	fclose(tmp);
	//printDataTree(&res);
	//printChainedList(&res);
	//printPointers(&res);
	return res;
}

void insertNode(struct DataTree * tree, char c, int count){
	
}

void sortByOccurence(ChainedList * list){

}

//TODO mege sort (greenend.org.uk)
//Root
void swap(ChainedList * x, ChainedList *y){
	printf("old next %p, old root %p\n", x, y);
	ChainedList * tmp = malloc(sizeof(ChainedList));
	tmp->count = x->count;//TODO do that better
	tmp->chara = x->chara;
	x->count = y->count;
	x->chara = y->chara;
	y->count=tmp->count;
	y->chara=tmp->chara;
	free(tmp);
	printf("new next %p, new root %p\n", x, y);
}


void bubbleSort(ChainedList *head){
	bool shouldContinue = true;
	ChainedList *i;
	ChainedList *j = NULL;

	/* Checking for empty list */
	if (head == NULL)
		return;

	while(shouldContinue){
		shouldContinue = 0;
		i = head;

		while (i->next != j){
			if (i->count > i->next->count){
				swap(i, i->next);
				shouldContinue = 1;
			}
			i = i->next;
		}
		j = i;
	}
}

