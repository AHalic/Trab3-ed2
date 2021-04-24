#include "graph.h"
#include "word.h"
#include "trie.h"

struct node{ 
    int id;
    char* fileName;
    struct node* files;                  // lista de paginas que apontam para esse nó
    int influeciados, influencia;
};


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
