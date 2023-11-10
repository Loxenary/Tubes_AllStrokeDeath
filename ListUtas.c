#include <stdio.h>
#include <stdlib.h>
#include "ListUtas.h"


void CreateUtas(ListUtas *U)
{  
    FIRST(U) = NULL;
}

Address newUtas(int id, WrdType text, WrdType auth, DATETIME date){
    // kamus
    Address p;
    // algoritma
    p = (Address) malloc(sizeof(Utas));
    if(p != NULL){
        p->Id = id;
        p->texts = text;
        p->Author = auth;
        p->dateTime = date;
        p->NextAdress = NULL;
    }
    return p;
}

void addUtas(Utas* u, WrdType text, WrdType auth, DATETIME date){
    // kamus 
    Address p, a;

    // algoritma
    // inisialisasi
    if(FIRST(u) == NULL){
        p = newUtas(0,text,auth,date);
        FIRST(u) = p;
    } else{
        // awalnya utas tidak kosong
        a = FIRST(u);
        while(NEXT(a) != NULL){
            a = NEXT(a);
        }
        p = newUtas(a->Id+1,text,auth,date);
        NEXT(a) = p;
    }

}

// boolean IsIdxFound(ListUtas U){
//     Address p = FIRST(U);
//     boolean isFound  = FALSE;
//     while (NEXT(p) != NULL)
//     {
//         if()
//         p = NEXT(p);
//     }
    
// }


