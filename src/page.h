#ifndef PAGE_H
#define PAGE_H

#include "node.h"


typedef struct page Pages;

/*
 * Inicializa a page
 * @param {Node*}nodeFile nó que será inserido na Page
 * @return página criada
**/ 
Pages* initPage (Node *nodeFile);

/**
 * Retorna uma cópia de nodeList
 * @param {Pages*}nodeList lista de páginas que será copiada
 * @return lista de páginas cópia de nodeList
**/
Pages* getPagesCopy(Pages* nodeList);

/**
 * Faz a interseção entre duas listas de páginas
 * @param {Pages*}baseList
 * @param {Pages*}filterList
 * @return retorna uma lista de páginas contendo as páginas 
 *         presentes nas duas listas de entrada
**/
Pages* filterPageList(Pages* baseList, Pages* filterList);

/* 
 * Retorna o nome do nó da página
 * @param {Pages*}page
 * @return string nome do arquivo
**/ 
char* getPageName (Pages* page);

/**
 * Retorna o page rank do nó da página
 * @param {Pages*}page
 * @return double page rank
**/
double getPR (Pages* page);

/*
 * Verifica se o nó existe dentro da lista de pages
 * @param {Pages*}pal lista de pages
 * @param {Node*}nodeFile nó a ser buscado
 * @return page contendo o nó buscado
 */ 
Pages* searchPage (Pages* pal, Node *nodeFile);

/*
 * Insere page a uma lista de pages
 * @param {Pages*}lista
 * @param {Pages*}p page que será inserida
 * @return nova lista contendo page
 */ 
Pages* insertPage (Pages* lista, Pages* p);

/*
 * Imprime lista de pages
 * @param {Pages*}pal lista de pages
 */ 
void showPageList (Pages* pal);

/*
 * Libera memoria alocada pela lista de pages
 * @param {Pages*}pal
 */ 
void destroyPageList (Pages* pal);

#endif
