#include <stdio.h>
#include <string.h>
#include "pengguna.h"
#include "kicauan.h"
#include "balasan.h"
#include "draf.h"
#include "utas.h"

void displayScreen() {
    printf("baby shark doo doo doo doo doo doo\n");
    printf("baby shark doo doo doo doo doo doo\n");
    printf("baby shark\n");
    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi ini sangat mirip dengan Twitter.\n");
}

void inisialisasiAplikasi() {
    char folder[100];
    printf("Silahkan masukkan folder konfigurasi untuk dimuat: ");
    scanf("%s", folder);

    // Inisialisasi dengan folder konfigurasi
    char penggunaConfigFile[200];
    char kicauanConfigFile[200];
    char balasanConfigFile[200];
    char drafConfigFile[200];
    char utasConfigFile[200];

    // Membangun jalur lengkap untuk setiap berkas konfigurasi
    snprintf(penggunaConfigFile, sizeof(penggunaConfigFile), "%s/pengguna.config", folder);
    snprintf(kicauanConfigFile, sizeof(kicauanConfigFile), "%s/kicauan.config", folder);
    snprintf(balasanConfigFile, sizeof(balasanConfigFile), "%s/balasan.config", folder);
    snprintf(drafConfigFile, sizeof(drafConfigFile), "%s/draf.config", folder);
    snprintf(utasConfigFile, sizeof(utasConfigFile), "%s/utas.config", folder);

    // Memuat berkas konfigurasi
    loadPengguna(penggunaConfigFile);
    loadKicauan(kicauanConfigFile);
    loadBalasan(balasanConfigFile);
    loadDraf(drafConfigFile);
    loadUtas(utasConfigFile);

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");
}