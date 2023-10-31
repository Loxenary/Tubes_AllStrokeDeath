#include <stdio.h>
#include "kicauan.h"

void loadKicauan(char filename[200]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file kicauan.\n");
        return;
    }
    printf("Berhasil membuka file kicauan.\n");

    // Kicauan kicauan;
    // size_t maxTextLength = sizeof(kicauan.text) - 1;
    // while (fread(&kicauan, sizeof(Kicauan), 1, file) == 1) {
    //     printf("ID: %d\n", kicauan.id);
        
    //     printf("Text: ");
    //     for (size_t i = 0; i < maxTextLength; i++) {
    //         if (kicauan.text[i] == '\0') {
    //             break;
    //         }
    //         putchar(kicauan.text[i]);
    //     }
    //     printf("\n");

    //     printf("Like: %d\n", kicauan.like);

    //     printf("Author: ");
    //     for (size_t i = 0; i < sizeof(kicauan.author) - 1; i++) {
    //         if (kicauan.author[i] == '\0') {
    //             break;
    //         }
    //         putchar(kicauan.author[i]);
    //     }
    //     printf("\n");

    //     printf("Datetime: ");
    //     for (size_t i = 0; i < sizeof(kicauan.datetime) - 1; i++) {
    //         if (kicauan.datetime[i] == '\0') {
    //             break;
    //         }
    //         putchar(kicauan.datetime[i]);
    //     }
    //     printf("\n");
    // }

    fclose(file);
}