#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hash.h"
#include "utils.h"
#include "graph.h"
#include "trie.h"

#define HASH_SZ 127 // TO DO: pesquisar como escolher um tamanho de HASH


int main(int argc, char* argv[]) {
    if (argc != 2)
        return 1;

    // caminho do diretorio dos arquivos
    char* dir = argv[1];                              
    
    // hash para auxiliar com a busca dos arquivos e suas conexoes
    Hash* hashFiles = initHash(HASH_SZ);              

    // cria grafo e calcula page rank
    int numFiles = readIndex(dir, hashFiles);
    Node** filesVector = initNodeVector(numFiles); 
    Graph* graph = initGraph(filesVector, numFiles);
    readGraph(dir, hashFiles, graph);    
    updatePageRank(graph);

    // ordena vetor de arquivos
    sortNodeVector(filesVector, numFiles);   // nao seria legal isso ser parte de graph, ter uma funcao que chama?

    // cria trie vazia
    Trie* trie = initTrieNode();

    // adiciona a trie todas as stopwords e as palavras das paginas do grafo
    readStopWords(dir, trie);
    readPages(dir, graph, trie);

    
    // while (!feof(stdin)) {
    //     getline(&lineBuffer, &n, stdin);

    // }

    destroyGraph(graph);

    return 0;
}
