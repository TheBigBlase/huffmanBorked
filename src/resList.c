#include "triAlphabet.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void addToResList(ResList* list, char* path, char c){

	if(strcmp(list->path, "") == 0){//if starting node
		list->chara = c;
		list->path = malloc(strlen(path) + 1);
		strcpy(list->path, path);
		list->next = NULL;
	}

	else{
		ResList * new = malloc(sizeof(ResList));
		new->chara = c;

		new->path = malloc(strlen(path) + 1);
		strcpy(new->path, path);

		new->next = list->next;
		list->next = new;
	}
}

void printResList(ResList * l){
	if(l == NULL)return;
	
	printf("path : %s, chara : %c\n", l->path, l->chara);
	printResList(l->next);

}

char* getPathFromChara(ResList * res, char c){
	while(res->chara != c){
		res = res->next;
	}

	return res->path;
};
