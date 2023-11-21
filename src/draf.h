#ifndef DRAF_H
#define KICAU_H

#include "Database.h"
#include "charmachine.h"
#include "wordmachine.h"

void buatDraf(WrdType nama);
/*berfungsi untuk membuat draf yang baru*/

int lihatDraf(WrdType nama);
/*  berfungsi memanggil draf yang sudah pernah dibuat paling baru.
    jika kosong, maka akan ada output peringatan*/

#endif