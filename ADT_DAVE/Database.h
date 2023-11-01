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


// #include "matrix.h"

//Config Pengguna
int current_id;
int banyak_pengguna;
boolean isLogin;
ListStatikWord dataNama;
ListStatikWord password;
ListStatikWord bio;
ListStatikWord phone;
ListStatikWord Weton;
ListStatikWord JenisAkun;
//Foto Profile
AdjMatrix matPertemanan;
int addFriendCounter;
Matrix matTambahTeman;

//Config Kicauan
int jumlah_kicau;
ListWord TextKicau;
ListDin likes;
ListWord Authors;
ListWord Tagar;

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
