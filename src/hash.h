#ifndef HASH_H
#define HASH_H
#include "node.h"

typedef struct hash Hash;

/*
 * Inicializa a tabela hash com o tamanho informado e todos elementos NULL
 * Input: void
 * Output: Hash*
 */ 
Hash* initHash (int sz);

/*
 * Atualiza a tabela Hash
 * Input: Hash*, char*
 * Output: Pages*
 */ 
Node* accessHash (Hash* h, char* string);

/*
 * Libera a memoria alocada pela tabela hash
 * Input: Hash*
 * Output: void
 */ 
void destroyHash (Hash* h);

#endif
