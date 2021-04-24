#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
#include "word.h"

char* stringConcat(char* dir, char* file) {
    int dirLen = strlen(dir);
    
    char* fileName = file;
    int fileSz = strlen(fileName);

    char* filePath = (char*) malloc (sizeof(char) * (dirLen + fileSz + 1));  
    
    strcpy(filePath, dir);
    strcat(filePath, fileName);

    return filePath;
}

void toLowerString(char *string){
    for (int i = 0; i < strlen(string); i++){
        string[i] = tolower(string[i]);
    }
}

FILE* openFile(char* dir, char* file){
    FILE* fp;
    char* filePath;

    filePath = stringConcat(dir, file);
    fp = fopen(filePath, "r");

    return fp;
}

Hash* readIndex(FILE* fp, Hash* hashTable) {
    char* lineBuffer = NULL;
    size_t n;
    int i = 0;

    while(!feof(fp)) {
        getline(&lineBuffer, &n, fp);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        Word* auxWord = acess(hashTable, lineBuffer);
        setIndex(auxWord, i++);
        // showWordList(auxWord);
    }

    return hashTable;
}