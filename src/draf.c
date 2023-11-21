#include <stdio.h>
#include <time.h>
#include "database.h"
#include "draf.h"


void buatDraf(WrdType nama)
{
    Word currentWord, fungsi;
    char currentChar;
    DATETIME currentWaktu;
    int index, i = 0;
    if (SwindexOf(dataNama, nama) != IDX_UNDEF)
    {
        index = SwindexOf(dataNama, nama);
    }

    Stack s = ambilDrafdanDatetime(draf, index);

    printf("\nMasukkan draf:\n");
    START();
    while (currentChar != MARK && i <= 280)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    START();
    i = 0;
    while (currentChar != MARK)
    {
        fungsi.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (fungsi.TabWord[0] == 'S')
    {
        DATETIME waktu = ExtractLocalTimes();
        Push(&s, currentWord, waktu);
        overwriteDraf(&draf, index, s);
        printf("Draf telah berhasil disimpan!\n");
    }
    else if(fungsi.TabWord[0] == 'T')
    {
        InsertNewLastKicau(&list_kicau, currentWord);
    }
    else
    {
        printf("Draf telah berhasil dihapus!\n");
    }
}

int lihatDraf(WrdType nama)
{
    Word currentWord, fungsi, worddraf, waktudraf, drafbaru;
    char currentChar;
    int index, i = 0;
    if (SwindexOf(dataNama, nama) != IDX_UNDEF)
    {
        index = SwindexOf(dataNama, nama);
    }

    Stack s = ambilDrafdanDatetime(draf, index);
    DATETIME waktu;

    if (IsEmpty(s))
    {
        printf("\nWhoops, anda belum memiliki draf apapun! Buat dulu ya :3\n\n");
        return 0;
    }
    else
    {
       
        Pop(&s, &worddraf, &waktu);
        printf("Ini draf terakhir anda:\n");
        printf("| ");
        TulisDATETIME(waktu);
        printf("\n| ");
        printWord(worddraf);
        printf("\n");
    }

    printf("Apakah anda ingin mengubah(UBAH), menghapus(HAPUS), atau menerbitkan(TERBIT) draf ini? (KEMBALI jika ingin kembali)\n");
    i = 0;
    STARTWORD();

    if (currentWord.TabWord[0] == 'H')
    {
        return 0;
    }
    else if (currentWord.TabWord[0] == 'K')
    {
        Push(&s, worddraf, waktu);
        overwriteDraf(&draf, index, s);
        return 0;
    }
    else if (currentWord.TabWord[0] == 'U')
    {
        printf("Masukkan draf yang baru:\n");
        i = 0;
        START();
        while (currentChar != ';' || i <= 280)
        {
            drafbaru.TabWord[i] = currentChar;
            ADV();
            i++;
        }

        printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
        START();
        i = 0;
        while (currentChar != MARK)
        {
            fungsi.TabWord[i] = currentChar;
            ADV();
            i++;
        }

        if (fungsi.TabWord[0] == 'S')
        {
            DATETIME waktu = ExtractLocalTimes();
            Push(&s, drafbaru, waktu);
            overwriteDraf(&draf, index, s);
            printf("Draf telah berhasil disimpan!\n");
            return 0;
        }
        else if(fungsi.TabWord[0] == 'T')
        {
            InsertNewLastKicau(&list_kicau, currentWord);
            return 0;
        }
        else
        {
            printf("Draf telah berhasil dihapus!\n");
            return 0;
        }
    }
    else
    {
        InsertNewLastKicau(&list_kicau, worddraf);
        return 0;
    }
}