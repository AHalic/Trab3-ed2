#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "hash.h"

char* stringConcat(char* dir, char* file);

void toLowerString(char *string);

FILE* openFile(char* dir, char* file);

int readIndex(char* arq, Hash* hashFiles);

void readGraph(char* arq, Hash* hashFiles, int count_files, Node** filesVector);

char* trimwhitespace(char *str);

#endif