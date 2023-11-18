
#ifndef LOAD_KICAU_H
#define LOAD_KICAU_H


#include <stdio.h>
#include "./adt/wordmachine.h"
#include "listutas.h"
#include "./adt/datetime.h"

typedef struct Kicau
{   
    int jumlah_kicau;
    int id;
    Word Text;
    int Likes;
    Word Auth;
    DATETIME dates;
    ListUtas next_Utas;
    // BAddress next_Balasan;
} kicauan;

typedef struct List_Kicau
{
    kicauan* kicau;
    int nEff;
    int capacity;
}ListKicau;


#endif