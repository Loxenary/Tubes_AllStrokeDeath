#include "../src/ADT/wordmachine.h"

int main() {
    printf("==========Hello, World!============\n");
    printf("Input 1 kata: ");
    STARTWORD();
    printf("Kata yang diinput: ");
    printWord(currentWord);
    printf("\n");
    printf("Input 2 kata: ");
    ADVLINE();
    printf("Kata yang diinput: ");
    printWord(currentWord);
    printf("\n");

    printf("========Baca File========\n");
    printf("Input nama file: ");
    // membaca file pengguna.config dengan startfileword
    STARTFILEWORD("kicauan.config");
    int jumlah_kicau = toInt(currentWord);
    printf("Jumlah pengguna: %d\n", jumlah_kicau);
    int i;
    for (i = 0; i < jumlah_kicau; i++) {
        // baca id kicauan
        ADVWORD();
        printf("ID kicauan: ");
        printWord(currentWord);
        printf("\n");
        // baca text kicau
        ADVLINE();
        printf("Text kicauan: ");
        printWord(currentWord);
        printf("\n");
        // baca jumlah like
        ADVWORD();
        printf("Jumlah like: ");
        printWord(currentWord);
        printf("\n");
        // baca author
        ADVLINE();
        printf("Author: ");
        printWord(currentWord);
        printf("\n");
        // baca waktu kicau
        ADVLINE();
        printf("Waktu kicau: ");
        printWord(currentWord);
        printf("\n");
    }

    return 0;
}