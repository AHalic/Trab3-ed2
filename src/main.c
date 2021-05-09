#include "page.h"
#include "hash.h"
#include "utils.h"

#define HASH_SZ 509 

int main(int argc, char *argv[]) {
    if (argc != 2)
        return 1;

    // caminho do diretorio dos arquivos
    char *dir = argv[1];

    // hash para auxiliar com a busca dos arquivos e suas conexoes
    Hash *hashFiles = initHash(HASH_SZ);

    // cria grafo e calcula page rank
    int numFiles = readIndex(dir, hashFiles);
    Node **filesVector = initNodeVector(numFiles);

    Graph *graph = initGraph(filesVector, numFiles);
    readGraph(dir, hashFiles, graph);
    destroyHash(hashFiles);

    updatePageRank(graph);

    // ordena vetor de arquivos
    sortNodeVector(filesVector, numFiles);   

    // cria trie vazia
    Trie *trie = initTrieNode();

    // adiciona a trie todas as stopwords e as palavras das paginas do grafo
    readStopWords(dir, trie);
    readPages(dir, graph, trie);

    // faz busca
    searchQuery(trie);

    // libera memoria
    destroyGraph(graph);
    destroyTrie(trie);
    
    return 0;
}