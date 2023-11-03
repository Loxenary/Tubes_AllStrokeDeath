#include <stdio.h>
#include "times.h"
#include <math.h>


boolean IsTIMEValid(int H, int M, int S){
    return ((H < 24 && H >= 0) && (M < 60 && M >= 0) && (S < 60 && S >= 0));
}

void CreateTime (TIME * T, int HH, int MM, int SS){
    if(IsTIMEValid(HH,MM,SS)){
        Hour(*T) = HH;
        Minute(*T) = MM;
        Second(*T) = SS;
    }

}

void BacaTIME (TIME * T){
    int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    while(!IsTIMEValid(HH,MM,SS)){
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &HH, &MM, &SS);
    }
    CreateTime(T, HH, MM ,SS);
}

void TulisTIME (TIME T){
    printf("%02d:%02d:%02d",Hour(T),Minute(T),Second(T));
}

long TIMEToDetik(TIME T){
    long hasil;
    hasil = (Hour(T)*3600) + (Minute(T)*60) +Second(T);

    return hasil;
}

TIME DetikToTIME (long N){
    TIME T1;
    int N1;
    N1 = N;
    if(N1 >= 86400){
        N1 %= 86400;
    }
    int HH = N1 / 3600;
    int MM = (N1 % 3600) / 60;
    int SS = (N1 % 3600) % 60;
    CreateTime(&T1,HH,MM,SS);

    return T1;
}

boolean TEQ(TIME T1, TIME T2){
    return ((T1.HH == T2.HH)&&(T1.MM == T2.MM)&&(T1.SS == T2.SS));
}

boolean TNEQ(TIME T1, TIME T2){
    return !TEQ(T1,T2);
}

boolean TLT(TIME T1, TIME T2){
    return (TIMEToDetik(T1)< TIMEToDetik(T2));
}
boolean TGT(TIME T1, TIME T2){
    return (TIMEToDetik(T1)> TIMEToDetik(T2));
}

TIME NextNDetik(TIME T, int N){
    return DetikToTIME((TIMEToDetik(T) + N)%86400);
}

TIME NextDetik(TIME T){
    return NextNDetik(T,1);
}

TIME PrevNDetik(TIME T, int N){
    return DetikToTIME((TIMEToDetik(T) - N + 86400) % 86400);  
}

TIME PrevDetik(TIME T){
    return PrevNDetik(T, 1);
}

long Durasi(TIME TAw, TIME TAkh){
    if(TIMEToDetik(TAw)<=TIMEToDetik(TAkh)){
        return TIMEToDetik(TAkh)-TIMEToDetik(TAw);
    }
    return 86400 - TIMEToDetik(TAw) + TIMEToDetik(TAkh);
}
