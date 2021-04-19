#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "palavra.h"

struct hash {
    Palavra** vet;
    int tam;
};

Hash* inicHash (int tamanho) {
    Hash* h = (Hash*) malloc (sizeof(Hash));
    h->tam = tamanho;

    h->vet = (Palavra**) malloc (sizeof(Palavra*) * tamanho);

    for (int i = 0; i < tamanho; i++) {
        h->vet[i] = NULL;
    }

    return h;
}

// Funcao de Hash
static int hash (char* s, int tam) {
    int total = 0;
    for(int i  = 0; s[i] != '\0'; i++) {
        total += s[i];
    }

    return (total % tam);
}

Palavra* acessa (Hash* h, char* string) {
    Palavra* p;

    int indice = hash(string, h->tam);

    p = buscaPalavra(h->vet[indice], string);

    // atualizo a ocorrencia
    // A palavra ja esta la
    if (p)
        return p;

    // se nao encontrou, se p == NULL

    p = inicPalavra(string);
    h->vet[indice] = inserePalavraLista(h->vet[indice], p);

    return p;
}

void imprimeHash (Hash* h) {
    for (int i = 0; i < h->tam; i++) {
        printf("Posição vet[%d]:\n", i);
        imprimeLista(h->vet[i]);
    }
}

void liberaHash (Hash* h) {
    for (int i = 0; i < h->tam; i++) {
        liberaListaPalavra(h->vet[i]);
    }

    free(h->vet);
    free(h);
}
