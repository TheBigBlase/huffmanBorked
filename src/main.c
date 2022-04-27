#include <stdio.h>
#include <malloc.h>
#include "triAlphabet.h"

int main(int argc, char ** argv){
	ChainedList BigTree;
	char  file[] = "tests/test.txt";
	if(argv[1]){
		BigTree = loadFile(argv[1]);
	}
	else {
		BigTree = loadFile(file);
	}

	huffman(&BigTree, file);

	return 0;
}
