#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "hash.h"
#include "graph.h"
#include "trie.h"

/**
 * Concatena as duas strings, com espaco alocado sendo a soma 
 * dos comprimentos das strings.
 * @param {char*}dir string do diretorio
 * @param {char*}file string do arquivo
 * 
 * @return string resultado da concatenacao das strings
 */ 
char* stringConcat(char* dir, char* file);

/**
 * Coloca todos os caracteres para minusculo.
 * @param {char*}string 
 */
void toLowerString(char *string);

/**
 * Retira whitespace de uma string
 * @param {char*}string
 * 
 * @return string sem whitespace
 */
char* trimWhitespace(char *string);

/**
 * Abre arquivo dado seu diretorio e nome
 * @param {char*}dir string do diretorio
 * @param {char*}file string do arquivo
 *  
 * @return ponteiro para o arquivo
 */
FILE* openFile(char* dir, char* file);

/**
 * Ler arquivo index.txt do diretorio da string 
 * informada. Sao criado nodes com o nome dos 
 * arquivos lido e inseridos em uma hash.
 * @param {char*}dir string do diretorio
 * @param {Hash*}hashFiles estrutura de hash vazia 
 *                         e inicializada
 * 
 * @return numero de arquivos lido
 */
int readIndex(char* dir, Hash* hashFiles);

/**
 * Ler arquivo graph.txt do diretorio da string
 * informada. Os arquivos de conexoes sao encontrados
 * usando a hash. Todas os Nodes referente a um arquivo
 * são colocados depois em um vetor de Node. O grafo eh
 * atualizado.
 * @param {char*}dir string do diretorio
 * @param {Hash*}hashFiles estrutura de hash preenchida
 * @param {Graph*}graph grafo com valores vazios
 */
void readGraph(char* dir, Hash* hashFiles, Graph* graph);

/**
 * Ler arquivo stopword.txt do diretorio da string 
 * informada. Adiciona stopwords a trie com flag de 
 * stopword setado.
 * @param {char*}dir string do diretorio
 * @param {Trie*}trie estrutura trie vazia e inicializada
 */
void readStopWords (char* dir, Trie* trie);

/**
 * Ler arquivos do diretorio de pages encontrado no
 * diretorio da string informada. Adiciona palavras
 * lida para trie.
 * @param {char*}dir string do diretorio
 * @param {Graph*}graph grafo com informacoes das paginas
 * @param {Trie*}trie estrutura trie incializada
 */
void readPages(char* dir, Graph* graph, Trie* trie);

/**
 * Recebe do stdin uma serie de palavras e imprime no
 * stdout a pagina em que se encontra as strings de palavra
 * alem dos pageranks.
 * @param {Trie*}trie
 */
void searchQuery (Trie* trie);

#endif