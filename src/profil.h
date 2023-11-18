#ifndef PROFIL_H
#define PROFIL_H

#include "./adt/charmachine.h"
#include "./adt/wordmachine.h"
#include "./adt/pcolor.h"
void gantiProfil(WrdType nama);
/*bertujuan untuk mengganti profil dari user*/

void lihatProfil(WrdType nama);
/*  melihat profil dari orang yang ditentukan yaitu "nama"
    jika diprivat, maka akan ada output peringatan.*/

void aturJenisAkun(WrdType nama);
/*mengubah jenis akun dari privat -> publik maupun publik -> privat*/

void ubahFotoProfil(WrdType nama);
/*mengubah foto profil dari akun orang yang sedang login*/

boolean cekWeton(Word Weton);

#endif