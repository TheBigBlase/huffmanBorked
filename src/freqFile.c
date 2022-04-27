#include "triAlphabet.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern short alphabetSize;

void writeFreqToFile(ChainedList * list, char * file){

	printf("\n");
	char* fileNoExt = malloc(sizeof(strlen(file) + 1));
	strcpy(fileNoExt, file);
	fileNoExt = strtok(fileNoExt, ".");

	char* fileWithExtension = malloc(strlen(fileNoExt) + 9);//9 new chars in name
	strcpy(fileWithExtension, file); /* copy name into the new var */
	strcat(fileWithExtension, "_freq.txt"); /* add the extension */


	freopen(fileWithExtension, "w+", stdout); //print to file instead
	printf("total : %d\n", alphabetSize);
	printChainedList(list);
	freopen("/dev/tty", "w", stdout); //resume stdout
}

