#include"Palavra.h"
#define CHAR_SIZE 36

struct Trie{
	int isLeaf;
	Palavra* p;
	struct Trie* character[CHAR_SIZE];
};

struct Trie* getNewTrieNode();

void insert(struct Trie* *head, char* str, int j, int i);

int search(struct Trie* head, char* str, char** argv);

int haveChildren(struct Trie* curr);

int deletion(struct Trie* *curr, char* str);

void TRIE(int argc, char** argv, FILE **file);

void free_all(struct Trie* curs);