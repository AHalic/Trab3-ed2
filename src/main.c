#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "utils.h"

#define HASH_SZ 127 // TO DO: pesquisar como escolher um tamanho de HASH

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 1;

    FILE* indexFile,* graphFile,* stopWordsFile;
    indexFile = openFile(argv[1], "index.txt");
    graphFile = openFile(argv[1], "graph.txt");

    Hash* hashFiles = initHash(HASH_SZ);
    Node* nodeList;

    // readIndex(indexFile, hashFiles);

    char* lineBuffer = NULL;
    size_t n;

    while(!feof(indexFile)) {
        getline(&lineBuffer, &n, indexFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        access(hashFiles, lineBuffer);
    }

//    showHash(hashFiles);



    // stopWordsFile = openFile(argv[1], "stopwords.txt");
    return 0;
}
