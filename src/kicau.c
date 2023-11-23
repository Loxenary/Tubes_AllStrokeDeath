#include <stdio.h>
#include "kicau.h"
#include "database.h"

void CreateListKicau(ListKicau *l, int Capacity)
{
    KCAPACITY(l) = Capacity;
    KBUFFER(*l) = (kicauan*)malloc(KCAPACITY(l)*sizeof(kicauan));
    KNEFF(*l) = 0;
}


void inputKicau(ListKicau * l)
{
    printf("Masukkan kicauan:\n");
    Word text = MultipleInput();
    // printf("%d",text.Length);
    if(text.Length == 0){
        printf("Kicauan tidak boleh hanya berisi\n");
        printf("spasi!\n");
    }
    else{
        InsertNewLastKicau(l, text);
        printf("\n");
        printf("Selamat! kicauan telah\n");
        printf("diterbitkan!\n");
        printf("Detil kicauan: \n");
        printDataKicauan(l->kicau[l->nEff-1]);
    }
    
}

void DisplayKicauan(ListKicau l, int id){
    Word user = SELMT(dataNama,id);
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

void InsertNewLastKicau(ListKicau *l, Word word)
{
    jumlah_kicau++;
    printf("Data: %d",jumlah_kicau);
    kicauan temp;
    KAUTH(&temp) = SELMT(dataNama,current_id);
    printWord(temp.Auth);
    KID(&temp) = jumlah_kicau;
    KLIKE(&temp) = 0;
    printf("%d",temp.Likes);
    KDATE(&temp) = ExtractLocalTimes();
    printWord(temp.Auth);
    KTEXT(&temp) = word;
    temp.next_Utas = NULL;
    KNEFF(*l)++;
    KELMT(*l,KNEFF(*l)-1) = temp;
    printf("id: %d\n",KNEFF(*l)-1);
    insertLast(&kicau_with_balasan,-1);
}

void InsertNewLastKicauWithDATETIME(ListKicau *l,Word word, DATETIME time){
    jumlah_kicau++;
    kicauan temp;
    KAUTH(&temp) = SELMT(dataNama,current_id);
    printWord(temp.Auth);
    KID(&temp) = jumlah_kicau;
    KLIKE(&temp) = 0;
    printf("%d",temp.Likes);
    KDATE(&temp) = time;
    printWord(temp.Auth);
    KTEXT(&temp) = word;
    KNEFF(*l)++;
    temp.next_Utas = NULL;
    KELMT(*l,KNEFF(*l)-1) = temp;
    insertLast(&kicau_with_balasan,-1);
}

kicauan CreateDefinedKicau(Word author, Word text, int Likes, DATETIME dates, int id)
{
    kicauan temps;
    KID(&temps) = id;
    KAUTH(&temps) = author;
    KLIKE(&temps) = Likes;
    KDATE(&temps) = dates;
    KTEXT(&temps) = text;
    temps.next_Utas = NULL;
    return temps;
}

void InsertDeclaredLastKicau(ListKicau *l, kicauan kicau){
    KNEFF(*l)++;
    KELMT(*l,NEFF(*l)-1) = kicau;
    insertLast(&kicau_with_balasan,-1);
    inputNewKicauToListTree(&list_balasan,kicau,NEFF(*l));
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
            ubahKicauToNewBalasan(&BELMT(list_balasan,idKicau-1),KELMT(l,idKicau));
        }
        else{
            printf("Kicauan dengan ID = %d bukan\n",idKicau);
            printf("milikmu!");
        }
    }
}

void expandKicau(ListKicau l, int additional){

}