#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hash.h"
#include "utils.h"
#include "graph.h"
#include "trie.h"

#define HASH_SZ 127 // TO DO: pesquisar como escolher um tamanho de HASH
#define true 1
#define false 0

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 1;

    Hash* hashFiles = initHash(HASH_SZ);

    int count_files = readIndex(argv[1], hashFiles);

    Node** filesVector = initNodeVector(count_files); 

    Graph* graph = initGraph(filesVector, count_files);
    readGraph(argv[1], hashFiles, count_files, filesVector);    

    updatePageRank(graph);
    showAllPR(graph);

    Trie *arvore = initTrieNode();

    FILE* stopWordsFile;
    stopWordsFile = openFile(argv[1], "stopwords.txt");
    char* lineBuffer = NULL;
    size_t n;

    while(!feof(stopWordsFile)) {
        getline(&lineBuffer, &n, stopWordsFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';
// insert(Trie** head, char* str, char* file, int isStop)
        printf("[INSERE] %s\n", lineBuffer);
        insert(&arvore , lineBuffer, NULL, true);
    }
    free(lineBuffer);

    while (!feof(stdin)) {
        getline(&lineBuffer, &n, stdin);

    }

    destroyGraph(graph);
    return 0;
}
