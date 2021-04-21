#include "trie.h"
#include <stdio.h>
#include "word.h"

#define SZ 37 // 26 letras + 10 digitos + hifen

struct trie {
    Trie* characters[37];
    Word* word;
    int isLeaf;   
    int isStop;
};

// Function that returns a new Trie node
Trie* getNewTrieNode() {
	Trie* node = (Trie*)malloc(sizeof(Trie));
	node->word = NULL;
	node->isLeaf = 0;
	node->isStop = 0;

	for (int i = 0; i < SZ; i++)
		node->characters[i] = NULL;

	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie* *head, char* str, char* file, int isStop) {
	// start from root node
	Trie* curr = *head, *aux;
	char* c = str;
	//Filter2(str);
	while (*c) {
		if((*str - '0')>=0 && (*str - '0')<=9){
			// getNewTrieNode para digitos
			if (curr->characters[(*str - '0') + 26] == NULL) {
				curr->characters[(*str - '0') + 26] = getNewTrieNode();
			}
			aux = curr->characters[(*str - '0') + 26];
		} else if ((*str - '0') >= 0 && (*str = '0')<26) {
			// getNewTrieNode para letras do alfabeto
			if (curr->characters[*str - 'a'] == NULL) {
				curr->characters[*str - 'a'] = getNewTrieNode();
				aux = curr->characters[*str - 'a'];
			}
			aux = curr->characters[*str - 'a'];
		} else {
			// getNewTrieNode para hifen		
			if (curr->characters[36] == NULL) {
				curr->characters[36] = getNewTrieNode();
				aux = curr->characters[36];
			}
			aux = curr->characters[36];
		}
		curr = aux;
		str++;
	}

	//cria e coloca as coisas da estrutura no nó
	if(curr->isLeaf == 0) {
		curr->isLeaf = 1;
		curr->isStop = isStop;
		Word* p = initWord(file);
        insertWord(curr->word, p);

	} else {
		Word* aux = searchWord(curr->word, file);
		
		if (!aux) {
			Word* p = initWord(file);
			insertWord(curr->word, p);
		} 
	}
}

int search(Trie* head, char* str,  char** argv){
	int i = 0;
	if (head == NULL)
		return 0;
	Trie* curr = head;
	char* aux = malloc(sizeof(char)*(strlen(str)+1));
	strcpy(aux, str);
	tolowers(aux);
	Filter2(aux);
	while (aux[i]){
		if((aux[i] - '0')>=0 && (aux[i] - '0')<=9){
			curr = curr->characters[(aux[i] - '0') + 26];
		}else{
			curr = curr->characters[aux[i] - 'a'];
		}
		
		if (curr == NULL){
			printf("gotcha\n\n");
			free(aux);
			return 0;
		}
		i++;
	}
	if(curr->isLeaf == 1){
		// Imprime_Word(*(curr->p), argv);
	}
	free(aux);
	return curr->isLeaf;
}

int haveChildren(Trie* curr)
{
	for (int i = 0; i < SZ; i++)
		if (curr->characters[i])
			return 1;	// child found

	return 0;
}

// Acho q n precisamos
int deletion(Trie* *curr, char* str)
{
	if (*curr == NULL)
		return 0;
	if (*str)
	{
		if (*curr != NULL && (*curr)->characters[*str - 'a'] != NULL &&
			deletion(&((*curr)->characters[*str - 'a']), str + 1) &&
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

void free_all(Trie* curs)
{
    int i;
    if(!curs) return;
    for (i = 0; i < SZ; i++){
		if(curs->characters[i] != NULL){
			free_all(curs->characters[i]);
		}
		if(curs->isLeaf == 1){
			Libera_Word(*(curs->p));
			free(curs->p);
			curs->isLeaf = 0;
		}
	}
    free(curs);
}
