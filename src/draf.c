#include <stdio.h>
#include <string.h>
#include "draf.h"

void loadDraf(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file draf.\n");
        return;
    }
    printf("Berhasil membuka file draf.\n");
    // Draf draf;
    // while (fread(&draf, sizeof(Draf), 1, file) == 1) {
    //     printf("ID: %d\n", draf.id);
    //     printf("Text: %s\n", draf.text);
    //     printf("Author: %s\n", draf.author);
    //     printf("Datetime: %s\n", draf.datetime);
    // }

    fclose(file);
}