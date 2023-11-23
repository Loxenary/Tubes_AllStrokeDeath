#include "permintaanpertemanan.h"

boolean isFriendRequestExist(PrioQueue friendRequests, Word sender, Word receiver) {
    for (int i = 0; i < friendRequests.size; i++) {
        PermintaanPertemanan request = friendRequests.array[i];
        if (isWordEqual(request.pengirim, sender) && isWordEqual(request.penerima, receiver)) {
            return TRUE;
        }
    }
    return FALSE;
}

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

    for (; i < friendRequests->size - 1; i++) {
        friendRequests->array[i] = friendRequests->array[i + 1];
    }

    friendRequests->size--;
}

void sendFriendRequest(PrioQueue* friendRequests, Word currentUser) {
    if (hasPendingFriendRequests(*friendRequests, currentUser)) {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    } else {
        printf("Masukkan nama pengguna:\n");
        STARTWORD();
        Word friendName = currentWord;

        if (isFriendRequestExist(*friendRequests, currentUser, friendName)) {
            printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
            printWord(friendName);
            printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
        } else {
            PermintaanPertemanan request;
            request.pengirim = currentUser;
            request.penerima = friendName;

            Enqueue(friendRequests, request);
            printf("Permintaan pertemanan kepada ");
            printWord(friendName);
            printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
        }
    }
}

boolean hasPendingFriendRequests(PrioQueue friendRequests, Word user) {
    for (int i = 0; i < friendRequests.size; i++) {
        PermintaanPertemanan request = friendRequests.array[i];
        if (isWordEqual(request.penerima, user)) {
            return TRUE;
        }
    }
    return FALSE;
}

void displayPendingFriendRequests(PrioQueue friendRequests, Word currentUser) {
    if (friendRequests.size > 0) {
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", friendRequests.size);
        for (int i = 0; i < friendRequests.size; i++) {
            PermintaanPertemanan request = friendRequests.array[i];
            printf("\n| ");
            printWord(request.pengirim);
            printf("\n| Jumlah teman: %d\n", jumlah_Teman(matPertemanan, SwindexOf(dataNama, request.pengirim)));
        }
    } else {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
}

void processFriendRequest(PrioQueue* friendRequests, Word currentUser) {
    if (friendRequests->size > 0) {
        PermintaanPertemanan request = Dequeue(friendRequests);

        printf("Permintaan pertemanan teratas dari ");
        printWord(request.pengirim);
        printf("\n- ");
        printWord(request.pengirim);

        printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
        STARTWORD();

        if (isWordEqualString(currentWord, "YA")) {
            printf("Permintaan pertemanan dari ");
            printWord(request.pengirim);
            printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
            printWord(request.pengirim);
            printf(".\n");
            int id_teman = SwindexOf(dataNama, request.penerima);
            int id_user = SwindexOf(dataNama, currentUser);
            AddEdge(&matPertemanan, id_teman, id_user);
        } else {
            printf("Permintaan pertemanan dari ");
            printWord(request.pengirim);
            printf(" telah ditolak.\n");
        }
    } else {
        printf("Tidak ada permintaan pertemanan yang dapat disetujui.\n");
    }
}