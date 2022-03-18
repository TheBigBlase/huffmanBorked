#ifndef SORT_ALPHABET
#define SORT_ALPHABET

typedef struct DataTree{
	char chara;
	int count;
	struct DataTree * nextL, * nextR;
}DataTree;


void addEltToTree(struct DataTree *, int chara);
void printDataTree(struct DataTree*);

void sortData(struct DataTree*);

typedef struct ChainedList{//TODO replace data by tree
	int count;
	char chara;
	struct ChainedList* next;
} ChainedList;

void bubbleSort(ChainedList *);

ChainedList loadFile(char* file);
void printChainedList(ChainedList*);

//void swap(ChainedList * x, ChainedList *y);

#endif
