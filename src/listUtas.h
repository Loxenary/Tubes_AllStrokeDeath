#ifndef LIST_UTAS_H
#define LIST_UTAS_H

#include "./adt/boolean.h"
#include "./adt/listStatikWord.h"
#include "./adt/datetime.h"

typedef struct Utas* Address;
typedef struct Utas{
    int IdUtas;
    int Idkicau;
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

void CreateUtas(ListUtas *U);

Address newUtas(int idutas,int idkicau, WrdType text, WrdType auth, DATETIME datetime);

void addUtas(ListUtas* u, int idutas, int idkicau, WrdType text, WrdType auth, DATETIME date);
/* membuat utas baru dan menambahkannya pada Utas */

Address getLastElement_LinkedUtas(ListUtas u);
/* mengembalikan address elemen terakhir dari linked list utas */

void insertAt_LinkedUtas(ListUtas u, int idutas, int idkicau, int idx, WrdType text, WrdType auth, DATETIME date);
/* menambahkan utas pada indeks tertentu. prekondisi panjang utas >= indeks */

int length_LinkedUtas(ListUtas u);
/* mengembalikan total elemen dari utas (panjang utas)*/

void deleteAt_LinkedUtas(ListUtas u, int idx);
/* menghapus elemen pada idx di linked list utas*/
#endif