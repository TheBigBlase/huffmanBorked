#include <stdio.h>
#include <malloc.h>
#include "triAlphabet.h"

int main(int argc, char ** argv){
	ChainedList BigTree;
	char  file[] = "tests/test.txt";
	if(argv[1]){
		BigTree = loadFile(argv[1]);
		huffman(&BigTree, argv[1]);
	}
	else {
		BigTree = loadFile(file);
		huffman(&BigTree, file);
	}

	//ChainedList BigTreeLeaf = {1,a,NULL};
	//ChainedList BigTreeRoot = {3,b,&BigTreeLeaf};
	//ChainedList BigTree = {0,0, &BigTreeRoot};

	//bubbleSort(&BigTree);
	//printf("MAIN : printing chainlist\n");
	//printChainedList(&BigTree);
	//printf("%d\n", alphabetSize);
	//ResList list = {'2',NULL};
	//ResList list2 = {'1',&list};
	//printRes(&list2);
	
	return 0;
}
