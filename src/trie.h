#ifndef TRIE_H
#define TRIE_H

typedef struct trie Trie;

void insert(Trie* *head, char* str, char* file, int isStop);

int search(Trie* head, char* str,  char** argv);

int haveChildren(Trie* curr);

void free_all(Trie* curs);

#endif
