#include "triAlphabet.h"
#include <stdio.h>
#include <malloc.h>

void addEltToLeft(struct DataTree* ptr, int chara){
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

void printDataTree(struct DataTree* tree){
	if(tree == NULL) return;
	if(!(tree->nextL == NULL && tree->nextR == NULL)){
		printDataTree(tree->nextL);
		printf("%c", tree->chara);
		printDataTree(tree->nextR);
	}
}

struct DataTree loadFile(char* file){
	struct DataTree res = { chara:0, count:0, nextL:NULL, nextR:NULL };
	unsigned int counter = 0;
	FILE *tmp =fopen(file, "r");
	int c;
	while(1) {
		c = fgetc(tmp);
		//printf("%c", c);//inc c
		addEltToLeft(&res, c);
		if(feof(tmp)){break;} //ugly but has to check after 
		counter++;
	}

	//printf("\n");
	fclose(tmp);
	printDataTree(&res);
	return res;
}
