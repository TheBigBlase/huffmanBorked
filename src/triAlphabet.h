#ifndef SORT_ALPHABET
#define SORT_ALPHABET

struct DataTree{
	char chara;
	int count;
	struct DataTree * nextL, * nextR;
};

struct DataTree loadFile(char* file);

void addEltToTree(struct DataTree *, int chara);
void printDataTree(struct DataTree*);



#endif
