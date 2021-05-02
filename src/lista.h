
#ifndef _LISTA  
#define _LISTA 

#include "page.h"


typedef struct list List;


List* initList();

int isListEmpty (List* list);

void insertPageToList (Pages* page, List* list); 

void removePage (List* list, int id);

void showList (List* list);

void destroyList(List* list);


#endif