#include <stdio.h>
#include <string.h>
#include "utas.h"

void loadUtas(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file utas.\n");
        return;
    }
    printf("Berhasil membuka file utas.\n");
    // Utas utas;
    // while (fread(&utas, sizeof(Utas), 1, file) == 1) {
    //     printf("Text: %s\n", utas.text);
    //     printf("Author: %s\n", utas.author);
    //     printf("Datetime: %s\n", utas.datetime);
    // }

    fclose(file);
}