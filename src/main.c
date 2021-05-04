#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "page.h"
#include "hash.h"
#include "utils.h"

#define HASH_SZ 127 // TO DO: pesquisar como escolher um tamanho de HASH

int getUserInput(char *returnStr, int maxStringLength);

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
    updatePageRank(graph);

    // ordena vetor de arquivos
    sortNodeVector(filesVector, numFiles);   // nao seria legal isso ser parte de graph, ter uma funcao que chama?

    // cria trie vazia
    Trie *trie = initTrieNode();

    // adiciona a trie todas as stopwords e as palavras das paginas do grafo
    readStopWords(dir, trie);
    readPages(dir, graph, trie);

    char *lineBuffer = NULL;
    size_t n = 0;

    while (!feof(stdin)) {
        getline(&lineBuffer, &n, stdin);
        trimWhitespace(lineBuffer);
        char* token = strtok(lineBuffer, " ");

//        printf("consulta: ");
        while (token) {
            printf("%s\n", token);
            Pages* aux = search(trie, token);
            showPageList(aux);
            if(aux) printf("achou algo\n");
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    destroyGraph(graph);

    return 0;
}