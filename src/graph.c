#include "graph.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "page.h"
#include "trie.h"
#include "node.h"

struct graph {
    Node **nodeArray;
    int nNodes;
};

Graph *initGraph(Node **vector, int nNode) {
    Graph *new = (Graph *)malloc(sizeof(Graph));
    new->nodeArray = vector;
    new->nNodes = nNode;
    return new;
}

Node** getNodeArray(Graph* graph) {
    return graph->nodeArray;
}

int getNumNodes(Graph* graph) {
    return graph->nNodes;
}

void updatePageRank(Graph *graph) {
    int tam = graph->nNodes;
	int counter = 0;
    while (1) {
        double error = 0;
        counter++;
        for (int i = 0; i < tam; i++){
            // pega o influenciador
            Node *aux = graph->nodeArray[i];
            calcPageRank(aux, tam);
        }
        for (int i = 0; i < tam; i++) {
            Node *aux = graph->nodeArray[i];
            double diff = changePRs(aux);
            error += fabs(diff);
        }
        error = error/ (double)tam;
        if (error <= 0.000001) {
            break;
        }
    }
}

void destroyGraph(Graph *graph) {
    destroyNodeVector(graph->nodeArray, graph->nNodes);
    free(graph);
}