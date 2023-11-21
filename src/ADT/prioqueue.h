#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "wordmachine.h"

typedef struct {
    Word pengirim;
    Word penerima;
    int kepopuleran;
} PermintaanPertemanan;

typedef struct {
    PermintaanPertemanan* array;
    int capacity;
    int size;
} PrioQueue;

void PrioQueueInitialize(PrioQueue* pq, int capacity);
boolean IsPrioQueueEmpty(PrioQueue pq);
void Enqueue(PrioQueue* pq, PermintaanPertemanan data);
PermintaanPertemanan Dequeue(PrioQueue* pq);
void PrioQueueDestroy(PrioQueue* pq);

#endif /* PRIOQUEUE_H */