#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "time.h"
#include "boolean.h"
#define pi 3.14159265359

boolean IsTIMEValid (int H, int M, int S)
{
    return (((H <= 23) && (H >= 0)) && ((M >= 0) && (M <= 59)) && ((S >= 0) && (S <= 59)));
}

void CreateTime (TIME * T, int HH, int MM, int SS)
{
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME (TIME * T)
{
    int H, M, S;
    scanf("%d %d %d", &H, &M, &S);

    while (IsTIMEValid(H, M, S) == false)
    {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &H, &M, &S);
    }

    CreateTime(T, H, M, S);
}

void TulisTIME (TIME T)
{
    printf("%d:%d:%d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T)
{
    return (((Hour(T) * 3600) + (Minute(T) * 60) + Second(T))%86400);
}

TIME DetikToTIME (long N)
{
    TIME T;
    int jam, menit, detik;
    while (N >= 86400)
    {
        N = N % 86400;
    }

    jam = N / 3600;
    menit = (N - (jam*3600)) / 60;
    detik = (N - (jam*3600)) - (menit*60);
    CreateTime(&T, jam, menit, detik);
    return T;
}

boolean TEQ (TIME T1, TIME T2)
{
    return ((Hour(T1)==Hour(T2)) && (Minute(T1)== Minute(T2)) && (Second(T1)==Second(T2)));
}

boolean TNEQ (TIME T1, TIME T2)
{
    return (!TEQ(T1, T2));
}

boolean TLT (TIME T1, TIME T2)
{
    long total1, total2;
    total1 = (Hour(T1) * 3600) + (Minute(T1) * 60) + Second(T1);
    total2 = (Hour(T2) * 3600) + (Minute(T2) * 60) + Second(T2);
    return (total1 < total2);
}

boolean TGT (TIME T1, TIME T2)
{
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

TIME NextDetik (TIME T)
{
    long detik = TIMEToDetik(T);
    detik++;
    return DetikToTIME(detik);
}

TIME NextNDetik (TIME T, int N)
{
    long jumlah;
    jumlah = ((Hour(T) * 3600) + (Minute(T) * 60) + Second(T));
    jumlah = jumlah + N;

    if (jumlah > 86400)
    {
        jumlah = jumlah % 86400;
    }
    else if (jumlah < 0)
    {
        jumlah = jumlah + 86400;
    }
    Hour(T) = jumlah / 3600;
    Minute(T) = (jumlah - (Hour(T)*3600)) / 60;
    Second(T) = (jumlah - (Hour(T)*3600)) - (Minute(T)*60);
    return T;
}

TIME PrevDetik (TIME T)
{
    long jumlah;
    jumlah = ((Hour(T) * 3600) + (Minute(T) * 60) + Second(T));
    jumlah = jumlah - 1;

    if (jumlah > 86400)
    {
        jumlah = jumlah % 86400;
    }
    else if (jumlah < 0)
    {
        jumlah = jumlah + 86400;
    }
    Hour(T) = jumlah / 3600;
    Minute(T) = (jumlah - (Hour(T)*3600)) / 60;
    Second(T) = (jumlah - (Hour(T)*3600)) - (Minute(T)*60);
    return T;
}

TIME PrevNDetik (TIME T, int N)
{
    long jumlah;
    jumlah = ((Hour(T) * 3600) + (Minute(T) * 60) + Second(T));
    jumlah = jumlah - N;

    while (jumlah > 86400)
    {
        jumlah = jumlah % 86400;
    }

    if (jumlah < 0)
    {
        jumlah = jumlah + 86400;
    }

    Hour(T) = jumlah / 3600;
    Minute(T) = (jumlah - (Hour(T)*3600)) / 60;
    Second(T) = (jumlah - (Hour(T)*3600)) - (Minute(T)*60);
    return T;
}

long Durasi (TIME TAw, TIME TAkh)
{
    long total1, total2, selisih;
    total1 = (Hour(TAw) * 3600) + (Minute(TAw) * 60) + Second(TAw);
    total2 = (Hour(TAkh) * 3600) + (Minute(TAkh) * 60) + Second(TAkh);

    selisih = total2-total1;

    if (selisih < 0)
    {
        selisih = selisih + 86400;
    }
    return selisih;
}
