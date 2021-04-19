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
    char* indexPath,* graphPath,* stopWordsPath;

    indexPath = stringConcat(argv[1], "index.txt");
    graphPath = stringConcat(argv[1], "graph.txt");
    stopWordsPath = stringConcat(argv[1], "stopwords.txt");

    indexFile = fopen(indexPath, "r");
    graphFile = fopen(graphPath, "r");
    stopWordsFile = fopen(stopWordsPath, "r");

    Hash* hashFiles = initHash();
    char* lineBuffer = NULL;
    size_t n;

    while(!feof(indexFile)) {
        getline(&lineBuffer, &n, indexFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        Word* auxWord = acess(hashFiles, lineBuffer);
        updateNAppearance(auxWord);
        showWordList(auxWord);
    }

    // showHash(hashFiles);    
    return 0;
}