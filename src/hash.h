#ifndef HASH_H
#define HASH_H
#include "word.h"

typedef struct hash Hash;

/*
 * Inicializa a tabela hash com o tamanho informado e todos elementos NULL
 * Input: void
 * Output: Hash*
 */ 
Hash* initHash (void);

/*
 * Atualiza a tabela Hash
 * Input: Hash*, char*
 * Output: Word*
 */ 
Word* acess (Hash* h, char* string);

/*
 * Imprime a tabela Hash
 * Input: Hash*
 * Output: void
 */ 
void showHash (Hash* h);

/*
 * Libera a memoria alocada pela tabela hash
 * Input: Hash*
 * Output: void
 */ 
void destroyHash (Hash* h);

#endif