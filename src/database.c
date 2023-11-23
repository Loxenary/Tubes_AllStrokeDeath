#include "database.h"

int wrdCapacity = 0;
int current_id = 0;
int banyak_pengguna = 0;
boolean isLogin = FALSE;
ListStatikWord dataNama;
ListStatikWord password;
ListStatikWord bio;
ListStatikWord phone;
ListStatikWord Weton;
ListStatik JenisAkun;
ListStatikMatrix profil;

AdjMatrix matPertemanan;
int addFriendCounter;
PrioQueue permintaanTeman;

int jumlah_kicau;
ListKicau list_kicau;

ListDin id_kicau;

//Config Draf
int jumlah_Draf;
ListStatikStack draf;


//Tree untuk Balasan
int jumlah_balasan;
ListTree list_balasan;
ListDin kicau_with_balasan;

int jumlah_utas;
ListDinUtas utas_pointers;

int kicau_have_utas;

