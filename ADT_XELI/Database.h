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
#include "liststatikmatrixchar.h"
#include "liststatikstack.h"
#include "prioqueue.h"
#include "balasan.h"
#include "kicau.h"


// #include "matrix.h"
//General
extern int wrdCapacity;

//Config Pengguna
extern int current_id;
extern int banyak_pengguna;
extern boolean isLogin;
extern int MaxWordCapacity;
extern ListStatikWord dataNama;
extern ListStatikWord password;
extern ListStatikWord bio;
extern ListStatikWord phone;
extern ListStatikWord Weton;
extern ListStatik JenisAkun;
extern ListStatikMatrix profil;

extern AdjMatrix matPertemanan;
extern int addFriendCounter;
extern PrioQueue permintaanTeman;
//Config Kicauan
extern int jumlah_kicau;
extern ListKicau list_kicau;

//Config Balesan
extern int jumlah_balasan;
extern ListTree list_balasan;
//Tree untuk Balasan

//Config Draf
extern int jumlah_Draf;
extern ListStatikStack draf;
 //List Stack yang isinya 2 word ama dateTime

//Config Utas
extern int jumlah_utas;

// Typedef yang berisi id Utas, dan linked Listnya
