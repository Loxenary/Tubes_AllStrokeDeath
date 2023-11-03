#ifndef KICAU_H
#define KICAU_H
#include "Database.h"

typedef struct  UNode* UAddress;
typedef struct RootUtas{
    UAddress Utas;
}UNode;

typedef struct BNode * BAddress;
typedef struct RootBalasan{
    BAddress balasan;
}BNode;

typedef struct Kicau
{
    int id;
    Word Text;
    int Likes;
    Word Auth;
    DATETIME dates;
    UAddress next_Address;
    BAddress next_Balasan;
}kicauan;

typedef struct ListKicau
{
    int maxId;
    kicauan * kicau;
    int nEff;
    int capacity;
}ListKicau;

//Kicauan Definition
#define UNEXT(k) (k)->next_Address
#define BNEXT(k) (k)->next_Balasan
#define KAUTH(k) (k)->Auth
#define KDATE(k) (k)->dates
#define KTEXT(k) (k)->Text
#define KID(k) (k)->id
#define KLIKE(k) (k)->likes

//List Kicau
#define KBUFFER(l) (l).kicau
#define KELMT(l,i) (l).kicau[(i)]
#define KCAPACITY(l) (l).capacity
#define KNEFF(l) (l).nEff

void CreateEmptyKicau(kicauan * k);

void CreateEmptyListKicau(ListKicau * l);

void inputKicau(kicauan *k);

void sukaKicauan(kicauan *k, int idKicau);

void insertFirstKicau(kicauan * kicau);

void insertAtKicau(kicauan * kicau, int idx);
#endif
