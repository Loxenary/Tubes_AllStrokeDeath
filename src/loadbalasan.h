#ifndef LOAD_BALASAN_H
#define LOAD_BALASAN_H

#include "./adt/wordmachine.h"
#include "./adt/datetime.h"

#define MaxKicau 100
#define MaxBalasan 100

typedef struct {
    int kicauBalas;   // Banyak kicauan yang memiliki balasan
    int idKicau;            // ID kicauan
    int banyakBalasan; // Banyak balasan yang diterima
    int idParent;      // ID parent, -1 jika tidak memiliki parent
    int idBalasan;     // ID balasan
    Word teksBalasan;  // Teks balasan
    Word penulis;      // Penulis balasan
    DATETIME dates; // Waktu balasan
} Balasan;

// void ReadBalasanData(char* filename, Balasan *balasan);

#endif