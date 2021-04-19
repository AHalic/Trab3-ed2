#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "word.h"

struct word {
    char* string;
    int n;
    Word* prox;
};

Word* inicPalavra (char* str) {
    Word* pal = (Word*) malloc (sizeof(Word));
    pal->string = strdup(str);
    pal->n = 0;
    pal->prox = NULL;
    return pal;
}

char* retornaString (Word* pal) {
    return pal->string;
}

void atualizaOcorrencias (Word* pal) {
    pal->n++;
}

int retornaOcorrencias (Word* pal) {
    return pal->n;
}

Word* buscaPalavra (Word* pal, char* string) {
    Word* aux;
    
    for (aux = pal; aux != NULL; aux = aux->prox) {
        if (strcmp (string, aux->string) == 0)
            return aux;
    }

    return NULL;
}

Word* inserePalavraLista (Word* lista, Word* p) {
    p->prox = lista;
    return p;
}

int contaPalavrasLista (Word* p) {
    Word* aux;
    int qtd = 0;

    for (aux = p; aux != NULL; aux = aux->prox) {
        qtd++;
    }

    return qtd;
}

void imprimeLista (Word* pal) {
    Word* aux;

    for (aux = pal; aux != NULL; aux = aux->prox) {
        printf("String: %s - Ocorrencia: %d \n", aux->string, aux->n);
    }
}

void liberaListaPalavra (Word* pal) {
    Word* aux1 = pal;
    Word* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1->string);
        free(aux1);
        aux1 = aux2;
    }
}