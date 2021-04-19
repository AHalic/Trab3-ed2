#include "trie.h"
#include <stdio.h>

#define SZ 37 // 26 letras + 10 digitos + hifen

struct trie {
    Trie* characters[37];
    int isLeaf;   
};

