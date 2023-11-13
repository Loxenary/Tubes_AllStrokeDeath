#include <stdio.h>
#include "kicau.h"
#include "database.h"


void CreateListKicau(ListKicau *l, int Capacity)
{
    KBUFFER(*l) = (kicauan*)malloc(KCAPACITY(l)*sizeof(kicauan));
    KNEFF(*l) = 0;
    KCAPACITY(l) = Capacity;
}


void inputKicau(ListKicau l)
{
    printf("Masukkan kicauan:\n");
    Word text = MultipleInput();
    // printf("%d",text.Length);
    if(text.Length == 0){
        printf("Kicauan tidak boleh hanya berisi\n");
        printf("spasi!\n");
    }
    else{
        InsertNewLastKicau(&l, text);
        printf("\n");
        printf("Selamat! kicauan telah\n");
        printf("diterbitkan!\n");
        printf("Detil kicauan: \n");
        printDataKicauan(KELMT(l,KNEFF(l)-1));
    }
    
}

void DisplayKicauan(ListKicau l){
    Word user =SELMT(dataNama,current_id);
    int i;
    for(i = 0; i < KNEFF(l); i++){
        kicauan temp = KELMT(l,i);
        Word wTemp = temp.Auth;
        
        if(isWordEqual(user,wTemp)){
            printDataKicauan(temp);
        }
    }
}

void printDataKicauan(kicauan k){
    printf("| ID = %d",k.id);
    printf("\n| ");
    printWord(k.Auth);
    printf("\n| ");
    TulisDATETIME(k.dates);
    printf("\n| ");
    printWord(k.Text);
    printf("\n| Disukai: %d",k.Likes);
    printf("\n");
}

void sukaKicauan(int idKicau, ListKicau l){
    if(idKicau > KNEFF(l)){
        printf("Tidak ditemukan kicauan dengan ID = %d",idKicau);
    }
    else{
        Word data = KELMT(l,idKicau).Auth;
        int indexNama = SwindexOf(dataNama,KELMT(l,idKicau).Auth);
        //Jika 2 orang tersebut berteman atau akun yang dicari public
        if(isTeman(matPertemanan, data, SELMT(dataNama,indexNama)) || (ELMT(JenisAkun,indexNama) == 1)){
            printf("Selamat! kicauan telah disukai!\n");
            KELMT(l,idKicau).Likes++;
            printf("Detil kicauan: \n");
            printDataKicauan(KELMT(l,idKicau));
        }
        else{
            printf("Wah, kicauan tersebut dibuat oleh\n");
            printf("akun privat! tambah teman akun itu dulu\n");
            printf("ya");
        }
        
    }
}

void InsertNewLastKicau(ListKicau *l, Word Word)
{
    jumlah_kicau++;
    kicauan temp;
    KAUTH(&temp) = SELMT(dataNama,current_id);
    KID(&temp) = jumlah_kicau;
    KLIKE(&temp) = 0;
    KDATE(&temp) = ExtractLocalTimes();
    KTEXT(&temp) = Word;
    KNEFF(*l)++;
    KELMT(*l,NEFF(*l)-1) = temp;

}

kicauan CreateDefinedKicau(Word author, Word text, int Likes, DATETIME dates, int id)
{
    kicauan temps;
    KID(&temps) = id;
    KAUTH(&temps) = author;
    KLIKE(&temps) = Likes;
    KDATE(&temps) = dates;
    KTEXT(&temps) = text;
    return temps;
}

void InsertDeclaredLastKicau(ListKicau *l, kicauan kicau){
    KNEFF(*l)++;
    jumlah_kicau++;
    KELMT(*l,NEFF(*l)-1) = kicau;
}

void ubah_kicauan(int idKicau, ListKicau l)
{
    if(idKicau > KNEFF(l)){
        printf("Tidak ditemukan kicauan dengan ID = %d",idKicau);
    }
    else{
        Word user_find = KELMT(l,idKicau).Auth;
        if(isWordEqual(user_find,SELMT(dataNama,current_id))){
            printf("Masukan kicauan baru: \n");
            KELMT(l,idKicau).Text = MultipleInput();
            KELMT(l,idKicau).dates = ExtractLocalTimes();
            printf("Selamat! kicauan telah diterbitkan! \n");
            printf("Detil kicauan: \n");
            printDataKicauan(KELMT(l,idKicau));
        }
        else{
            printf("Kicauan dengan ID = %d bukan\n",idKicau);
            printf("milikmu!");
        }
    }
}