#ifndef KICAU_H
#define KICAU_H
#include "Database.h"

typedef struct  UNode* UAddress;
typedef struct RootUtas{
    UAddress Utas;
}UNode;

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
}kicauan;

void CreateKicau();
#endif
