#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
#include "word.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc != 2)
        return 1;

    FILE* indexFile,* graphFile,* stopWordsFile;
    indexFile = openFile(argv[1], "index.txt");
    graphFile = openFile(argv[1], "graph.txt");
    stopWordsFile = openFile(argv[1], "stopwords.txt");

    Hash* hashFiles = initHash();

    readIndex(indexFile, hashFiles);
    showHash(hashFiles);    

    return 0;
}