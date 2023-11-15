#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "Kicau.h"
#include "ListUtas.h"


Word kicauan_utas;
ListUtas list_utas;

void CreateRootUtas(int idKicau){
    // kamus
    Address utas_utama;
    Word text;
    kicauan kicau_utama;
    char * YA = "YA";
    char * TIDAK = "TIDAK";
    // algoritma
    if((isId(idKicau))){
        kicau_utama = getKicau(idKicau);
        if(isWordEqual(kicau_utama.Auth, SELMT(dataNama, current_id))){
            
            // kicauan milik pengguna saat ini
            printf("Utas berhasil dibuat!\n");
            printf("\n");
            printf("Masukkan kicauan:\n");
            
            // inisialisasi linked list
            utas_utama = kicau_utama.next_Utas;
            CreateUtas(&utas_utama);
            
            // input kicauan utas
            text = MultipleInput();
            addUtas(&utas_utama, text, kicau_utama.Auth, ExtractLocalTimes());

            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            STARTWORD();
            while(!isWordEqualString(currentWord, TIDAK)){
                printf("Masukkan kicauan:\n");

                text = MultipleInput();

                addUtas(&utas_utama, text, kicau_utama.Auth, ExtractLocalTimes());

                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                STARTWORD();
            }
            printf("Utas selesai!\n");
        } else{
            // kicauan bukan miliki pengguna saat ini
            printf("Utas ini bukan milik anda!\n");
        }
    } else{
        // id kicau tidak ditemukan
        printf("Kicauan tidak ditemukan\n");
    }
}

void DeleteUtas(int idKicau, int indexUtas){
    
}

void SambungUtas(int idUtas, int indexUtas){

}

void CetakUtas(){

}

boolean isId(int index){
    boolean found = FALSE;
    int idx = 0;
    while(idx < KNEFF(list_kicau)){
        if((KELMT(list_kicau, idx).id) == index){
            found = TRUE;
            break;
        }
        idx ++;
    }
    return found;
}


kicauan getKicau(int index){
    return(KELMT(list_kicau,index));
}

// harus buat fungsi-fungsi linked list yang diperlukan untuk utas. alur: id sesuai, author sesuai. create node baru. node ini seperti linked list pada umumnya, ada next address, ada info.
// buat linked list utas dari index nol. di index nol itu nyimpen utas utama.
// index selanjutnya nyimpen sambungan dari utasan tersebuts.