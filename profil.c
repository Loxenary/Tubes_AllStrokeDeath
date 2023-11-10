#include <stdio.h>
#include "ADT_DAVE/Database.h"
#include "ADT_DAVE/charmachine.h"
#include "ADT_DAVE/wordmachine.h"
#include "ADT_Dave/pcolor.h"

void gantiProfil(WrdType nama)
{
    Word currentWord;
    char currentChar;
    int i = 0;

    int index;
    if (SwindexOf(dataNama, nama) != IDX_UNDEF)
    {
        index = SwindexOf(dataNama, nama);
    }

    printf("| Nama: ");
    printWord(SELMT(dataNama, index));
    printf("\n| Bio Akun: ");
    printWord(SELMT(bio, index));
    printf("\n| No HP: ");
    printWord(SELMT(phone, index));
    printf("\n| Weton: ");
    printWord(SELMT(Weton, index));

    printf("\n\nMasukkan Bio Akun:\n");
    START();
    while (currentChar != BLANK && currentChar != ';' && i <= 135)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i == 0)
    {
        SELMT(bio, index) = STATICMARK;
    }
    else
    {
        SELMT(bio, index) = currentWord;
    }

    printf("\nMasukkan No HP:\n");
    boolean cek = FALSE, cek1 = TRUE;

    Word cekAngka;
    for (int i = 0; i <= 9; i++)
    {
        cekAngka.TabWord[i] = i;
    }

    while (!cek)
    {
        START();
        int len = 0;
        while (currentChar != BLANK && currentChar != ';')
        {
            currentChar -= '0';    
            currentWord.TabWord[i] = currentChar;
            ADV();
            len++;
        }

        for (int i = 0; i <= len; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                if (currentWord.TabWord[j] != cekAngka.TabWord[i]);
                {
                    
                }
            }
        }

        if ()
        {
            SELMT(phone, index) = currentWord;
        }
        else
        {
            printf("");
        }
    }
    


    printf("\nMasukkan Weton:\n");

    START();
    while (currentChar != BLANK && currentChar != ';')
    {
        currentChar -= '0';
        if (currentChar == int)
        {
            currentWord.TabWord[i] = (char)currentChar;
            ADV();
            i++;
        }
        else
        {
            cek = FALSE;
        }
    }
}

void lihatProfil(WrdType nama)
{
    int index;
    if (SwindexOf(dataNama, nama) != IDX_UNDEF)
    {
        index = SwindexOf(dataNama, nama);
    }

    if (ELMT(JenisAkun, index) == 0 || SwisValExist(ListTeman(matPertemanan, index), SELMT(dataNama, index)))
    {
        printf("| Nama: ");
        printWord(SELMT(dataNama, index));
        printf("\n| Bio Akun: ");
        printWord(SELMT(bio, index));
        printf("\n| No HP: ");
        printWord(SELMT(phone, index));
        printf("\n| Weton: ");
        printWord(SELMT(Weton, index));

        printf("\n\nFoto profil akun ");
        printWord(SELMT(dataNama, index));
        printf("\n");

        displayMatrixChar(LSMELMT(profil, index));
        printf("\n\n");
    }
    else
    {
        printf("Wah, akun ");
        printWord(SELMT(dataNama, index));
        printf("diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
        printWord(SELMT(dataNama, index));
        printf("!\n\n");
    }
}

void aturJenisAkun(WrdType nama)
{
    Word currentWord;
    char currentChar;
    int index = SwindexOf(dataNama, nama), i = 0;

    if (ELMT(JenisAkun, index) == 0)
    {
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK) ");

        START();
        IgnoreBlanks();
        while (currentChar != BLANK && currentChar != ';')
        {
            currentWord.TabWord[i] = currentChar;
            ADV();
            i++;
        }

        if (currentWord.TabWord[0] == 'Y')
        {
            ELMT(JenisAkun, index) = 1;
        }
        else
        {
            printf("Baiklah, akun Anda akan tetap menjadi akun Publik\n");
        }
    }
    else
    {
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK) ");

        START();
        IgnoreBlanks();
        while (currentChar != BLANK && currentChar != ';')
        {
            currentWord.TabWord[i] = currentChar;
            ADV();
        }

        if (currentWord.TabWord[0] == 'Y')
        {
            ELMT(JenisAkun, index) = 0;
        }
        else
        {
            printf("Baiklah, akun Anda akan tetap menjadi akun Privat\n");
        }
    }
}

void ubahFotoProfil(WrdType nama)
{    
    int index;
    if (SwindexOf(dataNama, nama) != IDX_UNDEF)
    {
        index = SwindexOf(dataNama, nama);
    }

    printf("Foto profil Anda saat ini adalah\n");
    displayMatrixCharColoured(LSMELMT(profil, index));
    printf("\nMasukkan foto profil yang baru\n");
    readMatrixProfil(&LSMELMT(profil, index));
    printf("Foto profil anda sudah berhasil diganti!\n");
}