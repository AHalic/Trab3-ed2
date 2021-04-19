#ifndef WORD_H
#define WORD_H

typedef struct word Word;

/*
 * Inicializa a word
 * Input: char*
 * Output: Word*
 */ 
Word* inicPalavra (char* str);

/* 
 * Retorna a string da word
 * Input: Word*
 * Output: char*
 */ 
char* retornaString (Word* pal);

/* 
 * Atualiza n da struct word. Referente a ocorrencias daquela word
 * Input: Word*
 * Output: void
 */ 
void atualizaOcorrencias (Word* pal);

/* 
 * Retorna o numero de ocorrencias daquela word
 * Input: Word*
 * Output: int
 */ 
int retornaOcorrencias (Word* pal);

/*
 * Verifica se a word existe dentro da lista de palavras
 * Input: Word*, char*
 * Output: Word*
 */ 
Word* buscaPalavra (Word* pal, char* string);

/*
 * Insere word *lista* a word *p* 
 * Input: Word*, Word*
 * Output: Word*
 */ 
Word* inserePalavraLista (Word* lista, Word* p);

/*
 * Conta a quantidade de palavras na lista
 * Input: Word*
 * Output: int
 */ 
int contaPalavrasLista (Word* p);

/*
 * Imprime lista de palavras
 * Input: Word*
 * Output: void
 */ 
void imprimeLista (Word* pal);

/*
 * Libera memoria alocada pela lista de palavras
 * Input: Word*
 * Output: void
 */ 
void liberaListaPalavra (Word* pal);

#endif