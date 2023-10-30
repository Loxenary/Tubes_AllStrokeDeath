#include <stdio.h>
#include <string.h>
#include "pengguna.h"

void loadPengguna(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file pengguna.\n");
        return;
    }
    printf("Berhasil membuka file pengguna.\n");

    // int numUsers;
    // fscanf(file, "%d", &numUsers); // Baca jumlah pengguna

    // for (int i = 0; i < numUsers; i++) {
    //     Pengguna pengguna;

    //     fscanf(file, "%s", pengguna.nama); // Baca nama
    //     fscanf(file, "%s", pengguna.password); // Baca password
    //     fscanf(file, "%s", pengguna.bio); // Baca bio
    //     fscanf(file, "%s", pengguna.nomor_hp); // Baca nomor HP
    //     fscanf(file, "%s", pengguna.weton); // Baca weton
    //     fscanf(file, "%s", pengguna.jenis_akun); // Baca jenis akun

    //     for (int j = 0; j < 10; j++) {
    //         for (int k = 0; k < 10; k++) {
    //             char foto;
    //             fscanf(file, " %c", &foto);
    //             pengguna.foto_profil[j][k] = foto; // Baca foto profil
    //         }
    //     }

        // Sekarang Anda dapat melakukan sesuatu dengan data pengguna, misalnya, menyimpannya dalam array atau struktur data.
    // }

    fclose(file);
}