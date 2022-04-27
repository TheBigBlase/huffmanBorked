#ifndef SORT_ALPHABET
#define SORT_ALPHABET
#include <stdbool.h>

//extern short alphabetSize;
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
	char * path;
	char chara;
	struct ResList* next;
} ResList;


////// OPS ON CHAINED LIST //////
void addToChainedList_char(ChainedList *, char);
void addToChainedList_tree(ChainedList *,  BinaryTree *);
BinaryTree * removeFromList(ChainedList * list);

ChainedList loadFile(char* file);

void bubbleSort(ChainedList *);
void writeFreqToFile(ChainedList*, char*);

BinaryTree* getHead(ChainedList**);

///// OPS ON RES LIST /////
void addToResList(ResList *,  char*, char);
void printResList(ResList *);
char* getPathFromChara(ResList *, char);

///// PRINT /////
void printBinaryTree(BinaryTree*);
void printChainedList(ChainedList*);

///// OPS ON BINARY TREE /////
void huffman(ChainedList*, char*);
BinaryTree * createTreeNode(BinaryTree*, BinaryTree*);
#endif
