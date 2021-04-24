#ifndef WORD_H
#define WORD_H

typedef struct word Word;

/*
 * Inicializa a word
 * Input: char*
 * Output: Word*
 */ 
Word* initWord (char* str);

/* 
 * Retorna a string da word
 * Input: Word*
 * Output: char*
 */ 
char* getString (Word* pal);

/* 
 * Atualiza n da struct word. Referente a ocorrencias daquela word
 * Input: Word*
 * Output: void
 */ 
void setIndex (Word* pal, int index);

/* 
 * Retorna o numero de ocorrencias daquela word
 * Input: Word*
 * Output: int
 */ 
int getIndex (Word* pal);

/*
 * Verifica se a word existe dentro da lista de palavras
 * Input: Word*, char*
 * Output: Word*
 */ 
Word* searchWord (Word* pal, char* string);

/*
 * Insere word *lista* a word *p* 
 * Input: Word*, Word*
 * Output: Word*
 */ 
Word* insertWord (Word* lista, Word* p);

/*
 * Conta a quantidade de palavras na lista
 * Input: Word*
 * Output: int
 */ 
int getQtyWords (Word* p);

/*
 * Imprime lista de palavras
 * Input: Word*
 * Output: void
 */ 
void showWordList (Word* pal);

/*
 * Libera memoria alocada pela lista de palavras
 * Input: Word*
 * Output: void
 */ 
void destroyWordList (Word* pal);

#endif