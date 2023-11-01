#include <stdio.h>
#include <stdlib.h>
#include "time.h"  
#include "datetime.h" 


int GetMaxDay(int M, int Y)
{
    if (M == 2){
        if ((Y % 400 == 0) || (Y % 400 != 0 && Y % 100 != 0 && Y % 4 == 0))
        {
            return 29;
        }   
        else
        {
            return 28;
        }
    } 
    else if ((M == 8) || (M >= 1 && M <= 7 && M % 2 != 0 ) || (M >= 9 && M <= 12 && M % 2 == 0))
    {
        return 31;
    } 
    else if ((M >= 1 && M <= 7 && M % 2 == 0 ) || (M >= 9 && M <= 12 && M % 2 != 0))
    {
        return 30;
    }
}
boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    return((D <= GetMaxDay(M,Y) && D >= 1) && (M>=1 && M<=12) && (Y>=1) && IsTIMEValid(h,m,s));
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{   
    TIME T ;
    CreateTime(&T,hh,mm,ss);
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;    
    Time(*D) = T;
}

void BacaDATETIME(DATETIME *D)
{
    int DD, MM, YYYY, hh,mm,ss;
    do
    {
        scanf("%d %d %d %d %d %d",&DD,&MM,&YYYY,&hh, &mm ,&ss);
        if (!IsDATETIMEValid(DD,MM,YYYY,hh, mm ,ss))
        {
            printf("DATETIME tidak valid\n");
        }

    }while(!IsDATETIMEValid(DD,MM,YYYY,hh, mm ,ss));
    CreateDATETIME(D,DD,MM,YYYY,hh,mm,ss);
}

void TulisDATETIME(DATETIME D)
{
    printf("%d/%d/%d %d:%d:%d",Day(D),Month(D),Year(D),Hour(Time(D)),Minute(Time(D)),Second(Time(D)));
}
boolean DEQ(DATETIME D1, DATETIME D2)
{
    return((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && TEQ(Time(D1),Time(D2)));
}
boolean DNEQ(DATETIME D1, DATETIME D2)
{
    return((Day(D1) != Day(D2)) || (Month(D1) != Month(D2)) || (Year(D1) != Year(D2)) || TNEQ(Time(D1),Time(D2)));
}
boolean DLT(DATETIME D1, DATETIME D2)
{
    if (Year(D1) == Year(D2))
    {
        if (Month(D1) == Month(D2))
        {
            if (Day(D1) == Day(D2))
            {
                return(TLT(Time(D1),Time(D2)));
            }
            else
            {
                return(Day(D1) < Day(D2));
            }        
        }
        else
        {
            return(Month(D1) < Month(D2));
        }
    }
    else
    {
        return(Year(D1) < Year(D2));
    }
}
boolean DGT(DATETIME D1, DATETIME D2)
{
    if (Year(D1) == Year(D2))
    {
        if (Month(D1) == Month(D2))
        {
            if (Day(D1) == Day(D2))
            {
                return(TGT(Time(D1),Time(D2)));
            }
            else
            {
                return(Day(D1) > Day(D2));
            }        
        }
        else
        {
            return(Month(D1) > Month(D2));
        }
    }
    else
    {
        return(Year(D1) > Year(D2));
    }
}
DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    long detik ;
    detik = TIMEToDetik(Time(D)) + N;
    while (detik >= 8600)
    {
        Day(D)+=1;
        if (!IsDATETIMEValid(Day(D),Month(D),Year(D),Hour(Time(D)),Minute(Time(D)),Second(Time(D))))
        {
            Day(D) = 1;
            Month(D) +=1;
            if (!IsDATETIMEValid(Day(D),Month(D),Year(D),Hour(Time(D)),Minute(Time(D)),Second(Time(D))))
            {
                Day(D) = 1;
                Month(D) = 1;
                Year(D) +=1;
            }
        }    
        detik-=86400;
    }
    Time(D) = DetikToTIME(detik);
    return D;
}
DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    long detik ;
    detik = TIMEToDetik(Time(D)) - N;
    while (detik<0)
    {
        Day(D)-=1;
        if (!IsDATETIMEValid(Day(D),Month(D),Year(D),Hour(Time(D)),Minute(Time(D)),Second(Time(D))))
        {
            if (Month(D)-1!=0)
            {
                Day(D) = GetMaxDay(Month(D)-1,Year(D));
                Month(D) -=1;
            }
            else 
            {
                Day(D) = 31;
                Month(D) = 12;
                Year(D) -= 1;
            }
        }    
        detik+=86400;
    }
    Time(D) = DetikToTIME(detik);
    return D;
}
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    return 0;
}

