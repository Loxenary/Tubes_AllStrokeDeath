#include <stdio.h>
#include <stdlib.h>
#include "load.h"

void displayScreen() {
    char text[] = "baby shark doo doo doo doo doo doo\n";
    printf("%s", text);
    printf("%s", text);
    printf("baby shark\n");
    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi ini sangat mirip dengan Twitter.\n");
    printf("\n");
}

void inisialisasiAplikasi() {
    char folder[100];
    printf("Silahkan masukkan folder konfigurasi untuk dimuat: ");
    scanf("%s", folder);

    // Cek apakah folder "config" ada dalam folder "src"
    char configFolderPath[200];
    snprintf(configFolderPath, sizeof(configFolderPath), "%s/", folder);

    // Buat nama file konfigurasi pengguna dan kicauan berdasarkan folder yang diinput
    char userConfigFile[256];  // Nama file konfigurasi pengguna
    char kicauConfigFile[256]; // Nama file konfigurasi kicauan

    // Buat path lengkap ke file-file konfigurasi
    snprintf(userConfigFile, sizeof(userConfigFile), "%spengguna.config", configFolderPath);
    snprintf(kicauConfigFile, sizeof(kicauConfigFile), "%skicauan.config", configFolderPath);

    User users[MAX_USERS];
    FriendshipStatus friendshipStatus;
    ListKicau kicauList;
    int numUsers = 0;  // Deklarasikan dan inisialisasikan numUsers

    // Memuat data pengguna dari file konfigurasi
    LoadUser(users, &numUsers, &friendshipStatus, userConfigFile);

    // Memuat data kicauan dari file konfigurasi
    LoadKicau(&kicauList, kicauConfigFile);

    // Lakukan operasi lain sesuai kebutuhan
    // ...

    printf("Data berhasil dimuat dari folder konfigurasi: %s\n", folder);
}
void LoadUser(User* users, int* numUsers, FriendshipStatus* friendshipStatus, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    // Initialize the word machine
    STARTWORD();
    *numUsers = 0;

    // Loop to read user data
    while (!EndWord) {
        // Check if there's room for more users
        if (*numUsers >= MAX_USERS) {
            printf("Error: Maximum number of users reached.\n");
            break;
        }

        // Read user data
        Name(users[*numUsers]) = currentWord;
        ADVWORD();
        Password(users[*numUsers]) = currentWord;
        ADVWORD();
        Bio(users[*numUsers]) = currentWord;
        ADVWORD();
        Phone(users[*numUsers]) = currentWord;
        ADVWORD();
        Weton(users[*numUsers]) = currentWord;
        ADVWORD();
        IsPrivate(users[*numUsers]) = currentWord;

        // Read profile picture
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                Profile(users[*numUsers], i, j) = currentChar;
                ADV();
            }
            ADV();
        }

        // Increase the number of users
        (*numUsers)++;

        // Check if there are more words to read
        if (EndWord)
            break;

        // Read the next word
        STARTWORD();
    }

    // Read the friendship status data
    if (!EndWord) {
        ADVWORD();
        for (int i = 0; i < *numUsers; i++) {
            for (int j = 0; j < *numUsers; j++) {
                AdjacencyMatrix(*friendshipStatus)[i][j] = currentChar - '0';
                ADV();
            }
            ADV();
        }
    }

    fclose(file);
}

void LoadKicau(ListKicau* kicauList, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    int nKicauan;
    fscanf(file, "%d", &nKicauan); // Read the number of kicauans
    fgetc(file); // Read newline

    kicauList->nEff = nKicauan;

    for (int i = 0; i < nKicauan; i++) {
        KID(&KBUFFER(*kicauList)[i]) = i + 1; // ID is auto-increment starting from 1

        // Read Text
        STARTWORD();
        while (!EndWord) {
            ADVWORD();
            if (!EndWord) {
                CopyWord(currentWord, &KTEXT(&KBUFFER(*kicauList)[i]));
            }
        }

        // Read Likes
        int tempLikes;
        fscanf(file, "%d", &tempLikes);
        KLIKE(&KBUFFER(*kicauList)[i]) = tempLikes;
        fgetc(file); // Read newline

        // Read Author
        STARTWORD();
        while (!EndWord) {
            ADVWORD();
            if (!EndWord) {
                CopyWord(currentWord, &KAUTH(&KBUFFER(*kicauList)[i]));
            }
        }

        // Read Datetime
        char datetimeStr[20];
        fscanf(file, "%s", datetimeStr);
        // KDATE(&KBUFFER(*kicauList)[i]) = DetikToTIME(atoi(datetimeStr));
        fgetc(file); // Read newline
    }

    fclose(file);
}