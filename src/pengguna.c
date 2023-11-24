#include <stdio.h>
#include <stdlib.h>
#include "pengguna.h"

void daftar()
{
    /*Kamus Lokal*/
    boolean dipake = FALSE;
    MatrixChar m;
    /*Algoritma*/
    do 
    {
        printf("Masukkan nama:\n");
        START();
        CopyWordWithSpace();
        if(SwisValExist(dataNama,currentWord)) /*jika sudah terpakai atau jumlah huruf lebih dari 20 termasuk spasi*/
        {
            dipake = TRUE;
            printf("Wah, sayang sekali nama tersebut telah diambil.\n\n");
        }
        else if (currentWord.Length > 20)
        {
            dipake = TRUE;
            printf("Wah, nama yang anda pakai lebih dari 20 karakter mohon pilih kata sandi yang lain.\n\n");
        }
        else
        {
            dipake = FALSE;
            SwinsertLast(&dataNama,currentWord);
        }
    } while(dipake);
    
    printf("\n");

    dipake = TRUE; /*buat loop yang sandi*/
    while (dipake)
    {
        printf("Masukkan kata sandi:\n");
        START();
        CopyWordWithSpace();
        // Word test=  MultipleInput();
        if (currentWord.Length > 20)
        {
            dipake = TRUE;
            printf("Wah, kata sandi anda lebih dari 20 karakter mohon pilih kata sandi yang lain.\n\n");
        }
        else
        {
            dipake = FALSE;
            SwinsertLast(&password,currentWord);
        }
    }

    int idx = current_id+1;
    Word emptyword = {"",0};

    SwinsertLast(&bio,emptyword);
    SwinsertLast(&phone,emptyword);
    SwinsertLast(&Weton,emptyword);
    SinsertLast(&JenisAkun,0);
    createMatrixCharKosong(&m);
    MatrixProfileDefault(&m);
    overwriteMatrixChar(&profil,m,banyak_pengguna);
    expandAdjMatrix(&matPertemanan,1);
    AddEdge(&matPertemanan,banyak_pengguna,banyak_pengguna);
    banyak_pengguna++;

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n\n");
}

void masuk()
{
    boolean gada;
    gada = TRUE;
    do 
    {
        printf("Masukkan nama:\n");
        START();
        CopyWordWithSpace();
        if(SwisValExist(dataNama,currentWord)) 
        {
            gada = FALSE;
        }
        else if (currentWord.Length > 20)
        {
            printf("Wah, nama yang anda masukkan lebih dari 20 karakter mohon pilih kata sandi yang lain.\n\n");
            gada = TRUE;
        }
        else
        {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
            gada = TRUE;
        }
    } while(gada);

    Word login_nama = currentWord;
    printf("\n");

    gada = TRUE; /*buat loop yang sandi*/
    do 
    {
        printf("Masukkan kata sandi:\n");
        START();
        CopyWordWithSpace();
        if(SwisValExist(password,currentWord)) 
        {
            current_id = SwindexOf(password,currentWord);
            gada = FALSE;
        }
        else if (currentWord.Length > 20)
        {
            printf("Wah, kata sandi yang anda masukkan lebih dari 20 karakter mohon pilih kata sandi yang lain.\n\n");
            gada = TRUE;
        }
        else
        {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n\n");
            gada = TRUE;
        }
    } while(gada);

    isLogin = TRUE;
    printf("Anda telah berhasil masuk dengan nama pengguna ");
    printWord(login_nama);
    printf(". Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n\n");
}

void keluar()
{
    isLogin = FALSE;

}