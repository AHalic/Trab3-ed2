#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "hash.h"
#include "page.h"
#include "node.h"
#include "graph.h"
#include "trie.h"



/**************FUNCOES DE STRING**************/

char* stringConcat(char* dir, char* file) {
    int dirLen = strlen(dir);
    
    char* fileName = file;
    int fileSz = strlen(fileName);

    char* filePath = (char*) malloc (sizeof(char) * (dirLen + fileSz + 1));  
    
    strcpy(filePath, dir);
    strcat(filePath, fileName);


    return filePath;
}

void toLowerString(char *string){
    for (int i = 0; i < strlen(string); i++){
        string[i] = tolower(string[i]);
    }
}

char *trimwhitespace(char *str) {
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

/**************FUNCOES DE LEITURA**************/

FILE* openFile(char* dir, char* file){
    FILE* fp;
    char* filePath;

    filePath = stringConcat(dir, file);
    fp = fopen(filePath, "r");

    free(filePath);

    return fp;
}

int readIndex(char* arq, Hash* hashFiles) {
    FILE* indexFile = openFile(arq, "index.txt");
    
    if(!indexFile) {
        printf("Não foi encontrado o arquivo index.txt\n");
        exit(1);         
    }

    char* lineBuffer = NULL;
    size_t n;
    int nFiles = 0;

    // Lendo index.txt e preenchendo a hash
    while(!feof(indexFile)) {
        getline(&lineBuffer, &n, indexFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        access(hashFiles, lineBuffer);
        nFiles++;
    }
    fclose(indexFile);
    free(lineBuffer);
    
    return nFiles;
}

void readGraph(char* file, Hash* hashFiles, Graph* graph) {
    FILE* graphFile = openFile(file, "graph.txt");

    if(!graphFile) {
        printf("Não foi encontrado o arquivo graph.txt\n");
        exit(1);   
    }

    int nArray = getNumNodes(graph);
    Node** filesVector = getNodeArray(graph);
    
    size_t n;
    char* lineBuffer = NULL;

    for (int i = 0; i < nArray; ++i) {
        getline(&lineBuffer, &n, graphFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';

        char delim[2] = " ";
        char* token = strtok(lineBuffer, delim);
        Node* nodeFile = access(hashFiles, token);
        filesVector[i] = nodeFile;

        token = strtok(NULL, delim);
        int nInfluenced = atoi(token);
        setNodeInfluenced(nodeFile, nInfluenced);

        // Lê os nós que influenciam a página
        for (int j = 0; j < nInfluenced && token != NULL; j++){
            token = strtok(NULL, delim);
            Node* influencer = access(hashFiles, token);
            addConnection(influencer, nodeFile);
        }
    }
    free(lineBuffer);
    destroyHash(hashFiles);
    fclose(graphFile);
}

void readStopWords (char* dir, Trie* trie) {
    FILE* stopWordsFile;
    stopWordsFile = openFile(dir, "stopwords.txt");

    if(!stopWordsFile) {
        printf("Não foi encontrado o arquivo stopwords.txt\n");
        exit(1);      
    }

    char* lineBuffer = NULL;
    size_t n;    

    while(!feof(stopWordsFile)) {
        getline(&lineBuffer, &n, stopWordsFile);
        lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';
        insert(&trie , lineBuffer, NULL, true);
    }

    free(lineBuffer);
}

void readPages(char* dir, Graph* graph, Trie* trie) {
    Node** filesVector = getNodeArray(graph);
    int arraySize = getNumNodes(graph);

    size_t n;
    char* lineBuffer = NULL;

    // ler arquivos
    for (int i = 0; i < arraySize; i++) {
        char* path = getFileName(filesVector[i]);                // pega nome do arquivo no vetor de nos
        char* pagePath = stringConcat("pages/", path);           // concatena o nome do diretorio "pages/" + arq
        
        FILE* page = openFile(dir, pagePath);                    // abre arquivo do diretorio pages

        // caso a pagina nao existe
        if (!page) {
            printf("Não foi encontrado o arquivo %s\n", path);
            exit(1);
        }

        // ler paginas e armazena palavras
        while(!feof(page)) {
            getline(&lineBuffer, &n, page);
            lineBuffer[strcspn(lineBuffer, "\r\n")] = '\0';
            insert(&trie , lineBuffer, filesVector[i], false);  // false = nao eh stopword
        }
    }

    free(lineBuffer);
}

