#ifndef TRIE_H
#define TRIE_H

#include "node.h"
#include "page.h"
typedef struct trie Trie;

/**
 * Inicializa uma trie com vetor de character
 * eh inicializada com valores NULL.
 * 
 * @return trie inicializada
 */
Trie* initTrieNode();

/**
 * Funcao de insercao de palavra na trie.
 * @param {Trie**}head inicio da trie
 * @param {char*}string string da palavra para insercao
 * @param {Node*}nodeFile node do arquivo em que a palavra foi retirada
 * @param {int}isStop flag que indica se eh stopword
 */
void insert(Trie** head, char* string, Node* nodeFile, int isStop);

/**
 * Funcao de pesquisar palavra na trie.
 * @param {Trie*}head inicio da trie
 * @param {char*}string da palavra para busca
 * @param {int*}flag flag para indicar se encontrou stopword
 * 
 * @return lista de pages em que a palavra eh encontrada
 */
Pages* search(Trie* head, const char* string, int* flag);

/**
 * Libera informacoes da Trie
 * @param {Trie*}curs trie
 */
void destroyTrie(Trie* curs);

#endif
