#include "trie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "utils.h"

#define SZ 37 // 26 letras + 10 digitos + hifen

struct trie {
    Trie* characters[37];
    Pages* files;
    bool isLeaf;
    bool isStop;
};

// Function that returns a new Trie node
Trie* initTrieNode() {
	Trie* node = (Trie*)malloc(sizeof(Trie));
	node->files = NULL;
	node->isLeaf = false;
	node->isStop = false;

	for (int i = 0; i < SZ; i++)
		node->characters[i] = NULL;

	return node;
}

// Iterative function to insert a string in Trie.
void insert(Trie** head, char* str, Node *nodeFile, int isStop) {
	// start from root node
    toLowerString(str);
	Trie* curr = *head, *aux_trie;
	while (*str) {
		if((*str - '0')>=0 && (*str - '0')<=9){
			// initTrieNode para digitos
			if (curr->characters[(*str - '0') + 26] == NULL) {
				curr->characters[(*str - '0') + 26] = initTrieNode();
			}
            aux_trie = curr->characters[(*str - '0') + 26];
		}
		else if ((*str - 'a') >= 0 && (*str - 'a')<26) {
			// initTrieNode para letras do alfabeto
			if (curr->characters[*str - 'a'] == NULL) {
				curr->characters[*str - 'a'] = initTrieNode();
                aux_trie = curr->characters[*str - 'a'];
			}
            aux_trie = curr->characters[*str - 'a'];
		}
		else if (*str == '-'){
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
	if(curr->isLeaf == false) {
		// insere em um no vazio
		curr->isLeaf = true;
		curr->isStop = isStop;
		if (nodeFile != NULL) {
		    Pages* p = initPage(nodeFile);
            insertPage(curr->files, p);
            curr->files = insertPage(curr->files, p);
		}
	}
	else {
		// insere arquivo em no ja existente

		// se for uma stopword, sai da funcao
		if(curr->isStop) return;  

		Pages* aux_pages = searchPage(curr->files, nodeFile);

		if (!aux_pages) {
			Pages* p = initPage(nodeFile);
            insertPage(curr->files, p);
            curr->files = insertPage(curr->files, p);
		}
	}
}

Pages* search(Trie *head, const char *str) {
	if (head == NULL) return NULL;
    char *normalizedStr = strdup(str);
    toLowerString(normalizedStr);
	int i = 0;

	Trie* curr = head;

	while (normalizedStr[i]) {
	    if ((normalizedStr[i] - 'a') >= 0 && (normalizedStr[i] - 'a') < 26) {
            curr = curr->characters[normalizedStr[i] - 'a'];
        }
	    else if ((normalizedStr[i] - '0') >= 0 && (normalizedStr[i] - '0') <= 9) {
            curr = curr->characters[(normalizedStr[i] - '0') + 26];
        }
	    else {
	        curr = curr->characters[36];
		}

		if (curr == NULL) {
			free(normalizedStr);
			return NULL;
		}
		i++;
	}
    
	free(normalizedStr);

	if (curr->isStop){
		return NULL;
	}
	
	return curr->files;
}

void destroyTrie(Trie* curs) {
    int i;
    if(!curs) return;
    for (i = 0; i < SZ; i++){
		if(curs->characters[i] != NULL){
			destroyTrie(curs->characters[i]);
		}
		if(curs->isLeaf == 1){
			destroyPageList(curs->files);
			curs->isLeaf = 0;
		}
	}
    free(curs);
}
