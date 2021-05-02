#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "utils.h"
#include "graph.h"
#include "trie.h"
#define HASH_SZ 127 // TO DO: pesquisar como escolher um tamanho de HASH

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 1;

    FILE* indexFile,* graphFile,* stopWordsFile;
    indexFile = openFile(argv[1], "index.txt");
    graphFile = openFile(argv[1], "graph.txt");

    Hash* hashFiles = initHash(HASH_SZ);

    // readIndex(indexFile, hashFiles);

    char* lineBuffer = NULL;
    size_t n;
    int count_files = 0;

    // Lendo index.txt e preenchendo a hash
    while(!feof(indexFile)) {
        getline(&lineBuffer, &n, indexFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        access(hashFiles, lineBuffer);
        count_files++;
    }
    fclose(indexFile);

    free(lineBuffer);
    lineBuffer = NULL;

    Node** filesVector = initNodeVector(count_files); 

    for (int i = 0; i < count_files; ++i) {
        getline(&lineBuffer, &n, graphFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        char delim[2] = " ";
        char* token = strtok(lineBuffer, delim);
        Node* nodeFile = access(hashFiles, token);
        filesVector[i] = nodeFile;

        token = strtok(NULL, delim);
        int nInfluenced = atoi(token);
        setNodeInfluenced(nodeFile, nInfluenced);

        // Lê os nós que influenciam a página
        for (int j = 0; j < nInfluenced && token != NULL; j++){
            token = strtok(NULL, delim);
            Node* influencer = access(hashFiles, token);
            addConnection(influencer, nodeFile);
        }
    }
    free(lineBuffer);
    destroyHash(hashFiles);
    
    Graph* graph = initGraph(filesVector, count_files);
    
    updatePageRank(graph);
    showAllPR(graph);

    destroyGraph(graph);
    fclose(graphFile);

    Trie *arvore = getNewTrieNode();

    for (int i = 0; i < )

    // stopWordsFile = openFile(argv[1], "stopwords.txt");
    return 0;
}
