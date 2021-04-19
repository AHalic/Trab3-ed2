#ifndef HASH_H
#define HASH_H
#include "palavra.h"

typedef struct hash Hash;

/*
 * Inicializa a tabela hash com o tamanho informado e todos elementos NULL
 * Input: int
 * Output: Hash*
 */ 
Hash* inicHash (int tamanho);

/*
 * Atualiza a tabela Hash
 * Input: Hash*, char*
 * Output: Palavra*
 */ 
Palavra* acessa (Hash* h, char* string);

/*
 * Imprime a tabela Hash
 * Input: Hash*
 * Output: void
 */ 
void imprimeHash (Hash* h);

/*
 * Libera a memoria alocada pela tabela hash
 * Input: Hash*
 * Output: void
 */ 
void liberaHash (Hash* h);

#endif