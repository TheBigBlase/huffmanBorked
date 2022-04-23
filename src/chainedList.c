#include "triAlphabet.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


extern short alphabetSize;
void addToChainedList_char(ChainedList* list, char c){//TODO non recursive for opti
	if(list == NULL || list->node == NULL){
		list->node = malloc(sizeof(BinaryTree));
		list->node->count = 1;
		list->node->chara = c;
		list->next = NULL;
		alphabetSize++;
	}

	else if(list->node->chara == c){
		list->node->count++;
		return;
	}

	else{
		if(list->next == NULL){
			list->next = malloc(sizeof(ChainedList));
			list->next->next = NULL;
			list->next->node = NULL; 
		}
		addToChainedList_char(list->next, c);
	}
}

void addToChainedList_tree(ChainedList * list, BinaryTree * tree){
	if(list == NULL)
		exit(-1);
	if(list->node == NULL){//if list is empty put tree there
		list->node = tree;
		return;
	}

	//check next : A->B ==> A->NEW->B
	while(list->next != NULL && tree->count > list->next->node->count){//while does not belog here
		list = list->next;
	}
	//if belong here (count)
	while(list->next != NULL && tree->count == list->next->node->count){
		if(tree->chara < list->node->chara){// order it by ascii char

			ChainedList * newNode = malloc(sizeof(ChainedList));
			newNode->node = tree;
			newNode->next = list->next;
			list->next = newNode;

			return;//ugly but it works
		}
	
		list = list->next;
	}
	//we reached the 2nd to last of the list and did not put the tree
	//we have : tree counter < next list counter
	if(list->next != NULL){
		ChainedList * newNode = malloc(sizeof(ChainedList));
		newNode->node = tree;
		newNode->next = list->next;
		list->next = newNode;
		return;
	}
	else{
		if(tree->count < list->node->count){
			list->next = malloc(sizeof(ChainedList));
			list->next->next = NULL;
			list->next->node = list->node;
			list->node = tree;
		}
		else{
		}
	}
}

void printChainedList(ChainedList* l){
	if(l == NULL || l->node == NULL) return;
	//if(l->node->chara != 0)
		printf("%c ; %d\n",l->node->chara, l->node->count);
	if(l->next != NULL){
		printChainedList(l->next);
	}
}

//TODO mege sort (greenend.org.uk)
void swap(ChainedList * x, ChainedList *y){
	//printf("old next %p, old root %p\n", x, y);
	ChainedList * tmp = malloc(sizeof(ChainedList));
	tmp->node = malloc(sizeof(BinaryTree));
	tmp->node->count = x->node->count;//TODO do that better
	tmp->node->chara = x->node->chara;
	x->node->count = y->node->count;
	x->node->chara = y->node->chara;
	y->node->count=tmp->node->count;
	y->node->chara=tmp->node->chara;
	free(tmp->node);
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
			else if(i->next->node && i->node->count == i->next->node->count){
				if(i->node->chara > i->next->node->chara){
					swap(i, i->next);
					shouldContinue = true;
				}
			}
			i = i->next;
		}
		j = i;
	}
}
