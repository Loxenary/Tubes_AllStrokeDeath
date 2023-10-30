#include <stdio.h>
#include <string.h>
#include "kicauan.h"

void loadKicauan(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file kicauan.\n");
        return;
    }
    printf("Berhasil membuka file kicauan.\n");
    // Kicauan kicauan;
    // while (fread(&kicauan, sizeof(Kicauan), 1, file) == 1) {
    //     printf("ID: %d\n", kicauan.id);
    //     printf("Text: %s\n", kicauan.text);
    //     printf("Like: %d\n", kicauan.like);
    //     printf("Author: %s\n", kicauan.author);
    //     printf("Datetime: %s\n", kicauan.datetime);
    // }

    fclose(file);
}