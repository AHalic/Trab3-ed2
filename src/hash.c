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

// Hash function
static int hashCode (char* s, int sz) {
    int total = 0;
    for(int i  = 0; s[i] != '\0'; i++) {
        total = (s[i] * (total + 1)) % sz;
        // total += s[i];
    }

    return total;
}

Node* access (Hash* h, char* string) {
    Node* aux_list, *aux_node;
    int flag = 0;
    char *aux_string = strdup(string);

    int index = hashCode(aux_string, h->sz);

    aux_list = searchNode(h->array[index], aux_string, &flag);
    if (flag)
        return aux_list;

    // se nao encontrou, se flag == 0
    aux_node = initNode(index, aux_string);

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
        if (h->array[i] != NULL) {
            printNode(h->array[i]);
        }
    }
}

void destroyHash (Hash* h) {
    // destroyNodeVector(h->array, h->sz);
    free(h->array);
    free(h);
}


void updatePageRank(Hash* vetor){
    int tam = vetor->sz;
    while (1){
        double error = 0;
        for (int i = 0; i < tam; i++){
            Node* aux = vetor->array[i];
            calcPageRank(aux, tam);
        }
        for(int i = 0; i < tam; i++){
            Node*aux = vetor->array[i];
            double diff = changePRs(aux);
            error += diff*diff;
        }
        error = sqrt(error);
        if(error <= 0.000001){
            break;
        }
    } 
}