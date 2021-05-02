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

    free(filePath);

    return fp;
}

Hash* readIndex(char* arq, Hash* hashTable) {
    indexFile = openFile(argv[1], "index.txt");

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

    
}

char *trimwhitespace(char *str) {
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}