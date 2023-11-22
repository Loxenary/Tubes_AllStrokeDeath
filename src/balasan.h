#ifndef BALASAN_H
#define BALASAN_H

#include "./adt/wordmachine.h"
#include "./adt/datetime.h"
#include "./adt/tree.h" 

typedef struct ListTree
{
    Tree* balas;
    int nEff;
    int capacity;
}ListTree;

//List Balasan
#define BBUFFER(l) (l).balas
#define BELMT(l,i) (l).balas[i]
#define BCAPACITY(l) (l)->capacity
#define BNEFF(l) (l).nEff

void CreateListTree(ListTree *l, int Capacity);

void inputNewKicauToListTree(ListTree *l,kicauan kicau,IdxType id);

void ubahKicauToNewBalasan(Tree *t, kicauan new);

void InsertNewBalasId(ListTree *l, Word Word,IDType id_k, IDType id_b);

void printNewBalasan(Tree k);

void inputBalas(ListTree *l , int id_k,int id_b);

void hapusBalasan(ListTree *l,IDType id_k,IDType id_b);

void displayBalasan(ListTree l,IDType id_k);

void expandListTree(ListTree *l, int num);

void bacaConfigBalasan(ListTree *l,int id_k,int id_b,int id_baru,Word text,WordType Auth, DATETIME Date);

#endif