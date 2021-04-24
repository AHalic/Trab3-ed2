#include "node.h"
#include <stdlib.h>

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
    double PRold, PRnew;    
    Connection* connection;        // lista de arquivos que tem link para esse
    int influenced, influences;    // quantidade de links para este e deste nó
    Node* next;                    // proximo node na lista 
};

Node* initNode(int id, char* fileName) {
    Node* new = (Node*) malloc (sizeof(Node));
    
    new->id = id;
    new->fileName = fileName;
    new->connection = (Connection*) malloc (sizeof(Connection));
    new->influenced = new->influences = 0;
    
    return new;
}

void addConnection(Node* origin, Node* connect) {
    if (origin == NULL || connect == NULL) return;

    Connection* aux = origin->connection;
    aux->node = connect;
    aux->next = (Connection*) malloc (sizeof(Connection));
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
}

void destroyNode(Node* node) {
    if (node == NULL) return;

    Node *aux1, *aux2;

    aux1 = node;

    while(aux1) {
        aux2 = aux1->next;
        free(aux1->fileName);
        free(aux1);
        aux1 = aux2;
    }
}
