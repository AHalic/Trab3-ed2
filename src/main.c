#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "utils.h"
#include "graph.h"

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

    while(!feof(indexFile)) {
        getline(&lineBuffer, &n, indexFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        access(hashFiles, lineBuffer);
        count_files++;
    }

//    showHash(hashFiles);
    lineBuffer = NULL;

    for (int i = 0; i < count_files; ++i) {
        getdelim(&lineBuffer, &n, ' ', graphFile); // pega o nome do arquivo nó
        printf("%s", lineBuffer);
        Node* nodeFile = access(hashFiles, lineBuffer);

        getdelim(&lineBuffer, &n, ' ', graphFile); // pega a qtd de influencias
        printf("%s", lineBuffer);
        int numOfInfluenced = atoi(lineBuffer);
        setNodeInfluenced(nodeFile, numOfInfluenced);

        for (int j = 0; j < numOfInfluenced; ++j) {
            getdelim(&lineBuffer, &n, ' ', graphFile); // pega a qtd de influencias
            printf("%s", lineBuffer);
        }
    }

    // stopWordsFile = openFile(argv[1], "stopwords.txt");
    return 0;
}
