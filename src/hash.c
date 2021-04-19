#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "word.h"

#define HASH_SZ 127 // TO DO: pesquisar como escolher um tamanho de HASH

struct hash {
    Word** array;
    int sz;
};

Hash* initHash (void) {
    Hash* h = (Hash*) malloc (sizeof(Hash));
    h->sz = HASH_SZ;

    h->array = (Word**) malloc (sizeof(Word*) * HASH_SZ);

    for (int i = 0; i < HASH_SZ; i++) {
        h->array[i] = NULL;
    }

    return h;
}

// Hash function
static int hash (char* s, int sz) {
    int total = 0;
    for(int i  = 0; s[i] != '\0'; i++) {
        total += s[i];
    }

    return (total % sz);
}

Word* acess (Hash* h, char* string) {
    Word* aux_w;

    int index = hash(string, h->sz);

    aux_w = searchWord(h->array[index], string);

    if (aux_w)
        return aux_w;

    // se nao encontrou, se p == NULL

    aux_w = initWord(string);
    h->array[index] = insertWord(h->array[index], aux_w);

    return aux_w;
}

void showHash (Hash* h) {
    for (int i = 0; i < h->sz; i++) {
        printf("Posição array[%d]:\n", i);
        showWordList(h->array[i]);
    }
}

void destroyHash (Hash* h) {
    for (int i = 0; i < h->sz; i++) {
        destroyWordList(h->array[i]);
    }

    free(h->array);
    free(h);
}
