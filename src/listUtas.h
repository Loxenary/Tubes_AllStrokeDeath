#ifndef LIST_UTAS_H
#define LIST_UTAS_H

#include "./adt/boolean.h"
#include "./adt/ListStatikWord.h"
#include "./adt/datetime.h"

typedef struct Utas* Address;

typedef struct Utas{
    int Id;
    WrdType texts;
    WrdType Author;
    DATETIME dateTime;
    Address NextAdress;
}Utas;


#define NEFF(l) (l).nEff
#define Date(l,i) (l).dateTime[i]
#define Text(l,i) (l).texts[i]
#define Auth(l,i) (l).Author[i]
#define NEXT(p) (p)->NextAdress

#define FIRST(l) (l) 

typedef Address ListUtas;

void CreateUtas(ListUtas* U);

// void InputUtas(ListUtas *U, int id,);


#endif