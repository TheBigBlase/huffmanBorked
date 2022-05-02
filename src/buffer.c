#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>//for debug

short size = 0;

void freeLast(Buffer* b){
	if(b == NULL) return;
	while(b->next !=NULL && b->next->next != NULL){
		b = b->next;
	}
	free(b->next);
	b->next = NULL;
}

void printBuf(Buffer * b){
	if(b == NULL) return (void)printf("\n");
	printf("char %c \n", b->c);
	printBuf(b->next);
}

char * invertStringRemoveLast(char* str){
	if(str == NULL) return NULL;//i believe NULL is also \0

	char * reversedPath = malloc(strlen(str));//do not take nullbyte+first char
																						//but end it with NULL

	for(short k = 1 ; k < strlen(str) ; k++){//do not take last
		reversedPath[k] = str[strlen(str) - k];
	}
	reversedPath[0] = '\0';//reverse begins with null

	return reversedPath;
}

char * invertString(char* str, short len){
	if(str == NULL) return NULL;//i believe NULL is also \0

	char * reversedPath = malloc(len);//do not take nullbyte+first char
																		//but end it with NULL

	for(short k = 0 ; k <= len ; k++){//do not take last
		reversedPath[k] = str[len - k];
	}

	return reversedPath;
}

Buffer* writeToBuff(Buffer * buf, char * path){
	//we need to reverse the string : 
	//so we can grab the last char, write it to buf, rm it, and pass the inverted one
	//that way we removed the first char of a string

	Buffer * bufStart = buf;

	if(buf != NULL){
		while(buf->next != NULL){
			buf = buf->next;
		}
		buf->next = malloc(sizeof(Buffer));
		buf->next->next = NULL;
		buf = buf->next;
	}

	else{
		buf = malloc(sizeof(Buffer));
		buf->next = NULL;
	}

	while(path != NULL && strcmp(path, "") != 0){//i believe NULL is also \0
	
		if(bufStart == NULL){
			bufStart = buf;
		}

		short sizeToAdd = strlen(path) - 1;//needed ?
		
		char * reversedPath = invertStringRemoveLast(path);
		buf->c = path[0];
		buf->next = malloc(sizeof(Buffer));
		buf->next->next = NULL;
		buf->next->c = '\0';//just to make sure, but should be useless
		
		path = invertString(reversedPath, sizeToAdd);

		//free(reversedPath); remove after debug
		
		buf = buf->next;
		//free(path);
		size++;
	}
	freeLast(bufStart);
	return bufStart;
}

Buffer * buffToFile(Buffer * buf){
	while(size >= 8){
		char * toWrite = malloc(8);//8 char, 1 byte
		for(short k = 0 ; k < 8 ; k++){
			toWrite[k] = buf->c;
			Buffer * next = buf->next;
			free(buf);
			buf = next;
		}
		size = size - 8;
		long res = strtol(toWrite,NULL,2);
		printf("%ld", res);
	}
	return buf;
}

void emptyBuffer(Buffer * buf){
	if(buf == NULL) return;
	buf = buffToFile(buf);
	char * toWrite = malloc(size);//7 max
	short k;
	for(k = 0 ; k < size ; k --){
		toWrite[k] = buf->c;
		Buffer * next = buf->next;
		free(buf);
		buf = next;
	}

	for( ; k < 8 ;k++){
		toWrite[k] = 0;
	}
	long res = strtol(toWrite,NULL,2);
	printf("%ld", res);

}
