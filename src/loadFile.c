#include <stdlib.h>
#include "triAlphabet.h"
#include <stdio.h>

short alphabetSize = 0;
ChainedList loadFile(char* file){
	ChainedList res = {NULL, NULL};

	FILE *tmp = fopen(file, "r");

	if(!tmp){
		printf("No such file\n");
		exit(-1);
	}

	int c;
	while(1) {
		c = fgetc(tmp);
		if(feof(tmp)){break;} //ugly but has to check after 
		addToChainedList_char(&res, c);//Do we count EOL / EOF ?
	}
	fclose(tmp);

	bubbleSort(&res);
	writeFreqToFile(&res, file);

	return res;
}

