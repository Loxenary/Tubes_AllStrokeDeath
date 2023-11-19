#include <stdio.h>
#include <time.h>
#include "database.h"
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
        //Push(&stime, datetime);
        overwriteDraf(&draf, index, s, stime);
        printf("Draf telah berhasil disimpan!\n");
    }
    else if(fungsi.TabWord[0] == 'T')
    {
        
    }
    else
    {
        printf("Draf telah berhasil dihapus!\n");
    }
}

void lihatDraf(WrdType nama)
{
    time_t rawtime;
    struct tm *local_time;

    time(&rawtime);
    local_time = localtime(&rawtime);

    Word currentWord, fungsi, worddraf, waktudraf, drafbaru;
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
        Pop(&stime, &waktudraf);
        printf("Ini draf terakhir anda:\n");
        printf("| %d/%d/%d %d:%d:%d", local_time->tm_hour, local_time->tm_min, local_time->tm_sec, local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
        printf("| ");
        printWord(worddraf);
    }

    printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
    i = 0;
    START();
    while (currentChar != MARK)
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }

    if (currentWord.TabWord[0] == 'K' || currentWord.TabWord[0] == 'H')
    {
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
            Push(&s, currentWord);
            //Push(&stime, datetime);
            overwriteDraf(&draf, index, s, stime);
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
    else
    {
        InsertNewLastKicau(&list_kicau, worddraf);
        return 0;
    }
}