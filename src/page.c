#include "page.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct page {
    char* string;
    int index;
    Pages* next;
};

Pages* initWord (char* str) {
    Pages* w = (Pages*) malloc (sizeof(Pages));
    w->string = strdup(str);
    w->index = -1;
    w->next = NULL;
    return w;
}

char* getString (Pages* w) {
    return w->string;
}

void setIndex (Pages* w, int index) {
    w->index = index;
}

int getIndex (Pages* w) {
    return w->index;
}

Pages* searchWord (Pages* w, char* string) {
    Pages* aux;
    
    for (aux = w; aux != NULL; aux = aux->next) {
        if (strcmp (string, aux->string) == 0)
            return aux;
    }

    return NULL;
}

Pages* insertWord (Pages* lista, Pages* p) {
    p->next = lista;
    return p;
}

int getQtyWords (Pages* p) {
    Pages* aux;
    int qty = 0;

    for (aux = p; aux != NULL; aux = aux->next) {
        qty++;
    }

    return qty;
}

void showWordList (Pages* w) {
    Pages* aux;

    for (aux = w; aux != NULL; aux = aux->next) {
        printf("String: %s - Times: %d \n", aux->string, aux->index);
    }
}

void destroyWordList (Pages* w) {
    Pages* aux1 = w;
    Pages* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->next;
        free(aux1->string);
        free(aux1);
        aux1 = aux2;
    }
}

