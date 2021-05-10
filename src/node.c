#include "node.h"
#include <stdlib.h>
#include <string.h>

/**
 * Lista de connection (conexoes), que aponta para a pagina conectada a pagina 
 * principal e a proxima conexao.
 */
typedef struct connection {
    Node* node;                    // no da pagina
    Connection* next;              // lista de paginas conectadas 
} Connection;

/**
 * A lista de nodes, ou lista de paginas, possui todas as paginas do index.
 * Cada node representa uma pagina, e possui um id, o nome do arquivo, a 
 * quantidade de influenciados e quantos influencia, mais uma lista de 
 * paginas que possui conexao com a pagina do node. 
 * 
 * id            = id atribuido a pagina conforme calculo da hash
 * fileName      = nome do arquivo da pagina
 * connections   = lista de nodes, ou de paginas, a qual o nó tem uma conexao
 *                 de influenciadores. 
 * influenced    = numero de paginas influenciadas
 * influences    = numero de paginas que influencia
 * next          = a proxima pagina lida do arquivo index.txt
 */
struct node{
    int id;                        // id do nó
    char* fileName;                // nome do arquivo
    double oldPR, newPR;
    Connection* connection;        // lista de arquivos que tem link para esse
    int influenced, influences;    // quantidade de links para este e deste nó
    Node* next;                    // proximo node na lista 
};

Node* initNode(int id, char* fileName) {
    Node* new = (Node*) malloc (sizeof(Node));
    
    new->id = id;
    new->fileName = fileName;
    new->connection = NULL;
    new->influenced = new->influences = 0;
    new->oldPR = new->newPR = 0;
    new->next = NULL;

    return new;
}

Node** initNodeVector(int sz) {
    Node** vector = (Node**) malloc (sizeof(Node*) * sz);
    return vector;
}

void addConnection(Node* origin, Node* connect) {
    if (origin == NULL || connect == NULL) return;

    Connection* aux = (Connection*) malloc(sizeof(Connection));
    aux->next = origin->connection;
    aux->node = connect;
    origin->connection = aux;
    origin->influences++;
} 

void destroyConnections(Node* node) {
    if (node == NULL) return;

    Connection *aux1, *aux2;

    aux1 = node->connection;

    while(aux1) {
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }
    node->connection = NULL;
}

void destroyNode(Node* node) {
    if (node == NULL) return;

    destroyConnections(node);
    free(node->fileName);
    free(node);
}

void destroyNodeVector(Node** vector, int sz) {
    for (int i = 0; i< sz; i++) {
        destroyNode(vector[i]);
    }
    free(vector);
}

char* getFileName(Node* node) {
    return node->fileName;
}

int getNodeId(Node* node) {
    return node->id;
}

double getOldPR(Node* node) {
    return node->oldPR;
}

void setNodeInfluenced(Node* node, int value) {
    node->influenced = value;
}

void insertNextNode(Node* origin, Node* next) {
    origin->next = next;
}

Node *searchNode(Node *node, char *string, int *flag) {
    Node* aux = NULL, *before = NULL;

    for (aux = node; aux != NULL; aux = aux->next) {
        if ( aux->fileName != NULL && strcmp (string, aux->fileName) == 0) {
            *flag = 1;
            return aux;
        }
        before = aux;
    }

    return before;
}

void calcPageRank(Node* node, int nNodes){
    if(node->oldPR == 0) {
        node->newPR = 1.0 / nNodes;
    }
    else {
        if(node->influenced == 0){
            node->newPR = 0.15 / nNodes + 0.85 * node->oldPR;
            Connection * connection = node->connection;
            while (connection){
                Node* aux = connection->node;
                node->newPR += 0.85 * aux->oldPR/aux->influenced;
                connection = connection->next;
            }
        }
        else {
            node->newPR = 0.15 / nNodes;
            Connection * connection = node->connection;
            while (connection){
                Node* aux = connection->node;
                node->newPR += 0.85 * aux->oldPR/aux->influenced;
                connection = connection->next;
            }
        }
    }
}

double changePRs(Node* node){
    double diff = node->newPR - node->oldPR;
    node->oldPR = node->newPR;
    node->newPR = 0;
    return diff;
}

/**
 * Compara os valores de PageRank entre duas células
 * @param n1 célula de um arquivo
 * @param n2 célula de um arquivo
 * @return -1, n1 >= n2 | 1 ou 0, n1 < n2
 */
static int compareNodesByPageRank(const void* n1, const void* n2) {
    const Node* pri = *(const Node**) n1;
    const Node* seg = *(const Node**) n2;
    if (pri->oldPR < seg->oldPR) {
        return 1;
    }
    else if (pri->oldPR > seg->oldPR) {
        return -1;
    }
    else {
        return strcmp(pri->fileName, seg->fileName);        
    }

    // return (pri->oldPR < seg->oldPR) - (pri->oldPR > seg->oldPR);
}

void sortNodeVector(Node** nodeVet, int size){
    qsort(nodeVet, size, sizeof(Node*), compareNodesByPageRank);
}
