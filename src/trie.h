#ifndef TRIE_H
#define TRIE_H

#include "node.h"

typedef struct trie Trie;

Trie* initTrieNode();

void insert(Trie* *head, char* str, Node *nodeFile, int isStop);

int search(Trie *head, const char *str);

int haveChildren(Trie* curr);

void free_all(Trie* curs);

#endif
