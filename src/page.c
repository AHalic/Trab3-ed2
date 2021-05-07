#include "page.h"
#include "node.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct page {
    Node* nodeFile;
    Pages* next;
};

Pages* initPage (Node *nodeFile) {
    Pages* newPage = (Pages*) malloc (sizeof(Pages));
    newPage->nodeFile = nodeFile;
    newPage->next = NULL;
    return newPage;
}

Pages* filterPageList(Pages* baseList, Pages* filterList){
    Pages* base = baseList, *baseNext, *basePrev = NULL;
    Pages* filter;

    while (base != NULL){
        int match = 1;
        baseNext = base->next;
        filter = filterList;
        while (filter != NULL){
            if(getNodeId(filter->nodeFile) == getNodeId(base->nodeFile)){
                match = 0;
            }
            filter = filter->next;
        }
        if(match){
            if(basePrev == NULL){
                Pages* aux = base;
                base = baseNext;
                aux->next = NULL;
                baseList = base;
                free(aux);
                continue;
            }else if(baseNext == NULL){
                free(base);
                basePrev->next = NULL;
                break;
            }else{
                basePrev->next = baseNext;
                base->next = NULL;
                free(base);
                base = basePrev;
            }
        }
        basePrev = base;
        base = base->next;
    }
    
    return baseList;
}

Pages* getPagesCopy(Pages* nodeList){
    Pages* aux = nodeList, *newPagesList = NULL;
    while (aux != NULL){
        Pages* newPage = initPage(aux->nodeFile);
        if(newPage != NULL){
            newPagesList = insertPage(newPagesList, newPage);
        }
        aux = aux->next;
    }
    return newPagesList;
}

Node* getPageNode (Pages* page){
    return page->nodeFile;
}

char* getPageName (Pages* page) {
    return getFileName(page->nodeFile);
}

int getIndex (Pages* w) {
    return getNodeId(w->nodeFile);
}

double getPR (Pages* page) {
    return getPR_old(page->nodeFile);
}

Pages* getNext(Pages* page) {
    return page->next;
}

Pages* searchPage (Pages* pal, Node *nodeFile) {
    Pages* aux;
    
    for (aux = pal; aux != NULL; aux = aux->next) {
        if (strcmp (getFileName(nodeFile), getPageName(aux)) == 0)
            return aux;
    }

    return NULL;
}

Pages* insertPage (Pages* lista, Pages* p) {
    p->next = lista;
    return p;
}

int getQtyPages (Pages* p) {
    Pages* aux;
    int qty = 0;

    for (aux = p; aux != NULL; aux = aux->next) {
        qty++;
    }

    return qty;
}

void showPageList (Pages* w) {
    if(w == NULL){
        printf("página nula\n");
        return;
    }
    Pages* aux;

    for (aux = w; aux != NULL; aux = aux->next) {
        printf("%s ", getPageName(aux));
        if(aux->next == NULL){
            break;
        }
    }
    printf("\n");
    for (aux = w; aux != NULL; aux = aux->next) {
        printf("%lf ", getPR(aux));
        if(aux->next == NULL){
            break;
        }
    }
    printf("\n");
}

void destroyPageList (Pages* w) {
    Pages* aux1 = w;
    Pages* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->next;
        // destroyNode(aux1->nodeFile);
        free(aux1);
        aux1 = aux2;
    }
}

