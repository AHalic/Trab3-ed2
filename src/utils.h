#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "hash.h"

char* stringConcat(char* dir, char* file);

void toLowerString(char *string);

FILE* openFile(char* dir, char* file);

Hash* readIndex(FILE* fp, Hash* hashTable);

#endif