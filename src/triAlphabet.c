#include "triAlphabet.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// "private" funcs 
void huffmanAux(BinaryTree* tree, ResList* list);
void getHuffmanRes(BinaryTree*);
void printRes(ResList*);
void addToRes(ResList * res, char chara);

short alphabetSize = 0;
short resSize = 0;

void addEltToLeft(BinaryTree* ptr, int chara){//useless ?
	if(ptr->nextL == NULL){
		ptr->nextL = (BinaryTree*)malloc(sizeof(BinaryTree));
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
		list->node = (BinaryTree*)malloc(sizeof(BinaryTree));
		list->node->chara = c;
		list->node->count = 1;
		alphabetSize++;
	}
	else{
		addToChainedList_char(list->next, c);
	}
}

void addToChainedList_tree(ChainedList* list, BinaryTree * tree){
	//if(list->node && list->node->chara == tree->chara){//doesnt work : counter ++ big nono
	//	list->node->count++;
	//	return;
	//}

	if(list->node == NULL){
		list->node = tree;
		//printf("fuck\n");

	}
	else if(list->next == NULL){
		list->next = (ChainedList*)malloc(sizeof(ChainedList));
		list->next->node = (BinaryTree*)malloc(sizeof(BinaryTree));
		list->next->node = tree;
		alphabetSize++;
	}
	else if(list->node->count <= tree->count){
		ChainedList * listTmp = malloc(sizeof(ChainedList));
		listTmp->next = list->next;
		listTmp->node = tree;
		list->next = listTmp;
	}
	else{
		addToChainedList_tree(list->next, tree);
	}
}

ChainedList loadFile(char* file){
	BinaryTree * node = malloc(sizeof(BinaryTree));
	ChainedList res = { node,NULL};
	unsigned int counter = 0;
	FILE *tmp =fopen(file, "r");
	int c;
	while(1) {
		c = fgetc(tmp);
		if(c != '\n'){
			if(feof(tmp)){break;} //ugly but has to check after 
			addToChainedList_char(&res, c);//Do we count EOL / EOF ?
			counter++;
		}
	}

	fclose(tmp);
	bubbleSort(&res);
	return res;
}

void insertNode(BinaryTree * tree, char c, int count){//TODO
	
}

void printBinaryTree(BinaryTree* tree){
	if(tree->chara > 1)//if leaf
		printf("chara : %c, count %d\n", tree->chara, tree->count);
	else 
		printf("X : %d\n", tree->count);

	if(tree->nextL){
		printf("[TREE LEFT] ");
		printBinaryTree(tree->nextL);
	}

	else printf("[EMTPY LEFT]");
	if(tree->nextR){
		printf("[TREE RIGHT] ");
		printBinaryTree(tree->nextR);
	}
	else printf("[EMTPY LEFT]");
}

void printChainedList(ChainedList* l){
	if(l == NULL || l->node == NULL) return;
	if(l->node->chara != 0)
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
			i = i->next;
		}
		j = i;
	}
}

void addToTree(BinaryTree * tree, ChainedList * list){//lmao useless
	
}

BinaryTree * removeFromList(ChainedList * list){//not working
	BinaryTree * res = list->node;//nice commets bro 
	list = list->next; // thanks bro 
	free(list); // dw bro it compiles now 
	return res; // such genius much wow bro
}

void insertAfter(ChainedList * list, BinaryTree * node){
	ChainedList * new = malloc(sizeof(ChainedList));
	new->next = list->next;
	list->next = new;
	new->node = node;
}

void huffman(ChainedList* list){

	while(list->next != NULL){
		//printChainedList(list);
		BinaryTree * head1 = getHead(list);//get 2 first elt
		BinaryTree * head2 = getHead(list);
		//printf("---------------\n");
		//printBinaryTree(head1);
		//printBinaryTree(head2);
		BinaryTree * tree = createTreeNode(head1, head2); //make tree
		
		addToChainedList_tree(list, tree);//add tree to chain and sort
	}
	ResList * resList = malloc(sizeof(ResList));
	resList->next = NULL;

	//printf("---------------\n");
	//printBinaryTree(list->node);
	//printBinaryTree(tree);

	while(!(list->node->nextL == NULL && list->node->nextR == NULL)){
		resList = realloc(resList, 1);

			ResList* tmp = realloc(resList, resSize * sizeof(*resList));
			huffmanAux(list->node, resList);
			if (tmp){
				resList = tmp;
				resList[resSize] = *resList;
			}
		//printBinaryTree(list->node);
		//printRes(res);
		//printf("------------------------\n");
		printf("------------------------\n");

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
		printf("%p\n", tree->nextL);
		list = malloc(sizeof(ResList));
		list->l = 0;
		list->next = NULL;

		if(tree->nextL->nextL == NULL && tree->nextL->nextR == NULL && tree->nextL->chara > 0){//if leaf
			printf("[HUFFMAN] L leaf : %c\n", tree->nextL->chara);
			tree->nextL = NULL;
			//huffmanAux(tmp, list->next);
		}

		else 
			huffmanAux(tree->nextL, list->next);//should return from aux, not that bs
	}

	else if(tree->nextR != NULL){
		list = malloc(sizeof(ResList));
		list->next = NULL;
		list->l = 1;
		//list->next->next = NULL;

		if(tree->nextR->nextL == NULL && tree->nextR->nextR == NULL && tree->nextR->chara > 0){//if leaf
			printf("[HUFFMAN] R leaf : %c\n", tree->nextR->chara);
			tree->nextR = NULL;
			//huffmanAux(tmp, list->next);
		}

		else 
			huffmanAux(tree->nextR, list->next);
	}

	else{//if left and right are null
		//printf("Chara : %c\n", tree->chara); ?
		free(tree);
	}
}

BinaryTree* getHead(ChainedList * list){
	BinaryTree * tmp = list->node;
	*list = *list->next;
	return tmp;
}

void printRes(ResList * res){
	printf("%d", res->l);
	if(res->next != NULL)
		printRes(res->next);
}


void addToRes(ResList * list, char c){//not doing the right thing oopsie
	//read branch from root to leaf, and add chara at end
}

BinaryTree* createTreeNode(BinaryTree* l, BinaryTree * r){
	BinaryTree * res = malloc(sizeof(BinaryTree));
	//printf("chara l : %c chara r : %c\n", l->chara, r->chara);
	res->nextL = l;
	res->nextR = r;
	res->count = l->count + r->count;
	res->chara = 0;
	return res;//Drake this seems to work
}
