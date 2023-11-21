#ifndef BALASAN_H
#define BALASAN_H

#include "wordmachine.h"
#include "datetime.h"
#include "tree.h" 

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

void inputNewKicauToListTree(ListTree *l);

void InsertNewBalasId(ListTree *l, Word Word,IDType id_k, IDType id_b);

void printNewBalasan(Tree k);

void inputBalas(ListTree *l , int id_k,int id_b);

void hapusBalasan(ListTree *l,IDType id_k,IDType id_b);

void displayBalasan(ListTree l,IDType id_k);

#endif
