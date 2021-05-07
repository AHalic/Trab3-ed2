#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include "page.h"
typedef struct trie Trie;

Trie* initTrieNode();

void insert(Trie* *head, char* str, Node *nodeFile, int isStop);

Pages* search(Trie *head, const char *str, int* flag);

void destroyTrie(Trie* curs);

#endif
