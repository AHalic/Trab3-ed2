#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "page.h"

typedef struct celula_str Cell;

struct celula_str {
    Pages* pages;
    Cell* next;
};

struct list {
    Cell* first;
    Cell* last;
};

List* initList() {
    List* list = (List*) malloc (sizeof(List));
    
    list->first = NULL;
    list->last = NULL;

    return list;
}

int isListEmpty (List* list) {
    return (list->first == NULL);
}

// TODO: inserir ordenado pelo page rank 
void insertPageToList (Pages* page, List* list) {
    Cell* novo = (Cell*) malloc (sizeof(Cell));

    if(list->last == NULL) {
        list->first = list->last = novo;
    }
    else {
        list->last->next = novo;
        list->last = list->last->next;
    }

    list->last->pages = page;
    list->last->next = NULL;
}

void removePage (List* list, int id) {
    Cell* ant = NULL;
    Cell* p = list->first;


    // Busca ate parar na celula desejada
    while (p != NULL && getIndex(p->pages) != id) {
        ant = p;
        p = p->next;
    } 


    // Lista vazia ou nao encontrou o pages
    if (p == NULL) { 
        return NULL;
    }

    // Caso em que o aluno seja o unico da list
    if (p == list->first && p == list->last) {
        list->first = list->last = NULL; 
    }


    // Caso em que o aluno eh o last da list
    else if (p == list->last) {
        list->last = ant; 
        ant->next = NULL; 
    }


    // Caso em que o aluno eh o first da list
    else if (p == list->first) 
        list->first = p->next;

    // Caso padrao (se encontra no meio)
    else
        ant->next = p->next;


    free(p);
}

void showList (List* list) {
    Cell* aux = list->first;

    while (aux != NULL) {
        // Imprimir 
        aux = aux->next;
    }
    
}

void destroyList(List* list) {
    Cell* pr = list->first;
    Cell* aux = NULL;

    while (pr != NULL) {
        aux = pr->next;
        free(pr);
        pr = aux;
    }

    free(list);
}