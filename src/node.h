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
    
    char* getFileName(Node* node);

    int getNodeId(Node* node);

    double getPRold(Node* node);

    double getPRnew(Node* node);

    int getNodeInfluenced(Node* node);

    void setNodeInfluenced(Node* node, int value);

    int getNodeInfluences(Node* node);

    void setNodeInfluences(Node* node, int value);

    void insertNextNode(Node* origin, Node* next);

    Node *searchNode(Node *node, char *string, int *flag);

#endif
