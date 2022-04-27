#include "triAlphabet.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern short alphabetSize;
void writeFreqToFile(ChainedList * list, char * file){

	char * fileNoExt = malloc(strlen(file) + 1);
	strcpy(fileNoExt, file);
	strtok(fileNoExt, ".");

	char* fileWithExtension = malloc(strlen(fileNoExt) + 9);//9 new chars in name
	strcpy(fileWithExtension, fileNoExt); /* copy name into the new var */
	strcat(fileWithExtension, "_freq.txt"); /* add the extension */

	//freopen(fileWithExtension, "w+", stdout); //pipe stdout to file
	printf("total :%d\n", alphabetSize);
	printChainedList(list);
	//freopen("/dev/tty", "w", stdout); //resume to stdout

	free(fileWithExtension);
	free(fileNoExt);
}
