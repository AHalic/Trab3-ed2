#include <stdlib.h>
#include "graph.h"
#include "word.h"
#include "trie.h"
#include "node.h"

struct graph {
    Node** nodeArray;
};


Graph *initGraph(int count_files) {
    Graph *new = (Graph *) malloc(sizeof(Graph));
    new->nodeArray = initNodeVector(count_files);

}

