#include "triAlphabet.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void writeFreqToFile(ChainedList * list, char * file){
	printf("file : %s\n",file);
	file = strtok(file, ".");
	char* fileWithExtension = malloc(strlen(file) + 9);//9 new chars in name
	strcpy(fileWithExtension, file); /* copy name into the new var */
	strcat(fileWithExtension, "_freq.txt"); /* add the extension */
	FILE * freqFile = fopen(fileWithExtension, "w+");
	free(fileWithExtension);
	fflush(freqFile);
	//while(list->next != NULL){
	//	
	//}
}

