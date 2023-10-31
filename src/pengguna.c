#include <stdio.h>
#include "pengguna.h"

void loadPengguna(char filename[200]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file pengguna.\n");
        return;
    }
    printf("Berhasil membuka file pengguna.\n");

    int numUsers;
    if (fscanf(file, "%d", &numUsers) != 1) {
        printf("Gagal membaca jumlah pengguna.\n");
        fclose(file);
        return;
    }

    // Pengguna pengguna;

    // for (int i = 0; i < numUsers; i++) {
    //     if (fscanf(file, "%49s", pengguna.nama) != 1) {
    //         printf("Gagal membaca nama pengguna.\n");
    //         fclose(file);
    //         return;
    //     }

    //     if (fscanf(file, "%49s", pengguna.password) != 1) {
    //         printf("Gagal membaca password.\n");
    //         fclose(file);
    //         return;
    //     }

    //     if (fscanf(file, "%199s", pengguna.bio) != 1) {
    //         printf("Gagal membaca bio.\n");
    //         fclose(file);
    //         return;
    //     }

    //     if (fscanf(file, "%19s", pengguna.nomor_hp) != 1) {
    //         printf("Gagal membaca nomor HP.\n");
    //         fclose(file);
    //         return;
    //     }

    //     if (fscanf(file, "%19s", pengguna.weton) != 1) {
    //         printf("Gagal membaca weton.\n");
    //         fclose(file);
    //         return;
    //     }

    //     if (fscanf(file, "%19s", pengguna.jenis_akun) != 1) {
    //         printf("Gagal membaca jenis akun.\n");
    //         fclose(file);
    //         return;
    //     }

    //     for (int j = 0; j < 10; j++) {
    //         for (int k = 0; k < 10; k++) {
    //             char foto;
    //             if (fscanf(file, " %c", &foto) != 1) {
    //                 printf("Gagal membaca foto profil.\n");
    //                 fclose(file);
    //                 return;
    //             }
    //             pengguna.foto_profil[j][k] = foto;
    //         }
    //     }

    // }

    fclose(file);
}