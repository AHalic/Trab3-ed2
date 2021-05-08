#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"

// Define a estrutura Graph
typedef struct graph Graph;

/**
 * Inicializa o graph
 * @param {Node**}vector vetor de nodes
 * @param {int}nNodes quantidade de nós no vetor
 * 
 * @return graph alocada e inicializada
**/
Graph *initGraph(Node** vector, int nNodes);

/**
 * Retorna o vetor de nodes de graph
 * @param {Graph*}graph
 * 
 * @return vetor de nodes
**/
Node** getNodeArray(Graph* graph);

/**
 * Retorna a quantidade de nodes em graph
 * @param {Graph*}graph
 * 
 * @return int quantidade de nodes
**/
int getNumNodes(Graph* graph);

/**
 * Atualiza os page ranks dos nodes presentes em graph
 * @param {Graph*}graph
**/
void updatePageRank(Graph* graph);

/**
 * Desaloca toda a memória alocada pela estrutura
 * @param {Graph*}graph
**/
void destroyGraph(Graph* graph);

#endif