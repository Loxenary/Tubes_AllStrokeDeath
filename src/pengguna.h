#ifndef PENGUNA_H
#define PENGUNA_H

typedef struct {
    char nama[50];
    char password[50];
    char bio[200];
    char nomor_hp[20];
    char weton[20];
    char jenis_akun[20];
    char foto_profil[10][10];
} Pengguna;

void loadPengguna(char *filename);

#endif