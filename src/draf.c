#include <stdio.h>
#include "draf.h"

void loadDraf(char filename[200]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file draf.\n");
        return;
    }
    printf("Berhasil membuka file draf.\n");

    fclose(file);
}