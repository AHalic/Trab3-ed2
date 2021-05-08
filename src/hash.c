#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct hash {
    Node** array;
    int sz;
};

Hash* initHash (int sz) {
    Hash* h = (Hash*) malloc (sizeof(Hash));
    h->sz = sz;

    h->array = initNodeVector(sz);

    for (int i = 0; i < sz; i++) {
        h->array[i] = NULL;
    }

    return h;
}

/**
 * Funcao de hash
 * @param {char*}s string 
 * @param {int}sz tamanho da hash
 */
static int hashCode (char* s, int sz) {
    int total = 0;
    for(int i  = 0; s[i] != '\0'; i++) {
        total = (251 * total + s[i]) % sz;
    }

    return total;
}

Node* accessHash (Hash* h, char* string) {
    Node* aux_list = NULL, *aux_node = NULL;
    int flag = 0;

    int index = hashCode(string, h->sz);

    if (h->array == NULL
        && index >= h->sz
        && h->array[index] == NULL
        && string == NULL
        && index <= 0) {
            printf("erro em %s\n", string);
            return NULL;
    }

    aux_list = searchNode(h->array[index], string, &flag);
    
    if (flag) {
        return aux_list;
    }

    char *aux_string = strdup(string);

    // se nao encontrou, se flag == 0
    aux_node = initNode(index, aux_string);

    if (h->array[index] == NULL) {
        h->array[index] = aux_node;
    } 
    else {
        insertNextNode(aux_list, aux_node);
    }

    return aux_node; 
}

void destroyHash (Hash* h) {
    free(h->array);
    free(h);
}


