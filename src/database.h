#include <stdio.h>
#include <stdlib.h>
#include "./adt/listDinWord.h"
#include "./adt/wordmachine.h"
#include "./adt/adjacency_Matrix.h"
#include "./adt/listStatikWord.h"
#include "./adt/stack.h"
#include "./adt/listdin.h"
#include "./adt/liststatik.h"
#include "./adt/matrix.h"
#include "./adt/liststatikmatrixchar.h"
#include "./adt/liststatikstack.h"
#include "./adt/prioqueue.h"
#include "utas.h"
#include "ListDinUtasan.h"
#include "balasan.h"
#include "kicau.h"
#include "draf.h"


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
extern ListDinUtas utas_pointers;

extern int kicau_have_utas;
// Typedef yang berisi id Utas, dan linked Listnya
