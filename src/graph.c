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



/*

0 -> 1
  -> 2

O eh influenciado por 1 e 2;

[0 | 1 | 2]
 |      
---  
|1|
| |  
|2|
---

*/

/*
vetor de no arquivos

     0   0
     ^   ^
     |   |
[0 | 1 | 2]

P(0) = 1/n
P(1) = 1/n + 0.85P(0)
P(2) = 1/n + 0.85P(0)


0.txt 2 1.txt 2.txt
*/


// node** nodes;
//->quem aponta pra ele


//File** files;
//->indice do arquivo
