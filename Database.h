#include <stdio.h>
#include <stdlib.h>
#include "ListDinWord.h"
#include "ListStatikWord.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "boolean.h"
#include "Adjacency_Matrix.h"
#include "matrix.h"
#include "listdin.h"
#include "stack.h"
#include "queue.h"
#include "datetime.h"
#include "Kicau.h"
#include "liststatik.h"
#include "teman.h"

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
ListKicau list_kicau;


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
