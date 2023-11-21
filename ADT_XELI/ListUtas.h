#ifndef LIST_UTAS_H
#define LIST_UTAS_H

#include "boolean.h"
#include "ListStatikWord.h"
#include "listdin.h"
#include "datetime.h"

typedef struct node* Address;

typedef struct node{
    int maxId;
    WrdType texts;
    WrdType Author;
    DATETIME dateTime;
    Address NextAdress;
}Node;


#define NEFF(l) (l).nEff
#define Date(l,i) (l).dateTime[i]
#define Text(l,i) (l).texts[i]
#define Auth(l,i) (l).Author[i]
#define NEXT(p) (p)->next

#define FIRST(l) (l) 

typedef Address ListUtas;

void CreateUtas(ListUtas *U, int Capacity);

void InputUtas(ListUtas *U, int id);


#endif