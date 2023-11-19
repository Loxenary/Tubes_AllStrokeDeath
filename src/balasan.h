#ifndef BALASAN_H
#define BALASAN_H

#include "wordmachine.h"
#include "datetime.h"
#include "tree.h" 

typedef Tree* Balasan;

typedef struct ListBalasan
{
    Balasan* balas;
    int nEff;
    int capacity;
}ListBalasan;

//List Balasan
#define BBUFFER(l) (l).balas
#define BELMT(l,i) (l).balas[i]
#define BCAPACITY(l) (l)->capacity
#define BNEFF(l) (l).nEff

void CreateListBalasan(ListBalasan *l, int Capacity);

void inputBalas(ListBalasan *l , int id_k,int id_b);

void InsertNewBalasId(ListBalasan *l, Word Word,IDType id_k, IDType id_b);

void printNewBalasan(Tree k);

void hapusBalasan(ListBalasan *l,IDType id_k,IDType id_b);

void displayBalasan(ListBalasan l,IDType id_k);

#endif