#ifndef SORT_ALPHABET
#define SORT_ALPHABET


/////// HUFFMAN'S TREE ////////
typedef struct DataTree{
	char chara;
	int count;
	struct DataTree * nextL, * nextR;
}DataTree;

/////// CHAINED LIST ////////

typedef struct ChainedList{//TODO replace data by tree
	DataTree* node;
	struct ChainedList* next;
} ChainedList;

////// OPS ON CHAINED LIST //////
void addToChainedList_char(ChainedList *, char);
void addToChainedList_tree(ChainedList *,  DataTree *);
void printDataTree(DataTree*);

ChainedList loadFile(char* file);
void printChainedList(ChainedList*);
void bubbleSort(ChainedList *);

#endif
