#include <stdio.h>
#include "triAlphabet.h"

int main(){
	ChainedList BigTree = loadFile("test/text.txt");
	char a = 100;
	char b = 42;
	//ChainedList BigTreeLeaf = {1,a,NULL};
	//ChainedList BigTreeRoot = {3,b,&BigTreeLeaf};
	//ChainedList BigTree = {0,0, &BigTreeRoot};

	bubbleSort(&BigTree);
	printf("MAIN : printing chainlist\n");
	printChainedList(&BigTree);

	//printf("%p\n", &BigTree);
	//printf("%p\n", BigTree.next);
	//swap(&BigTree, BigTree.next);
	//printChainedList(&BigTree);
	//printf("%p\n", &BigTree);
	//printf("%p\n", BigTree.next);
	return 0;
}
