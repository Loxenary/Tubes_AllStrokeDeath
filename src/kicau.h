#ifndef KICAU_H
#define KICAU_H

#include "teman.h"
#include "listutas.h"

typedef struct Kicau
{
    int id;
    Word Text;
    int Likes;
    Word Auth;
    DATETIME dates;
    // ListDin id_utas;
    // BAddress next_Balasan;
} kicauan;

typedef struct List_Kicau
{
    kicauan* kicau;
    int nEff;
    int capacity;
}ListKicau;

//Kicauan Definition
// #define UNEXT(k) (k)->next_Address
// #define BNEXT(k) (k)->next_Balasan
#define KAUTH(k) (k)->Auth
#define KDATE(k) (k)->dates
#define KTEXT(k) (k)->Text
#define KID(k) (k)->id
#define KLIKE(k) (k)->Likes

//List Kicau
#define KBUFFER(l) (l).kicau
#define KELMT(l,i) (l).kicau[(i)]
#define KCAPACITY(l) (l)->capacity
#define KNEFF(l) (l).nEff

void CreateListKicau(ListKicau *l, int Capacity);

void inputKicau(ListKicau l);

void sukaKicauan(int idKicau, ListKicau l);

void InsertNewLastKicau(ListKicau *l, Word Word);

kicauan CreateDefinedKicau(Word author, Word text, int Likes, DATETIME dates, int id);

void printDataKicauan(kicauan k);


void InsertDeclaredLastKicau(ListKicau *l, kicauan kicau);

void ubah_kicauan(int idKicau, ListKicau l);

void DisplayKicauan(ListKicau l, int id);


#endif
