#include <stdio.h>
#include "utas.h"

void loadUtas(char filename[200]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file utas.\n");
        return;
    }
    printf("Berhasil membuka file utas.\n");

    // Utas utas;
    // size_t maxTextLength = sizeof(utas.text) - 1;  // Menghindari buffer overflow

    // while (fread(&utas, sizeof(Utas), 1, file) == 1) {
    //     // Membaca dan mencetak teks secara manual tanpa %s
    //     printf("Text: ");
    //     for (size_t i = 0; i < maxTextLength; i++) {
    //         if (utas.text[i] == '\0') {
    //             break;
    //         }
    //         putchar(utas.text[i]);
    //     }
    //     printf("\n");

    //     // Membaca dan mencetak penulis secara manual tanpa %s
    //     printf("Author: ");
    //     for (size_t i = 0; i < sizeof(utas.author) - 1; i++) {
    //         if (utas.author[i] == '\0') {
    //             break;
    //         }
    //         putchar(utas.author[i]);
    //     }
    //     printf("\n");

    //     // Membaca dan mencetak tanggal dan waktu secara manual tanpa %s
    //     printf("Datetime: ");
    //     for (size_t i = 0; i < sizeof(utas.datetime) - 1; i++) {
    //         if (utas.datetime[i] == '\0') {
    //             break;
    //         }
    //         putchar(utas.datetime[i]);
    //     }
    //     printf("\n");
    // }

    fclose(file);
}