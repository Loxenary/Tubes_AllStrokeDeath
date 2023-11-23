#include "../src/adt/prioqueue.h"

// Function to display the contents of the priority queue
void displayQueue(PrioQueue pq) {
    if (IsPrioQueueEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq.size; i++) {
        printf("(%s, %s, %d)\n", pq.array[i].pengirim.TabWord, pq.array[i].penerima.TabWord, pq.array[i].kepopuleran);
    }
    printf("\n");
}

int main() {
    // Initialize the priority queue
    PrioQueue pq;
    PrioQueueInitialize(&pq, 10);

    // Enqueue some friend requests for Alice
    printf("Sending friend requests...\n");

    PermintaanPertemanan request1 = {.pengirim = StringToWord("Alice", 5), .penerima = StringToWord("Bob", 3), .kepopuleran = 3};
    PermintaanPertemanan request2 = {.pengirim = StringToWord("Alice", 5), .penerima = StringToWord("Carol", 5), .kepopuleran = 5};
    PermintaanPertemanan request3 = {.pengirim = StringToWord("Alice", 5), .penerima = StringToWord("David", 5), .kepopuleran = 5};
    PermintaanPertemanan request4 = {.pengirim = StringToWord("Alice", 5), .penerima = StringToWord("Lora", 4), .kepopuleran = 3};

    Enqueue(&pq, request1);
    Enqueue(&pq, request2);
    Enqueue(&pq, request3);
    Enqueue(&pq, request4);

    // Display the current state of the friend request queue
    printf("\nInitial State of the Friend Request Queue:\n");
    displayQueue(pq);

    // Responding to friend requests
    printf("\nResponding to friend requests...\n");

    // Dequeue and respond to friend requests
    while (!IsPrioQueueEmpty(pq)) {
        PermintaanPertemanan dequeuedRequest = Dequeue(&pq);
        printf("Responding to friend request from %s to %s with popularity %d...\n",
               dequeuedRequest.pengirim.TabWord, dequeuedRequest.penerima.TabWord, dequeuedRequest.kepopuleran);
    }

    // Display the updated state of the friend request queue
    printf("\nUpdated State of the Friend Request Queue:\n");
    displayQueue(pq);

    // Destroy the friend request queue
    PrioQueueDestroy(&pq);

    return 0;
}