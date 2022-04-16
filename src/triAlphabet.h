#ifndef SORT_ALPHABET
#define SORT_ALPHABET
#include <stdbool.h>


/////// HUFFMAN'S TREE ////////
typedef struct BinaryTree{
	char chara;
	int count;
	struct BinaryTree * nextL, * nextR;
}BinaryTree;

/////// CHAINED LIST ////////

typedef struct ChainedList{//TODO replace data by tree
	BinaryTree* node;
	struct ChainedList* next;
} ChainedList;


typedef struct ResList{//TODO replace data by tree
	bool l;
	struct ResList* next;
} ResList;
void printRes(ResList*);

extern short alphabetSize;

////// OPS ON CHAINED LIST //////
void addToChainedList_char(ChainedList *, char);
void addToChainedList_tree(ChainedList *,  BinaryTree *);
BinaryTree * removeFromList(ChainedList * list);

ChainedList loadFile(char* file);
void bubbleSort(ChainedList *);

BinaryTree* getHead(ChainedList*);

///// PRINT /////
void printBinaryTree(BinaryTree*);
void printChainedList(ChainedList*);

///// OPS ON BINARY TREE /////
void huffman(ChainedList*);
BinaryTree * createTreeNode(BinaryTree*, BinaryTree*);
#endif
