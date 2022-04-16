#include <stdio.h>
#include <malloc.h>
#include "triAlphabet.h"

int main(){
	ChainedList BigTree = loadFile("test/text.txt");
	//ChainedList BigTreeLeaf = {1,a,NULL};
	//ChainedList BigTreeRoot = {3,b,&BigTreeLeaf};
	//ChainedList BigTree = {0,0, &BigTreeRoot};

	//bubbleSort(&BigTree);
	//printf("MAIN : printing chainlist\n");
	//printChainedList(&BigTree);
	//printf("%d\n", alphabetSize);
	huffman(&BigTree);
	//ResList list = {'2',NULL};
	//ResList list2 = {'1',&list};
	//printRes(&list2);
	
	return 0;
}
