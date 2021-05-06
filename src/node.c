#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
 * id            = id atribuido a pagina dado a ordem de leitura do arquivo 
 *                 index.txt
 * fileName      = nome do arquivo da pagina
 * connections   = lista de nodes, ou de paginas, a qual o nó tem uma conexao
 *                 de influenciadores. 
 * influenced    = numero de de paginas influenciadas
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
    for (int i = 0; i< sz; i++) { // 5 files
        destroyNode(vector[i]); // 1 + influencias + 1
    }
    free(vector); // 1
}

void printConnection(Connection* connection) {
    if (connection == NULL) return;

    Connection *aux = connection;

    printf("Connection: ");
    while (aux != NULL) {
        printf("%s, ", aux->node->fileName);
        aux = aux->next;
    }
    
}

void printNode(Node* node) {
    printf("[%d] %s: \n"
        "\tPR old=%f PR new=%f\n"
        "\tqtdInfluenciados=%d qtdInfluncias=%d\n", node->id, node->fileName, node->oldPR, node->newPR, node->influenced, node->influences);
    printConnection(node->connection);
    printf("\n");
}

char* getFileName(Node* node) {
    return node->fileName;
}

int getNodeId(Node* node) {
    return node->id;
}

double getPR_old(Node* node) {
    return node->oldPR;
}

double getPR_new(Node* node) {
    return node->newPR;
}

int getNodeInfluenced(Node* node) {
    return node->influenced;
}

void setNodeInfluenced(Node* node, int value) {
    node->influenced = value;
}

int getNodeInfluences(Node* node) {
    return node->influences;
}

void setNodeInfluences(Node* node, int value) {
    node->influences = value;
}

void insertNextNode(Node* origin, Node* next) {
    origin->next = next;
}

Node *searchNode(Node *node, char *string, int *flag) {
    Node* aux, *before = NULL;
    int f = 1;
    // printf("%s\n", node->fileName);
    for (aux = node; aux != NULL; aux = aux->next) {
        if (aux == NULL){
            printf("nó nulo??\n");
            break;
        }

        if ( aux->fileName != NULL && strcmp (string, aux->fileName) == 0) {
            flag = &f;
            return aux;
        }

        before = aux;
    }

    return before;
}

void calcPageRank(Node* node, int nNodes){
    if(node->oldPR == 0) {
        node->newPR = 1.0 / nNodes;
    }else{
        printf("entrei no else 1\n");
        if(node->influenced == 0){
            node->newPR = 0.15 / nNodes + 0.85 * node->oldPR;
            Connection * connection = node->connection;
            while (connection){
                // TODO: O vetor de connection esta cagado
                printf("tem connection 1\n");
                Node* aux = connection->node;
                node->newPR += 0.85 * aux->oldPR/aux->influenced;
                connection = connection->next;
            }
        }else{
            printf("entrei no else 2\n");
            node->newPR = 0.15 / nNodes;
            Connection * connection = node->connection;
            while (connection){
                // TODO: O vetor de connection esta cagado
                printf("tem connection 2\n");
                Node* aux = connection->node;
                node->newPR += 0.85 * aux->oldPR/aux->influenced;
                connection = connection->next;
            }
        }
    }
    printf("Node: %s ", node->fileName);
    printf("New: %lf Old: %lf\n", node->newPR, node->oldPR);
}

double changePRs(Node* node){
    double diff = node->newPR - node->oldPR;
    node->oldPR = node->newPR;
    node->newPR = 0;
    return diff;
}

static int compareNodes(const void* n1, const void* n2) {
    const Node* pri = *(const Node**) n1;
    const Node* seg = *(const Node**) n2;
    return (pri->oldPR > seg->oldPR) - (pri->oldPR < seg->oldPR);
}

void sortNodeVector(Node** nodeVet, int size){
    qsort(nodeVet, size, sizeof(Node*), compareNodes);
}
