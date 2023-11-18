#include <stdio.h>
#include "./src/perintah.h"
#include "./src/inisialisasi.h"

int main(){
       // displayScreen();
       // inisialisasiAplikasi();
       char folder[250];
       char filename[250];
       loadconfig(folder, filename);
       current_id = 0;
       banyak_pengguna = 0;
       isLogin = FALSE;
       SwCreateListStatik(&dataNama);
       SwCreateListStatik(&password);
       SwCreateListStatik(&bio);
       SwCreateListStatik(&phone);
       SwCreateListStatik(&Weton);
       CreateListStatik(&JenisAkun);
       CreateListStatikMatrix(&profil);
       perintah();
       
       return 0;
}