#ifndef DRAF_H
#define KICAU_H

#include "./adt/wordmachine.h"
#include "kicau.h"
#include "./adt/liststatikstack.h"


void buatDraf(WrdType nama);
/*berfungsi untuk membuat draf yang baru*/

void lihatDraf(WrdType nama);
/*  berfungsi memanggil draf yang sudah pernah dibuat paling baru.
    jika kosong, maka akan ada output peringatan*/

#endif