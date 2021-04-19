#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
#include "palavra.h"

#define NPAL 64
#define NTAB 127

int lePalavra (FILE* fp, char* s) {
    int i = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c))
            break;
    }

    if (c == EOF)
        return 0;
    else
        s[i++] = c;

    while ((i < NPAL - 1) && (c=fgetc(fp)) != EOF && isalpha(c)) 
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int main (int argc, char *argv[]) {
    FILE* fp; 
    Hash* tab;
    char s[NPAL];

    if (argc != 2) {
        printf("Arquivo não encontrado\n");
        return 0;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf ("Erro na abertura do arquivo!\n");
        return 0;
    }

    tab = inicHash (NTAB);

    while (lePalavra(fp, s)) {
        Palavra* p = acessa (tab, s);
        atualizaOcorrencias(p);
    }

    printf("Imprime Tabela Hash:\n");
    imprimeHash(tab);

    printf("\nLibera Tabela Hash:\n");
    liberaHash(tab);

    return 0;
}