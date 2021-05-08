#ifndef HASH_H
#define HASH_H
#include "node.h"

typedef struct hash Hash;

/**
 * Inicializa a tabela hash com o tamanho informado e todos elementos NULL
 * @param {int}sz tamanho do vetor da hash
 * 
 * @return retorna hash inicializada
 */ 
Hash* initHash (int sz);

/**
 * Atualiza a tabela Hash
 * @param {Hash*}h hash inicializada
 * @param {char*}string string da palavra para acessar 
 * 
 * @return Node em que ha a string
 */ 
Node* accessHash (Hash* h, char* string);

/**
 * Libera a memoria alocada pela tabela hash
 * @param {Hash*}h hash inicializada
 */ 
void destroyHash (Hash* h);

#endif
