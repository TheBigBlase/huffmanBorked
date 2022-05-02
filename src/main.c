#include <stdio.h>
#include <malloc.h>
#include "huffman.h"

int main(int argc, char ** argv){
	printf("no");
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
	
	return 0;
}
