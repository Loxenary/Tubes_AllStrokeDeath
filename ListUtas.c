#include <stdio.h>
#include <stdlib.h>
#include "ListUtas.h"


void CreateUtas(ListUtas *U)
{  
    FIRST(U) = NULL;
}

Address newUtas(int idutas, int idkicau, WrdType text, WrdType auth, DATETIME date){
    // kamus
    Address p;
    // algoritma
    p = (Address) malloc(sizeof(Utas));
    if(p != NULL){
        p->IdUtas = idutas;
        p->Idkicau = idkicau;
        p->texts = text;
        p->Author = auth;
        p->dateTime = date;
        p->NextAdress = NULL;
    }
    return p;
}

void addUtas(Utas* u, int idutas, int idkicau, WrdType text, WrdType auth, DATETIME date){
    // kamus 
    Address p, a;

    // algoritma
    // inisialisasi
    if(FIRST(u) == NULL){
        p = newUtas(0,idkicau, text, auth,date);
        FIRST(u) = p;
    } else{
        // awalnya utas tidak kosong
        a = FIRST(u);
        while(NEXT(a) != NULL){
            a = NEXT(a);
        }
        p = newUtas(a->IdUtas,a->Idkicau,text,auth,date);
        NEXT(a) = p;
    }

}

Address getLastElement_LinkedUtas(Utas* u){
    // kamus
    Address p;
    // algoritma
    p = FIRST(u);

    // handling kalau total elemen = 0
    if(p == NULL){
        return p;
    }
    while(NEXT(p) != NULL){
        p = NEXT(p);
    }
    // sekarang p = address elemen terakhir
    return p;
}

void insertAt_LinkedUtas(Utas* u, int idutas, int idkicau, int idx, WrdType text, WrdType auth, DATETIME date){
    // kamus
    int count;
    Address p, loc;
    // algoritma
    count = 0;
    loc = u;
    p = newUtas(idutas,idkicau,text,auth,date);
    if(p != NULL){
        while(count < idx - 1){
            count ++;
            loc = NEXT(loc);
        }
        NEXT(p) = NEXT(loc);
        NEXT(loc) = p;
    }
}

int length_LinkedUtas(Utas* u){
    // kamus
    int count = 0;
    Address p = u;
    // algoritma
    while(p != NULL){
        count++;
        p = NEXT(p);
    }
    return count;
}

void deleteAt_LinkedUtas(Utas* u, int idx){
    // kamus
    Address p,loc;
    int count;
    // algoritma
    count = 0;
    loc = u;
    while(count < idx-1){
        count++;
        loc = NEXT(loc);
    }
    p = NEXT(loc);
    NEXT(loc) = NEXT(p);
    free(p);
}