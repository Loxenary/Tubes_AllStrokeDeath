#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "listDinUtasan.h"
#include "utas.h"

// var global belum di inisialisasi



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

boolean isUtasID(int idx){
    boolean found = FALSE;
    int count = 0;
    while(count < NEFF_LDU(utas_pointers)){
        if(count + 1 == idx){ // count + 1 karena idutas mulai dari 1
            return TRUE;
        }
        count ++;
    }
    return found;
}



kicauan getKicau(int index){
    return(KELMT(list_kicau,index-1));
}

void CreateRootUtas(int idKicau){
    // kamus
    Address utas_utama;
    Word text;
    kicauan kicau_utama;
    // char * YA = "YA";
    char * TIDAK = "TIDAK";
    // algoritma
    if(isId(idKicau)){
        kicau_utama = getKicau(idKicau);
        if(isWordEqual(kicau_utama.Auth, SELMT(dataNama, current_id))){
            if(kicau_utama.next_Utas == NULL){
                // kicau belum pernah diutas
                // kicauan milik pengguna saat ini
                printf("Utas berhasil dibuat!\n");
                printf("\n");
                printf("Masukkan kicauan:\n");
                
                // inisialisasi linked list
                utas_utama = kicau_utama.next_Utas;
                CreateUtas(&utas_utama);

                // masukin pointer utas ke list dinamis
                
                // input kicauan utas
                text = MultipleInput();
                addUtas(&utas_utama, listLengthDinUtas(utas_pointers)+1, kicau_utama.id, text, kicau_utama.Auth, ExtractLocalTimes());

                insertLastDinUtas(&utas_pointers, utas_utama);
                // if(isEmptyDinUtas(utas_pointers)){
                //     printf("listdin kosong\n");
                // }
                // for(int i = 0; i < listLengthDinUtas(utas_pointers); i++){
                //     printf("isi: %d\n", ELMTD_LDU(utas_pointers, i)->IdUtas);
                // }
                
                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                STARTWORD();
                while(!isWordEqualString(currentWord, TIDAK)){
                    printf("Masukkan kicauan:\n");

                    text = MultipleInput();
                    // buat node baru. idutas, idkicau, auth sama dengan sebelumnya
                    addUtas(&utas_utama, listLengthDinUtas(utas_pointers), kicau_utama.id, text, kicau_utama.Auth, ExtractLocalTimes());

                    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                    STARTWORD();
                }
                printf("Utas selesai!\n");
            } else{
                // kicau pernah diutas
                printf("Kicau ini sudah pernah diutas sebelumnya\n");
            }
        } else{
            // kicauan bukan miliki pengguna saat ini
            printf("Utas ini bukan milik anda!\n");
        }
    } else{
        // id kicau tidak ditemukan
        printf("Kicauan tidak ditemukan\n");
    }
}

void DeleteUtas(int idUtas, int indexUtas){
    // kamus
    Address Utasan;
    // algoritma
    if(isUtasID(idUtas)){
        // idutas ada pada list dinamis
        Utasan = ELMTD_LDU(utas_pointers, idUtas-1);
        // cek apakah author sesuai
        if(isWordEqual(Utasan->Author, SELMT(dataNama, current_id))){
            // pengguna saat ini sesuai dengan author utas
            if(indexUtas <=(length_LinkedUtas(Utasan))){
                // indexutas valid
                if(indexUtas == 0){
                    printf("Anda tidak bisa menghapus kicauan\n");
                    printf("utama\n");
                } else if(indexUtas == 1){
                    // hapus utas
                    address x = Utasan->NextAdress;
                    KELMT(list_kicau, Utasan->Idkicau).next_Utas = x;
                    ELMTD_LDU(utas_pointers, idUtas-1) = x;
                } else{
                    deleteAt_LinkedUtas(Utasan, indexUtas);
                }
            } else{
                // indeks terlalu tinggi
                printf("Kicauan sambungan dengan indeks %d\n", indexUtas);
                printf("tidak ditemukan pada utas!");
            }
        } else{
            // pengguna saat ini tidak sesuai dengan author utas
            printf("Anda tidak bisa menghapus kicauan\n");
            printf("dalam utas ini!\n");
        }

    } else{
        // idutas tidak ada pada list dinamis
        printf("Utas tidak ditemukan\n");
    }
}

void SambungUtas(int idUtas, int indexUtas){
    // kamus
    Word txt;
    Address Utasan;
    
    // algoritma
    // cek apakah idUtas valid ada pada list
    if(isUtasID(idUtas)){
        // id utas ada di list dinamis
        Utasan = ELMTD_LDU(utas_pointers, idUtas - 1);

        if(isWordEqual(Utasan -> Author, SELMT(dataNama, current_id))){
            // pengguna saat ini adalah author utas
            if(indexUtas <= (length_LinkedUtas(Utasan))){
                if(indexUtas == 1){
                    printf("Masukkan kicauan:\n");
                    txt = MultipleInput();
                    // printf("test\n");
                    Address y = newUtas(idUtas, Utasan->Idkicau, txt, Utasan->Author, ExtractLocalTimes());
                    NEXT(y) = Utasan;

                    KELMT(list_kicau, utas_pointers.buffer[idUtas-1]->Idkicau).next_Utas = y;
                    utas_pointers.buffer[idUtas-1] = y;

                } else{
                        // semua kondisi terpenuhi untuk sambung utas
                    // input kicauan
                    printf("Masukkan kicauan:\n");
                    txt = MultipleInput();
                    // printf("test\n");

                    insertAt_LinkedUtas(ELMTD_LDU(utas_pointers, idUtas - 1), idUtas, Utasan->Idkicau, indexUtas, txt, Utasan->Author, ExtractLocalTimes());
                }
                
            } else{
                // indexutas yang dimasukkan terlalu tinggi
                printf("Index terlalu tinggi!\n");
            }
        } else{
            // pengguna saat ini tidak sesuai dengan author utas
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
    } else{
        // id utas tidak ada di list dinamis
        printf("Utas tidak ditemukan!\n");
    }
}

void CetakUtas(ListUtas u){
    // kamus
    Address p;
    kicauan kicauan_utama;
    int count;
    // algoritma
    if(u == NULL){
        printf("Kosong");
    } else{

        p = u;

        kicauan_utama = getKicau(p->Idkicau);
        count = 1;

        printf("| ID = %d\n", p->Idkicau);
        printf("| ");
        printWord(p->Author);
        printf("\n");
        printf("| ");
        TulisDATETIME(kicauan_utama.dates);
        printf("\n");
        printf("| ");
        printWord(kicauan_utama.Text);
        printf("\n");

        while((p) != NULL){
            
            printf("    | INDEX = %d\n", count);
            printf("    | ");
            printWord(p->Author);
            printf("\n");
            printf("    | ");
            TulisDATETIME(p->dateTime);
            printf("\n");
            printf("    | ");
            printWord(p->texts);
            printf("\n");
            printf("\n");
            
            count ++;
            p = NEXT(p);

            
        }
    }
    
}


// harus buat fungsi-fungsi linked list yang diperlukan untuk utas. alur: id sesuai, author sesuai. create node baru. node ini seperti linked list pada umumnya, ada next address, ada info.
// buat linked list utas dari index nol. di index nol itu nyimpen utas utama.
// index selanjutnya nyimpen sambungan dari utasan tersebuts.