#include <stdio.h>
#include "pengguna.h"
#include "kicauan.h"
#include "balasan.h"
#include "draf.h"
#include "utas.h"

void displayScreen() {
    char text[] = "baby shark doo doo doo doo doo doo\n";
    printf("%s", text);
    printf("%s", text);
    printf("baby shark\n");
    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi ini sangat mirip dengan Twitter.\n");
}

void inisialisasiAplikasi() {
    char folder[100];
    printf("Silahkan masukkan folder konfigurasi untuk dimuat: ");
    scanf("%s", folder);

    // Inisialisasi berkas konfigurasi
    char penggunaConfigFile[200];
    char kicauanConfigFile[200];
    char balasanConfigFile[200];
    char drafConfigFile[200];
    char utasConfigFile[200];


    char pathSeparator = '/';
    char fileExtension[] = ".config";

    snprintf(penggunaConfigFile, sizeof(penggunaConfigFile), "%s%c%s%s", folder, pathSeparator, "pengguna", fileExtension);
    snprintf(kicauanConfigFile, sizeof(kicauanConfigFile), "%s%c%s%s", folder, pathSeparator, "kicauan", fileExtension);
    snprintf(balasanConfigFile, sizeof(balasanConfigFile), "%s%c%s%s", folder, pathSeparator, "balasan", fileExtension);
    snprintf(drafConfigFile, sizeof(drafConfigFile), "%s%c%s%s", folder, pathSeparator, "draf", fileExtension);
    snprintf(utasConfigFile, sizeof(utasConfigFile), "%s%c%s%s", folder, pathSeparator, "utas", fileExtension);

    // Memuat berkas konfigurasi
    loadPengguna(penggunaConfigFile);
    loadKicauan(kicauanConfigFile);
    loadBalasan(balasanConfigFile);
    loadDraf(drafConfigFile);
    loadUtas(utasConfigFile);

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");
}