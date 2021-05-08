#include "trie.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "utils.h"

#define SZ 37 // 26 letras + 10 digitos + hifen

// characters: vetor para caber 26 letras + 10 digitos + hifen
// files: lista de Pages
// isLeaf: flag para ver se chegou no final da palavra
// isStop: flag para ver se eh stopword
struct trie {
    Trie* characters[37];
    Pages* files;
    bool isLeaf;
    bool isStop;
};

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
void insert(Trie** head, char* string, Node* nodeFile, int isStop) {
	// start from root node
    toLowerString(string);
	Trie* curr = *head, *aux_trie;
	while (*string) {
		if((*string - '0')>=0 && (*string - '0')<=9){
			// initTrieNode para digitos
			if (curr->characters[(*string - '0') + 26] == NULL) {
				curr->characters[(*string - '0') + 26] = initTrieNode();
			}
            aux_trie = curr->characters[(*string - '0') + 26];
		}
		else if ((*string - 'a') >= 0 && (*string - 'a')<26) {
			// initTrieNode para letras do alfabeto
			if (curr->characters[*string - 'a'] == NULL) {
				curr->characters[*string - 'a'] = initTrieNode();
                aux_trie = curr->characters[*string - 'a'];
			}
            aux_trie = curr->characters[*string - 'a'];
		}
		else if (*string == '-'){
			// initTrieNode para hifen
			if (curr->characters[36] == NULL) {
				curr->characters[36] = initTrieNode();
                aux_trie = curr->characters[36];
			}
            aux_trie = curr->characters[36];
		} 

		curr = aux_trie;
		string++;
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

Pages* search(Trie *head, const char *str, int* flag) {
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
		*flag = 1;
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
