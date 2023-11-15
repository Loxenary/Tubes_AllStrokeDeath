#include <stdio.h>
#include <time.h>
#include "draf.h"

void buatDraf(WrdType nama)
{
    Word currentWord, fungsi;
    char currentChar;
    int index, i = 0;
    if (SwindexOf(dataNama, nama) != IDX_UNDEF)
    {
        index = SwindexOf(dataNama, nama);
    }

    Stack s = ambilDraf(draf, index), stime = ambilWaktuDraf(draf, index);

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
        Push(&s, currentWord);
        Push(&stime, datetime);
        overwriteDraf(&draf, index, s, stime);
        printf("Draf telah berhasil disimpan!\n");
    }
    else if(fungsi.TabWord[0] == 'T')
    {
        cuit;
    }
    else
    {
        overwriteDraf(&draf, index);
        printf("Draf telah berhasil dihapus!\n");
    }
}

void lihatDraf(WrdType nama)
{
    time_t rawtime;
    struct tm *local_time;

    time(&rawtime);
    local_time = localtime(&rawtime);

    Word currentWord, fungsi, worddraf, waktudraf;
    char currentChar;
    int index, i = 0;
    if (SwindexOf(dataNama, nama) != IDX_UNDEF)
    {
        index = SwindexOf(dataNama, nama);
    }

    Stack s = ambilDraf(draf, index), stime = ambilWaktuDraf(draf, index);

    if (IsEmpty(s))
    {
        printf("\nWhoops, anda belum memiliki draf apapun! Buat dulu ya :3\n\n");
    }
    else
    {
        Pop(&s, &worddraf);
        Pop(&s, &waktudraf);
        printf("Ini draf terakhir anda:\n");
        printf("| %d/%d/%d %d:%d:%d", local_time->tm_hour, local_time->tm_min, local_time->tm_sec, local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
        printf("| ");
        
    }
}
