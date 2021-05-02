#ifndef PAGE_H
#define PAGE_H

typedef struct page Pages;

/*
 * Inicializa a word
 * Input: char*
 * Output: Pages*
 */ 
Pages* initWord (char* str);

/* 
 * Retorna a string da word
 * Input: Pages*
 * Output: char*
 */ 
char* getString (Pages* pal);

/* 
 * Atualiza n da struct word. Referente a ocorrencias daquela word
 * Input: Pages*
 * Output: void
 */ 
void setIndex (Pages* pal, int index);

/* 
 * Retorna o numero de ocorrencias daquela word
 * Input: Pages*
 * Output: int
 */ 
int getIndex (Pages* pal);

/*
 * Verifica se a word existe dentro da lista de palavras
 * Input: Pages*, char*
 * Output: Pages*
 */ 
Pages* searchWord (Pages* pal, char* string);

/*
 * Insere word *lista* a word *p* 
 * Input: Pages*, Pages*
 * Output: Pages*
 */ 
Pages* insertWord (Pages* lista, Pages* p);

/*
 * Conta a quantidade de palavras na lista
 * Input: Pages*
 * Output: int
 */ 
int getQtyWords (Pages* p);

/*
 * Imprime lista de palavras
 * Input: Pages*
 * Output: void
 */ 
void showWordList (Pages* pal);

/*
 * Libera memoria alocada pela lista de palavras
 * Input: Pages*
 * Output: void
 */ 
void destroyWordList (Pages* pal);

#endif