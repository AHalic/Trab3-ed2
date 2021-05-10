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

/**
 * Retorna o nome do arquivo
 * @param {Node*}node célula de um arquivo
 *
 * @return nome do arquivo
 */
char* getFileName(Node* node);

/**
 * Retorna o índice do arquivo na tabela hash
 * @param {Node*}node célula de um arquivo
 *
 * @return índice do arquivo na tabela hash
 */
int getNodeId(Node* node);

/**
 * Retorna o valor antigo do PageRank do arquivo
 * @param {Node*}node célula de um arquivo
 *
 * @return {double}valor antigo do PageRank do arquivo
 */
double getOldPR(Node* node);

/**
 * Define o valor da quantidade de influenciados pelo arquivo @param node
 * @param {Node*}node célula de um arquivo
 * @param {int}value quantiade de influenciados
 */
void setNodeInfluenced(Node* node, int value);

/**
 * Insere @param next na próxima posição de @param origin
 * em relação a lista de células
 * @param {Node*}origin nó atual
 * @param {Node*}next próximo nó
 */
void insertNextNode(Node* origin, Node* next);

/**
 * Procura uma célula com nome @param string na lista de células
 * na mesma posição da tabela hash
 * @param {Node*}node primeiro nó da lista
 * @param {char*}string nome do arquivo que está sendo procurado
 * @param {int*}flag booleano que define se foi encontrado o arquivo ou não
 *
 * @return *NULL* se não encontra a célula ou *Node* se encontrar
 */
Node *searchNode(Node *node, char *string, int *flag);

/**
 * Calcula o valor do PageRank
 * @param {Node*}node célula de um arquivo
 * @param {int}nNodes quantidade arquivos englobados na pesquisa
 */
void calcPageRank(Node* node, int nNodes);

/**
 * Atualiza o valor do PageRank do arquivo e retorna a diferença
 * @param {Node*}node célula de um arquivo
 *
 * @return {double} diferença entre os PageRanks
 */
double changePRs(Node* node);

/**
 * Ordena as células de arquivo de um vetor de células
 * @param {Node**}nodeVet vetor de células de arquivo
 * @param {int}size tamanho do vetor
 */
void sortNodeVector(Node** nodeVet, int size);

#endif
