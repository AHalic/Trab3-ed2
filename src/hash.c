#include "hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

// Hash function
static int hashCode (char* s, int sz) {
    int total = 0;
    for(int i  = 0; s[i] != '\0'; i++) {
        total += s[i];
    }

    return (total % sz);
}

Node* access (Hash* h, char* string) {
    Node* aux_list, *aux_node;
    int flag = 0;
    char *aux_string = strdup(string);

    int index = hashCode(aux_string, h->sz);
//    printf("index: %d\n", index);

    aux_list = searchNode(h->array[index], aux_string, &flag);
    if (flag)
        return aux_list;

    // se nao encontrou, se p == NULL

    aux_node = initNode(index, aux_string);
//    printf("node: %s i: %d\n", getFileName(aux_node), getNodeId(aux_node));

    if (h->array[index] == NULL) {
        h->array[index] = aux_node;
    } else  {
        insertNextNode(aux_list, aux_node);
    }

    return aux_node; // TODO: rever se precisa retornar algo
}

Node* find(Hash* h, char* string) {
    int index = hashCode(string, h->sz);
    Node* aux_n = searchNode(h->array[index], string, NULL);
    return aux_n;
}

void showHash (Hash* h) {
    for (int i = 0; i < h->sz; i++) {
        printf("index array[%d]:\n", i);
        if (h->array[i] != NULL) {
            printf("Node: %s Index: %d\n", getFileName(h->array[i]), getNodeId(h->array[i]));
        }
    }
}

void destroyHash (Hash* h) {
    destroyNodeVector(h->array, h->sz);
    free(h);
}
