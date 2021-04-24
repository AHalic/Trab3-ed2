#include "word.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct word {
    char* string;
    int index;
    Word* next;
};

Word* initWord (char* str) {
    Word* w = (Word*) malloc (sizeof(Word));
    w->string = strdup(str);
    w->index = -1;
    w->next = NULL;
    return w;
}

char* getString (Word* w) {
    return w->string;
}

void setIndex (Word* w, int index) {
    w->index = index;
}

int getIndex (Word* w) {
    return w->index;
}

Word* searchWord (Word* w, char* string) {
    Word* aux;
    
    for (aux = w; aux != NULL; aux = aux->next) {
        if (strcmp (string, aux->string) == 0)
            return aux;
    }

    return NULL;
}

Word* insertWord (Word* lista, Word* p) {
    p->next = lista;
    return p;
}

int getQtyWords (Word* p) {
    Word* aux;
    int qty = 0;

    for (aux = p; aux != NULL; aux = aux->next) {
        qty++;
    }

    return qty;
}

void showWordList (Word* w) {
    Word* aux;

    for (aux = w; aux != NULL; aux = aux->next) {
        printf("String: %s - Times: %d \n", aux->string, aux->index);
    }
}

void destroyWordList (Word* w) {
    Word* aux1 = w;
    Word* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->next;
        free(aux1->string);
        free(aux1);
        aux1 = aux2;
    }
}