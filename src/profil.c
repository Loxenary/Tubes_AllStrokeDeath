#include <stdio.h>
#include "database.h"
#include "./ADT/wordmachine.h"
#include "profil.h"

void gantiProfil(WrdType nama)
{
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
    printWordDin(LSWDELMT(phone,index));    
    printf("\n| Weton: ");
    printWord(SELMT(Weton, index));

    printf("\n\nMasukkan Bio Akun:\n");
    START();
    IgnoreEnters();
    while (currentChar != ';' && i <= 135)
    {
        if (currentChar != MARK && i <= NMax) {
            currentWord.TabWord[i] = currentChar;
        }
        ADV();
        i++;
    }
    if (i == 0)
    {
        SELMT(bio, index) = STATICMARK;
    }
    else
    {
        currentWord.Length = i;
        SELMT(bio, index) = currentWord;
    }
    currentWord.TabWord[currentWord.Length] = '\0';

    printf("\nMasukkan No HP:\n");
    boolean cek = TRUE;
    while (cek)
    {
        i = 0;
        cek = TRUE;
        boolean cek1 = TRUE;
        START();
        IgnoreEnters();
        copyWordDin();
        int j = 0;
        while (currentWordDin.container[j] == ENTER)
        {
            j++;
        }
        for (int i = j; i < currentWordDin.Length; i++)
        {
            if(currentWordDin.container[i] < '0' || currentWordDin.container[i] > '9')
            {
                cek1 = FALSE;
            }
        }
        if (cek1)
        {
            LSWDELMT(phone, index) = currentWordDin;
            cek = FALSE;
        }
        else
        {
            printf("No HP tidak valid. Masukkan lagi yuk!\n");
        }
    }
    
    printf("\nMasukkan Weton:\n");
    cek = TRUE;
    while (cek)
    {
        Word Wet = MultipleInput();
        if (cekWeton(Wet) || Wet.Length == 0)
        {
            SELMT(Weton, index) = Wet;
            cek = FALSE;
        }
        else
        {
            printf("Weton anda tidak valid.\n");
        }
    }

    printf("Profil Anda sudah berhasil diperbarui!\n");
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
        printWordDin(LSWDELMT(phone, index));
        printf("\n| Weton: ");
        printWord(SELMT(Weton, index));

        printf("\n\nFoto profil akun ");
        printWord(SELMT(dataNama, index));
        printf("\n");

        displayMatrixCharColoured(LSMELMT(profil, index));
    }
    else
    {
        printf("Wah, akun ");
        printWord(SELMT(dataNama, index));
        printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
        printWord(SELMT(dataNama, index));
        printf("!\n\n");
    }
}

void aturJenisAkun(WrdType nama)
{
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
            printf("Akun anda sudah diubah menjadi akun Private.\n");
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
            printf("Akun anda sudah diubah menjadi akun Publik.\n");
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

boolean cekWeton(Word Weton)
{
    char * legi = "Legi";
    char * pahing = "Pahing";
    char * pon = "Pon";
    char * wage = "Wage";
    char * kliwon = "Kliwon";
    if(isWordEqualString(Weton,legi) || isWordEqualString(Weton,pahing) || isWordEqualString(Weton,pon) || isWordEqualString(Weton,wage) || isWordEqualString(Weton, kliwon))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}