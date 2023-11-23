#include "permintaanpertemanan.h"

// check if a friend request exists
boolean isFriendRequestExist(PrioQueue friendRequests, Word sender, Word receiver) {
    for (int i = 0; i < friendRequests.size; i++) {
        PermintaanPertemanan request = friendRequests.array[i];
        if (isWordEqual(request.pengirim, sender) && isWordEqual(request.penerima, receiver)) {
            return TRUE;
        }
    }
    return FALSE;
}

// remove a friend request
void removeFriendRequest(PrioQueue* friendRequests, Word sender, Word receiver) {
    int i;
    for (i = 0; i < friendRequests->size; i++) {
        PermintaanPertemanan request = friendRequests->array[i];
        if (isWordEqual(request.pengirim, sender) && isWordEqual(request.penerima, receiver)) {
            break;
        }
    }

    if (i == friendRequests->size) {
        // Friend request not found
        return;
    }

    // Remove the friend request
    for (; i < friendRequests->size - 1; i++) {
        friendRequests->array[i] = friendRequests->array[i + 1];
    }

    friendRequests->size--;
}

// send a friend request
void sendFriendRequest(PrioQueue* friendRequests, Word sender, Word receiver) {
    if (!isFriendRequestExist(*friendRequests, sender, receiver)) {
        PermintaanPertemanan request;
        request.pengirim = sender;
        request.penerima = receiver;

        // Add the friend request to the priority queue
        Enqueue(friendRequests, request);
        printf("Permintaan pertemanan kepada ");
        printWord(receiver);
        printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
    } else {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
        printWord(receiver);
        printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
    }
}

// check if the user has pending friend requests
boolean hasPendingFriendRequests(PrioQueue friendRequests, Word user) {
    for (int i = 0; i < friendRequests.size; i++) {
        PermintaanPertemanan request = friendRequests.array[i];
        if (isWordEqual(request.penerima, user)) {
            return TRUE;
        }
    }
    return FALSE;
}

// display pending friend requests
void displayPendingFriendRequests(PrioQueue friendRequests) {
    printf("Terdapat %d permintaan pertemanan untuk Anda.\n", friendRequests.size);
    for (int i = 0; i < friendRequests.size; i++) {
        PermintaanPertemanan request = friendRequests.array[i];
        printf("- ");
        printWord(request.pengirim);
        printf("\n");
    }
}

// handle the friend request approval process
void processFriendRequest(PrioQueue* friendRequests, Word currentUser) {
    PermintaanPertemanan request = Dequeue(friendRequests);

    printf("Permintaan pertemanan teratas dari ");
    printWord(request.pengirim);
    printf("\n- ");
    printWord(request.pengirim);

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
    STARTWORD();

    if (isWordEqualString(currentWord, "YA")) {
        // Approve friend request
        printf("Permintaan pertemanan dari ");
        printWord(request.pengirim);
        printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
        printWord(request.pengirim);
        printf(".\n");
        int id_teman = SwindexOf(dataNama, request.penerima);
        int id_user=  SwindexOf(dataNama,currentUser);
        AddEdge(&matPertemanan,id_teman, id_user);
    } else {
        // Deny friend request
        printf("Permintaan pertemanan dari ");
        printWord(request.pengirim);
        printf(" telah ditolak.\n");
    }
}