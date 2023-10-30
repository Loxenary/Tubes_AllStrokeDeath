#include <stdio.h>
#include <string.h>
#include "balasan.h"

void loadBalasan(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file balasan.\n");
        return;
    }
    printf("Berhasil membuka file balasan.\n");
    // Balasan balasan;
    // while (fread(&balasan, sizeof(Balasan), 1, file) == 1) {
    //     printf("ID Parent: %d\n", balasan.id_parent);
    //     printf("ID Balasan: %d\n", balasan.id_balasan);
    //     printf("Text: %s\n", balasan.text);
    //     printf("Author: %s\n", balasan.author);
    //     printf("Datetime: %s\n", balasan.datetime);
    // }

    fclose(file);
}