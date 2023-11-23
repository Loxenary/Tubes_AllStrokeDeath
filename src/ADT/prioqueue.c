#include "prioqueue.h"
#include <stdlib.h>

void PrioQueueInitialize(PrioQueue* pq, int capacity) {
    pq->array = (PermintaanPertemanan*)malloc(capacity * sizeof(PermintaanPertemanan));
    pq->capacity = capacity;
    pq->size = 0;
}

boolean IsPrioQueueEmpty(PrioQueue pq) {
    return pq.size == 0;
}

void Enqueue(PrioQueue* pq, PermintaanPertemanan data) {
    if (pq->size == pq->capacity) {
        printf("Queue is full\n");
        return;
    }

    int i = pq->size - 1;
    while (i >= 0 && data.kepopuleran > pq->array[i].kepopuleran) {
        pq->array[i + 1] = pq->array[i];
        i--;
    }
    pq->array[i + 1] = data;
    pq->size++;
}

PermintaanPertemanan Dequeue(PrioQueue* pq) {
    if (IsPrioQueueEmpty(*pq)) {
        exit(EXIT_FAILURE);
    }

    PermintaanPertemanan root = pq->array[0];
    pq->size--;

    if (!IsPrioQueueEmpty(*pq)) {
        PermintaanPertemanan last = pq->array[pq->size];
        int i = 0;

        while (2 * i + 1 < pq->size) {
            int child = 2 * i + 1;

            if (child + 1 < pq->size && pq->array[child].kepopuleran < pq->array[child + 1].kepopuleran) {
                child++;
            }

            if (last.kepopuleran >= pq->array[child].kepopuleran) {
                break;
            }

            pq->array[i] = pq->array[child];
            i = child;
        }

        pq->array[i] = last;
    }

    return root;
}

void PrioQueueDestroy(PrioQueue* pq) {
    free(pq->array);
    pq->array = NULL;
    pq->size = pq->capacity = 0;
}