#ifndef NODE_H
#define NODE_H

// Define a estrutura Connection
typedef struct connection Connection;

// Define a estrutura Node
typedef struct node Node;

/**
 * Aloca e inicializa o Node
 * @param {int}id id do node na hash
 * @param {char*}fileName
 * 
 * @return Node inicializado e alocado
**/
Node* initNode(int id, char* fileName);

/**
 * Aloca e inicializa vetor de Nodes
 * @param {int}sz tamanho do vetor
 * 
 * @return vetor de Node
**/
Node** initNodeVector(int sz);

/**
 * Adiciona um node a lista de connection de outro
 * @param {Node*}origin
 * @param {Node*}connect node que será inserido na lista
**/
void addConnection(Node* origin, Node* connect);

/**
 * Desaloca toda memória alocada para a lista de connection
 * @param {Node*}node node contendo a lista
**/
void destroyConnections(Node* node);

/**
 * Desaloca toda a memória alocado para o Node
 * @param {Node*}node
**/
void destroyNode(Node* node);

/**
 * Desaloca toda memória alocada para o vetor de Node
 * @param {Node**}vector
 * @param {int}sz tamanho do vetor
**/
void destroyNodeVector(Node** vector, int sz);

char* getFileName(Node* node);

char* getFileName(Node* node);

int getNodeId(Node* node);

double getOldPR(Node* node);

void setNodeInfluenced(Node* node, int value);

void insertNextNode(Node* origin, Node* next);

Node *searchNode(Node *node, char *string, int *flag);

void calcPageRank(Node* node, int nNodes);

double changePRs(Node* node);

void sortNodeVector(Node** nodeVet, int size);

#endif
