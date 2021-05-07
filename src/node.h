#ifndef NODE_H
#define NODE_H

typedef struct connection Connection;

typedef struct node Node;

Node* initNode(int id, char* fileName);

Node** initNodeVector(int sz);

void addConnection(Node* origin, Node* connect);

void destroyConnections(Node* node);

void destroyNode(Node* node);

void destroyNodeVector(Node** vector, int sz);

void printNode(Node* node);

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
