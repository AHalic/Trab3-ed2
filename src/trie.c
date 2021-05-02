#include "trie.h"
#include <stdlib.h>
#include <string.h>
#include "page.h"

#define SZ 37 // 26 letras + 10 digitos + hifen

struct trie {
    Trie* characters[37];
    Pages* files;
    int isLeaf;   
    int isStop;
};

// Function that returns a new Trie node
Trie* initTrieNode() {
	Trie* node = (Trie*)malloc(sizeof(Trie));
	node->files = NULL;
	node->isLeaf = 0;
	node->isStop = 0;

	for (int i = 0; i < SZ; i++)
		node->characters[i] = NULL;

	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie** head, char* str, Node *nodeFile, int isStop) {
	// start from root node
	Trie* curr = *head, *aux_trie;
	char* c = str;
	while (*str) {
		if((*str - '0')>=0 && (*str - '0')<=9){
			// initTrieNode para digitos
			if (curr->characters[(*str - '0') + 26] == NULL) {
				curr->characters[(*str - '0') + 26] = initTrieNode();
			}
            aux_trie = curr->characters[(*str - '0') + 26];
		} else if ((*str - 'a') >= 0 && (*str - 'z')<26) {
			// initTrieNode para letras do alfabeto
			if (curr->characters[*str - 'a'] == NULL) {
				curr->characters[*str - 'a'] = initTrieNode();
                aux_trie = curr->characters[*str - 'a'];
			}
            aux_trie = curr->characters[*str - 'a'];
		} else {
			// initTrieNode para hifen		
			if (curr->characters[36] == NULL) {
				curr->characters[36] = initTrieNode();
                aux_trie = curr->characters[36];
			}
            aux_trie = curr->characters[36];
		}
		curr = aux_trie;
		str++;
	}

	//cria e coloca as coisas da estrutura no nó
	if(curr->isLeaf == 0) {
		curr->isLeaf = 1;
		curr->isStop = isStop;
		if (nodeFile != NULL) {
		    Pages* p = initPage(nodeFile);
            insertPage(curr->files, p);
		}


	} else {
		Pages* aux_word = searchWord(curr->files, nodeFile);
		
		if (!aux_word) {
			Pages* p = initPage(nodeFile);
            insertPage(curr->files, p);
		} 
	}
}

int search(Trie *head, const char *str) {
	if (head == NULL) return 0;
	
	int i = 0;

	Trie* curr = head;
	// char* aux = (char*) malloc(sizeof(char) * (strlen(str)+1));
	// strcpy(aux, str);
	

	while (str[i]) {
		if((str[i] - '0') >= 0 && (str[i] - '0') <= 9){
			curr = curr->characters[(str[i] - '0') + 26];
		}else{
			curr = curr->characters[str[i] - 'a'];
		}
		
		if (curr == NULL) {
			return 0;
		}
		i++;
	}

	return curr->isLeaf;
}

int haveChildren(Trie* curr) {
	for (int i = 0; i < SZ; i++)
		if (curr->characters[i])
			return 1;	// child found

	return 0;
}

// Acho q n precisamos
int deletion(Trie* *curr, char* str) {
	if (*curr == NULL) return 0;
	if (*str) {
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

void free_all(Trie* curs) {
    int i;
    if(!curs) return;
    for (i = 0; i < SZ; i++){
		if(curs->characters[i] != NULL){
			free_all(curs->characters[i]);
		}
		if(curs->isLeaf == 1){
			destroyWordList(curs->files);
			free(curs->files);
			curs->isLeaf = 0;
		}
	}
    free(curs);
}
