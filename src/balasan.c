#include <stdio.h>
#include "balasan.h"

void loadBalasan(char filename[200]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file balasan.\n");
        return;
    }
    printf("Berhasil membuka file balasan.\n");

    // Balasan balasan;
    // size_t maxTextLength = sizeof(balasan.text) - 1;

    // while (fread(&balasan, sizeof(Balasan), 1, file) == 1) {
    //     printf("ID Parent: %d\n", balasan.id_parent);
    //     printf("ID Balasan: %d\n", balasan.id_balasan);
        

    //     printf("Text: ");
    //     for (size_t i = 0; i < maxTextLength; i++) {
    //         if (balasan.text[i] == '\0') {
    //             break;
    //         }
    //         putchar(balasan.text[i]);
    //     }
    //     printf("\n");


    //     printf("Author: ");
    //     for (size_t i = 0; i < sizeof(balasan.author) - 1; i++) {
    //         if (balasan.author[i] == '\0') {
    //             break;
    //         }
    //         putchar(balasan.author[i]);
    //     }
    //     printf("\n");

    //     printf("Datetime: ");
    //     for (size_t i = 0; i < sizeof(balasan.datetime) - 1; i++) {
    //         if (balasan.datetime[i] == '\0') {
    //             break;
    //         }
    //         putchar(balasan.datetime[i]);
    //     }
    //     printf("\n");
    // }

    fclose(file);
}