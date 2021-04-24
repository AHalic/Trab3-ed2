
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Palavra{
    char* string;
    struct arquivo *listaArquivos;
}Palavra;

// Lista de arquivos que a palavra apar
typedef struct arquivo{
    int file;
    char *nomeArquivo;
    // struct ind *findices;
    struct arquivo *Prox;
}arquivo;

// typedef struct ind{
//     int index;
//     struct ind *Prox;
// }Ind; 


//função para ler os arquivos
FILE** Leitura(int argc, char** argv);

//Função para liberar os arquivos
void Fechamento(FILE **file, int argc, char** argv);

// int ONDICT(TipoLista *dicionario, char*str);

// void Dict_Entry(TipoLista *dicionario, char* str, int file, int n);

// void Imprime_Dict(TipoLista *dicionario, char **argv);

void Imprime_Palavra(Palavra item, char** argv);

// funcao de string
int strcmpi(char *string, char* string2);

int Filter2(char *str);

int isletter(char a);

void tolowers(char *string);

//dá free nos componentes da palavra;
Palavra* Libera_Palavra(Palavra item);

int Filter(char *str);


int isnumb(char a);