#include "Palavra.h"

void tolowers(char *string){
    for (int i = 0; i < strlen(string); i++){
        string[i] = tolower(string[i]);
    }
}

int Filter2(char *str){
    int i, x = 0, j = 0;
    for (i = 0; i < strlen(str); i++){
        if (isletter(str[i])||isnumb(str[i])){
            str[j] = str[i];
            j++;
            continue;
        }
        x++;
    }
    str[j] = '\0';
    return x;
}

int isletter(char a){
    return (a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z');
}

void Imprime_Palavra(Palavra item, char** argv){
    int i;
    struct arquivo *q;
    struct ind *r;
    printf("Nome: %s\n", item.string);
    for (q = item.file; q != NULL; q = q->Prox){
        // if (q->findices == NULL){
        //     continue;
        // }
        printf("%s: ", argv[q->file + 1]);
        for (r = q->findices; r != NULL; r = r->Prox){
            printf("%d ", r->index);
        }
        putchar('\n');
    }
}

Palavra* Libera_Palavra(Palavra item){
    struct arquivo *q, *qaux;
    struct ind *r, *raux;
    for (q = item.file; q != NULL; q = qaux){
        for (r = q->findices; r != NULL; r = raux){
            raux=r->Prox;
            free(r);
        }
        qaux = q->Prox;
        free(q);
    }
    free(item.string);
    return NULL;
}

int Filter(char *str){
    int i, x = 0, j = 0;
    // printf("%s\n", str);
    for (i = 0; i < strlen(str); i++){
        if (isnumb(str[0]) && (str[i] != ':' || !isnumb(str[i]))){
            i++;
            continue;
        }
        // printf("%c ", str[i]);
        // printf("Caso 1\n");
        if (isletter(str[i]) || isnumb(str[i])){
            str[j] = str[i];
            j++;
            continue;
        }
        //Nao criar palavras bizarras como 59sanguine
        //auxiliar com email
        if ((str[i] == '@')&& isletter(str[0])){
            str[j] = str[i];
            j++;
            continue;
        }
        //Ambos ifs para auxiliar com registro de links
        if ((str[i] == '.' || str[i] == '/'|| str[i] == ':') && (isletter(str[i+1]) || isnumb(str[i+1]) || str[i+1] == '/') && i != 0){
            str[j] = str[i];
            j++;
            continue;
        }
        //auxiliar com palavras peculiares que usam hífem e apóstrofo
        if ((str[i] == '\'' || str[i] == '-') && isletter(str[0])){
            str[j] = str[i];
            j++;
            continue;
        }
        x++; 
    }
    str[j] = '\0';
    // printf("%s\n", str);
    return x;
}


int isnumb(char a){
    return a >= '0' && a <= '9';
}