#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"

typedef struct graph Graph;


Graph *initGraph(Node** vector, int count_files);

void updatePageRank(Graph* graph);

void destroyGraph(Graph* graph);

void showAllPR(Graph* graph);

#endif