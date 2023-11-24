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
    
    fungsi = MultipleInput();
    printf("\nApakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    Word temps;
    temps = MultipleInput();
    if (temps.TabWord[0] == 'S')
    {
        DATETIME waktu = ExtractLocalTimes();
        Push(&s, fungsi, waktu);
        overwriteDraf(&draf, index, s);
        printf("Draf telah berhasil disimpan!\n");
    }
    else if(temps.TabWord[0] == 'T')
    {
        InsertNewLastKicau(&list_kicau, fungsi);
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
    fungsi = MultipleInput();
    if (fungsi.TabWord[0] == 'H')
    {
        overwriteDraf(&draf, index, s);
        return 0;
    }
    else if (fungsi.TabWord[0] == 'K')
    {
        Push(&s, worddraf, waktu);
        overwriteDraf(&draf, index, s);
        return 0;
    }
    else if (fungsi.TabWord[0] == 'U')
    {
        printf("Masukkan draf yang baru:\n");
        i = 0;
        drafbaru = MultipleInput();

        printf("\nApakah anda ingin menghapus(HAPUS), menyimpan(SIMPAN), atau menerbitkan(TERBITKAN) draf ini?\n");
        fungsi = MultipleInput();
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
            InsertNewLastKicau(&list_kicau, drafbaru);
            printf("YAYY DRAF SUDAH DITERBITKAN >w<\n");
            printDataKicauan(list_kicau.kicau[list_kicau.nEff-1]);
            return 0;
        }
        else
        {
            printf("Draf telah berhasil dihapus!\n");
            overwriteDraf(&draf, index, s);
            return 0;
        }
    }
    else
    {
        printf("testingtesting\n");
        InsertNewLastKicau(&list_kicau, worddraf);
        overwriteDraf(&draf, index, s);
        return 0;
    }
}