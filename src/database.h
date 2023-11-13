#include <stdio.h>
#include <stdlib.h>
#include "./adt/listStatikWord.h"
#include "./adt/listDinWord.h"
#include "./adt/adjacency_Matrix.h"
#include "./adt/matrix.h"
#include "./adt/liststatik.h"
#include "./adt/listdin.h"
#include "kicau.h"
// #include "matrix.h"

//General
int wrdCapacity;

//Config Pengguna
int current_id;
int banyak_pengguna;
boolean isLogin;
ListStatikWord dataNama;
ListStatikWord password;
ListStatikWord bio;
ListStatikWord phone;
ListStatikWord Weton;
ListStatik JenisAkun;
Matrix profile;
AdjMatrix matPertemanan;
int addFriendCounter;
Matrix matTambahTeman;

//Config Kicauan
int jumlah_kicau;
ListKicau ListKicauan;


//Config Balesan
int jumlah_balasan;
ListDin id_kicau;
//Tree untuk Balasan

//Config Draf
int jumlah_Draf;
//List Stack yang isinya 2 word ama dateTime

//Config Utas
int jumlah_utas;
// Typedef yang berisi id Utas, dan linked Listnya
