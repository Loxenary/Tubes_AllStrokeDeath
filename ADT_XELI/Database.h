#include <stdio.h>
#include <stdlib.h>
#include "listDinWord.h"
#include "wordmachine.h"
#include "adjacency_Matrix.h"
#include "listStatikWord.h"
#include "stack.h"
#include "listdin.h"
#include "liststatik.h"
#include "matrix.h"
#include "liststatikstack.h"
#include "kicau.h"


// #include "matrix.h"

//General
extern int wrdCapacity;

//Config Pengguna
extern int current_id;
extern int banyak_pengguna;
extern boolean isLogin;
extern ListStatikWord dataNama;
extern ListStatikWord password;
extern ListStatikWord bio;
extern ListStatikWord phone;
extern ListStatikWord Weton;
extern ListStatik JenisAkun;
extern Matrix profile;
extern AdjMatrix matPertemanan;
extern int addFriendCounter;
extern Matrix matTambahTeman;

//Config Kicauan
extern int jumlah_kicau;
extern ListKicau list_kicau;

//Config Balesan
extern int jumlah_balasan;
extern ListDin id_kicau;
//Tree untuk Balasan

//Config Draf
extern int jumlah_Draf;
extern ListStatikStack draf;

//Config Utas
extern int jumlah_utas;
// Typedef yang berisi id Utas, dan linked Listnya