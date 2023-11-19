#include <stdio.h>
#include "./src/perintah.h"
#include "./src/inisialisasi.h"

int main(){
       // displayScreen();
       // inisialisasiAplikasi();
       char folder[250];
       char filename[250];
       loadconfig(folder, filename);
       SwprintList(dataNama);
       SwprintList(password);
       SwprintList(bio);
       SwprintList(phone);
       SwprintList(Weton);
       SprintList(JenisAkun);
       printf("\n");

       perintah();
       
       return 0;
}