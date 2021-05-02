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

char* getPageName (Pages* page) {
    return getFileName(page->nodeFile);
}

int getIndex (Pages* w) {
    return getNodeId(w->nodeFile);
}

Pages* searchWord (Pages* pal, Node *nodeFile) {
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

int getQtyWords (Pages* p) {
    Pages* aux;
    int qty = 0;

    for (aux = p; aux != NULL; aux = aux->next) {
        qty++;
    }

    return qty;
}

void showWordList (Pages* w) {
//    Pages* aux;
//
//    for (aux = w; aux != NULL; aux = aux->next) {
//        printf("String: %s - Times: %d \n", aux->string, aux->index);
//    }
}

void destroyWordList (Pages* w) {
    Pages* aux1 = w;
    Pages* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->next;
        destroyNode(aux1->nodeFile);
        free(aux1);
        aux1 = aux2;
    }
}

