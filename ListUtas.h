#ifndef LIST_UTAS_H
#define LIST_UTAS_H

#include "boolean.h"
#include "ListStatikWord.h"
#include "datetime.h"

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

void CreateUtas(ListUtas * U);

Address newUtas(int id, WrdType text, WrdType auth, DATETIME datetime);

void addUtas(Utas* u, WrdType text, WrdType auth, DATETIME date);
/* membuat utas baru dan menambahkannya pada Utas */


#endif