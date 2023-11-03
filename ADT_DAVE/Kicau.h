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
    int NEff;
    int Capacity;
    int id;
    Word Text;
    int Likes;
    Word Auth;
    DATETIME dates;
    UAddress next_Address;
    BAddress next_Balasan;
}kicauan;

#define UNEXT(l) (l)->next_Address
#define BNEXT(l) (l)->next_Balasan

void CreateKicau();
#endif
