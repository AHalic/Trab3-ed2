#ifndef PAGE_H
#define PAGE_H

#include "node.h"


typedef struct page Pages;

/*
 * Inicializa a word
 * Input: char*
 * Output: Pages*
 */ 
Pages* initPage (Node *nodeFile);

/**
 * Faz uma cópia de nodeList e retorna
 * Input: Pages*
 * Output: Pages*
*/
Pages* getPagesCopy(Pages* nodeList);

/**
 * Filtra a lista de páginas baseList usando uma outra lista de páginas filterList (faz a interseção das duas listas)
 * Input: Pages*, Pages*
 * Output: Pages*
*/
Pages* filterPageList(Pages* baseList, Pages* filterList);


/**
 * Retorna o node da pagina
 * Input: Pages* 
 * Output: Node*
*/
Node* getPageNode (Pages* page);


/* 
 * Retorna a string da word
 * Input: Pages*
 * Output: char*
 */ 
char* getPageName (Pages* page);

/* 
 * Retorna o numero de ocorrencias daquela word
 * Input: Pages*
 * Output: int
 */ 
int getIndex (Pages* pal);

double getPR (Pages* page);

Pages* getNext(Pages* page);

/*
 * Verifica se a word existe dentro da lista de palavras
 * Input: Pages*, char*
 * Output: Pages*
 */ 
Pages* searchPage (Pages* pal, Node *nodeFile);

/*
 * Insere word *lista* a word *p* 
 * Input: Pages*, Pages*
 * Output: Pages*
 */ 
Pages* insertPage (Pages* lista, Pages* p);

/*
 * Conta a quantidade de palavras na lista
 * Input: Pages*
 * Output: int
 */ 
int getQtyPages (Pages* p);

/*
 * Imprime lista de palavras
 * Input: Pages*
 * Output: void
 */ 
void showPageList (Pages* pal);

/*
 * Libera memoria alocada pela lista de palavras
 * Input: Pages*
 * Output: void
 */ 
void destroyPageList (Pages* pal);

#endif
