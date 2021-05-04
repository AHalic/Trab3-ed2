#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "hash.h"
#include "graph.h"
#include "trie.h"

char* stringConcat(char* dir, char* file);

void toLowerString(char *string);

char* trimWhitespace(char *str);

FILE* openFile(char* dir, char* file);

int readIndex(char* arq, Hash* hashFiles);

void readGraph(char* file, Hash* hashFiles, Graph* graph);

void readStopWords (char* dir, Trie* trie);

void readPages(char* dir, Graph* graph, Trie* trie);

#endif