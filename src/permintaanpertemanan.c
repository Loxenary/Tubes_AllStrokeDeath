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

void sendFriendRequest(PrioQueue* friendRequests, Word currentUser, int banyak_pengguna) {
    if (hasPendingFriendRequests(*friendRequests, currentUser)) {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
    } else {
        printf("Masukkan nama pengguna:\n");
        Word friendName = MultipleInput();

        // Check if the entered friend's name is not empty and not the same as the current user
        if (friendName.Length == 0) {
            printf("Nama pengguna tidak boleh kosong.\n");
        } else if (isWordEqual(friendName, currentUser)) {
            printf("Anda tidak dapat mengirim permintaan pertemanan kepada diri sendiri.\n");
        } else {
            int friendIndex = SwindexOf(dataNama, friendName);

            // Check if the user is found in the database
            if (friendIndex != -1) {
                // Initialize the request structure
                PermintaanPertemanan request;
                request.pengirim = currentUser;
                request.penerima = friendName;

                // Enqueue the request
                Enqueue(friendRequests, request);
                printf("Permintaan pertemanan kepada ");
                printWord(friendName);
                printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
            } else {
                printf("Pengguna bernama ");
                printWord(friendName);
                printf(" tidak ditemukan.\n");
            }
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
    if (friendRequests.size == 0) {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    } else {
        printf("Berikut adalah daftar permintaan pertemanan yang belum Anda setujui:\n");
        for (int i = 0; i < friendRequests.size; i++) {
            PermintaanPertemanan request = friendRequests.array[i];
            if (isWordEqual(request.penerima, currentUser)) {
                printf("%d. ", i + 1);
                printWord(request.pengirim);
                printf("\n");
            }
        }
    }
}

void processFriendRequest(PrioQueue* friendRequests, Word currentUser) {
    printf("Masukkan nama pengguna yang ingin Anda terima pertemanannya:\n");
    Word friendName = MultipleInput();

    if (friendRequests->size > 0) {
        PermintaanPertemanan request = Dequeue(friendRequests);
        if (isWordEqual(request.penerima, currentUser) && isWordEqual(request.pengirim, friendName)) {
            printf("Permintaan pertemanan teratas dari ");
            printWord(request.pengirim);
            printf("\n| Jumlah teman: %d\n", jumlah_Teman(matPertemanan, SwindexOf(dataNama, request.pengirim)));

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
            printf("Permintaan pertemanan tidak valid atau berasal dari Anda sendiri atau nama pengguna yang salah.\n");
        }
    } else {
        printf("Tidak ada permintaan pertemanan yang dapat disetujui.\n");
    }
}
