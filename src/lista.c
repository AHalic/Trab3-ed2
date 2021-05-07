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
        return;
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

void filterList(List* list, Pages* pages) {
    Pages* auxP = pages, *beforeP;
    Cell* beforeL;
    Cell* auxL = list->first;
    for(auxL = auxL; auxL != NULL && auxP != NULL; auxL = auxL->next) {
        printf("sou página %s ", getPageName(auxL->pages));
        if (getIndex(auxL->pages) == getIndex(auxP)) {
            printf(" entrei pq sao iguais\n");
            auxP = getNext(auxP);
        }
        else if (getPR(auxL->pages) >= getPR(auxP)) {
            int id = getIndex(auxL->pages);
            printf(" entrei pq tem q retirar o nó %d\n", id);
            auxL = beforeL;
            removePage(list, id);
        }
        else {
            while (getPR(auxL->pages) < getPR(auxP)) {
                auxP = getNext(auxP);
                if (getIndex(auxL->pages) == getIndex(auxP)) {
                    auxP = getNext(auxP);
                    break;
                }
                else if (getPR(auxL->pages) >= getPR(auxP)) {
                    int id = getIndex(auxL->pages);
                    auxL = beforeL;
                    removePage(list, id);
                }
            }
        }
        beforeL = auxL;
        beforeP = auxP;
    }

    if (auxP == NULL) {
        // beforeL = NULL;
        for (auxL = auxL; auxL != NULL; auxL = auxL->next) {
            int id = getIndex(auxL->pages);
            auxL = beforeL;
            removePage(list, id);              
        }
    }
    
    
}

void copyPagesList(Pages* pages, List* list) {
    if(pages != NULL) return;
    Pages* aux = pages;
    do
    {
        insertPageToList(aux, list);
        aux = getNext(aux);
    } while (aux != NULL);
    
}

void showList (List* list) {
    Cell* aux = list->first;
    if(aux == NULL){
        printf("lista nula\n");
    }
    while (aux != NULL) {
        printf("entrou no primeiro while\n");
        // Imprimir 
        printf("%s ", getPageName(aux->pages));
        aux = aux->next;
    }
    printf("\n");

    aux = list->first;

    while (aux != NULL) {
        printf("entrou no segundo while\n");
        // Imprimir 
        printf("%lf ", getPR(aux->pages));
        aux = aux->next;
    }
    printf("\n");
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

/*
a   b    c    d
4   3    2    1

e   a    b    f
5   4    3    1
*/