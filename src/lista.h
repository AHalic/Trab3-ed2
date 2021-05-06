
#ifndef _LISTA  
#define _LISTA 

#include "page.h"

typedef struct list List;

List* initList();

int isListEmpty (List* list);

void insertPageToList (Pages* page, List* list); 

void removePage (List* list, int id);

void filterList(List* list, Pages* pages);

void copyPagesList(Pages* pages, List* list) ;

void showList (List* list);

void destroyList(List* list);


#endif