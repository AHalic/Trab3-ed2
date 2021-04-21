
#include"TRIE.h"




// Function that returns a new Trie node
struct Trie* getNewTrieNode()
{
	struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
	node->p = NULL;
	node->isLeaf = 0;

	for (int i = 0; i < CHAR_SIZE; i++)
		node->character[i] = NULL;

	return node;
}

// Iterative function to insert a string in Trie.
void insert(struct Trie* *head, char* str, int j, int i)
{
	// start from root node
	struct Trie* curr = *head, *aux;
	char* c = str;
	Filter2(str);
	while (*str)
	{
		if((*str - '0')>=0 && (*str - '0')<=9){
			if (curr->character[(*str - '0') + 26] == NULL){
				curr->character[(*str - '0') + 26] = getNewTrieNode();
			}
			aux = curr->character[(*str - '0') + 26];
		}else{
			if (curr->character[*str - 'a'] == NULL){
				curr->character[*str - 'a'] = getNewTrieNode();
				aux = curr->character[*str - 'a'];
			}
			aux = curr->character[*str - 'a'];
		}
		curr = aux;
		str++;
	}
	//cria e coloca as coisas da estrutura no nó
	if(curr->isLeaf == 0){
		curr->isLeaf = 1;
		Palavra * p = (Palavra*)malloc(sizeof(Palavra));
		p->string = (char*)malloc(sizeof(char)*(strlen(c)+1));
		char *wrd = p->string;
		strcpy(wrd, c);
		// p->file = (arquivo*)malloc(sizeof(arquivo));
		// arquivo *arq = p->file;
		arq->Prox = NULL;
		arq->file = j;
		// arq->findices = (Ind*)malloc(sizeof(Ind));
		// Ind * indices = arq->findices;
		indices->index = i;
		indices->Prox = NULL;
		curr->p = p;
	}else{
		// arquivo * arquivo1 = curr->p->file;
        arquivo *ant, *aux;
        for(aux = arquivo1; aux != NULL; aux = aux->Prox){
			ant = aux;
        }
        if(ant->file != j){
			aux = malloc(sizeof(arquivo));
			ant->Prox = aux;
			aux->Prox = NULL;
			aux->file = j;
			// Ind*indnovo1 = (Ind*)malloc(sizeof(Ind));
			// aux->findices = indnovo1 ;
			indnovo1->index = i;
			indnovo1->Prox = NULL;     
        }else{

            // Ind* ind, *inda;
            // for(ind = ant->findices; ind!= NULL; ind = ind->Prox){
            //     inda = ind;
            // }
            // Ind * indnovo = (Ind*)malloc(sizeof(Ind));
            // inda->Prox = indnovo;
            // ind = inda->Prox;
            // indnovo->Prox = NULL;
            // indnovo->index = i;
		}
	}
}

int search(struct Trie* head, char* str,  char** argv){
	int i = 0;
	if (head == NULL)
		return 0;
	struct Trie* curr = head;
	char* aux = malloc(sizeof(char)*(strlen(str)+1));
	strcpy(aux, str);
	tolowers(aux);
	Filter2(aux);
	while (aux[i]){
		if((aux[i] - '0')>=0 && (aux[i] - '0')<=9){
			curr = curr->character[(aux[i] - '0') + 26];
		}else{
			curr = curr->character[aux[i] - 'a'];
		}
		
		if (curr == NULL){
			printf("gotcha\n\n");
			free(aux);
			return 0;
		}
		i++;
	}
	if(curr->isLeaf == 1){
		// Imprime_Palavra(*(curr->p), argv);
	}
	free(aux);
	return curr->isLeaf;
}

int haveChildren(struct Trie* curr)
{
	for (int i = 0; i < CHAR_SIZE; i++)
		if (curr->character[i])
			return 1;	// child found

	return 0;
}

// Acho q n precisamos
int deletion(struct Trie* *curr, char* str)
{
	if (*curr == NULL)
		return 0;
	if (*str)
	{
		if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
			deletion(&((*curr)->character[*str - 'a']), str + 1) &&
			(*curr)->isLeaf == 0)
		{
			if (!haveChildren(*curr))
			{
				free(*curr);
				(*curr) = NULL;
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	if (*str == '\0' && (*curr)->isLeaf)
	{
		if (!haveChildren(*curr))
		{
			free(*curr);
			(*curr) = NULL;
			return 1; 
		}
		else
		{
			(*curr)->isLeaf = 0;
			return 0;
		}
	}

	return 0;
}

void free_all(struct Trie* curs)
{
    int i;
    if(!curs) return;
    for (i = 0; i < CHAR_SIZE; i++){
		if(curs->character[i] != NULL){
			free_all(curs->character[i]);
		}
		if(curs->isLeaf == 1){
			Libera_Palavra(*(curs->p));
			free(curs->p);
			curs->isLeaf = 0;
		}
	}
    free(curs);
}