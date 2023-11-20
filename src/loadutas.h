#ifndef LOAD_UTAS_H
#define LOAD_UTAS_H

#include "./adt/wordmachine.h"
#include "./adt/datetime.h"

#define MAX_KICAUAN 20
#define MAX_UTAS_PER_KICAUAN 20
#define MAX_TEXT_LENGTH 10000
#define MAX_DATETIME_LENGTH 20


typedef struct {
    int banyak_kicauan;
    int id_kicauan;
    int banyak_utas;
    struct {
        Word text;
        Word author;
        DATETIME datetime;
    } utas[MAX_UTAS_PER_KICAUAN];
} KicauanData;

typedef struct {
    int banyak_kicauan;
    KicauanData kicauans[MAX_KICAUAN];
} DataUtas;

// void ReadUtasData(const char *filename, DataUtas *dataUtas);

#endif