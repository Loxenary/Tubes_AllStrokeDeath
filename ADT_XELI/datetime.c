#include "datetime.h"
#include <stdio.h>
#include <time.h>
#include <math.h>


time_t locTime;

int GetMaxDay(int M, int Y){
    if(M == 1 || M == 3 || M == 5 || M == 7 || M == 8|| M ==10 || M == 12){
        return 31;
    }
    else if(M == 2){
        if(Y % 400 == 0){
            return 29;
        }
        else if(Y % 100 == 0){
            return 28;
        }
        else if(Y % 4 == 0){
            return 29;
        }
        else{
            return 28;
        }
    }
    else{
        return 30;
    }
}

int GetMaxDayInYear(int Y){
    if ((Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0))) {
        return 366;
    } else {
        return 365;
    }
}

int SecondToYear(long long second){
    int Year = 1970;
    while (second > GetMaxDayInYear(Year) *24 * 3600)
    {
        second-= GetMaxDayInYear(Year) * 24 * 3600;
        Year++;
    }
    return Year;
}

int SecondToMonth(long long seconds) {
    
    int Year = 1970;
    while (seconds > GetMaxDayInYear(Year) *24 * 3600)
    {
        seconds -= GetMaxDayInYear(Year) * 24 * 3600;
        Year++;
    }
    int Month = 1;
    while (seconds > GetMaxDay(Month, Year) * 24 * 3600)
    {
        seconds -=  GetMaxDay(Month, Year) * 24 * 3600;
        Month++;
    }
    return Month;
}

int SecondToDay(long long seconds){
    int Year = 1970;
    while (seconds > GetMaxDayInYear(Year) *24 * 3600)
    {
        seconds -= GetMaxDayInYear(Year) * 24 * 3600;
        Year++;
    }
    int Month = 1;
    while (seconds > GetMaxDay(Month, Year) * 24 * 3600)
    {
        seconds -=  GetMaxDay(Month, Year) * 24 * 3600;
        Month++;
    }
    int day = 1;
    while (seconds > day * 24 * 3600)
    {
        seconds -= day * 24 * 3600;
        day++;
    }
    return day;
}

void SecondsReducre(long long *seconds) {
    int Year = 1970;
    int secondsInYear;
    while (*seconds > (secondsInYear = GetMaxDayInYear(Year) * 24 * 3600)) {
        *seconds -= secondsInYear;
        Year++;
    }

    int Month = 1;
    int secondsInMonth;
    while (*seconds >= (secondsInMonth = GetMaxDay(Month, Year) * 24 * 3600)) {
        *seconds -= secondsInMonth;
        Month++;
    }

    int day = 1;
    while (*seconds > (day * 24 * 3600)) {
        *seconds -= (day * 24 * 3600);
        day++;
    }
}

boolean isLeapYear(int year) {
   return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void secondsToYearMonthDay(long long seconds, int *years, int *months, int *days){
    int secondsInDay = 24 * 60 * 60;  // Number of seconds in a day

    *years = seconds / (365 * secondsInDay);
    seconds %= 365 * secondsInDay;

    for (*years += 1970; seconds >= 0; (*years)++) {
        int daysInYear = isLeapYear(*years) ? 366 : 365;
        if (seconds < daysInYear * secondsInDay)
            break;
        seconds -= daysInYear * secondsInDay;
    }

    for (*months = 1; seconds >= 0; (*months)++) {
        int daysInMonth;
        switch (*months) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                daysInMonth = 31;
                break;
            case 4: case 6: case 9: case 11:
                daysInMonth = 30;
                break;
            case 2:
                daysInMonth = isLeapYear(*years) ? 29 : 28;
                break;
            default:
                break;
        }
        if (seconds < daysInMonth * secondsInDay)
            break;
        seconds -= daysInMonth * secondsInDay;
    }

    if (*months > 12) {
        *months = 1;
        (*years)++;
    }

    *days = (seconds % secondsInDay) / (60 * 60 * 24);
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss){
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Hour(Time(*D)) = hh;
    Minute(Time(*D)) = mm;
    Second(Time(*D)) = ss;
}

void BacaDATETIME(DATETIME *D){
    int Day;
    int Month;
    int Year;
    int hour;
    int minute;
    int second;
    scanf("%d %d %d %d %d %d", &Day, &Month, &Year, &hour, &minute, &second);
    while (!IsDATETIMEValid(Day, Month, Year, hour, minute, second))
    {
        printf("DATETIME tidak valid");
        scanf("%d %d %d %d %d %d", &Day, &Month, &Year, &hour, &minute, &second);
    }
    CreateDATETIME(D,Day, Month, Year, hour, minute, second);
}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s){
    int maxDay = GetMaxDay(M, Y);
    if( (D < 0) && (M < 0) && (Y < 0) && (h < 0) && (m < 0) && (s < 0)){
        return 0;
    }
    if(( D <= maxDay)&&(M <= 12)&&(h <=23)&&(m <= 59) &&(s <= 59))
    {
        return 1;
    }
    return 0;
}

void TulisDATETIME(DATETIME D){
    printf("%d/%d/%d ",Day(D),Month(D),Year(D));
    TulisTIME(Time(D));
}

boolean DEQ(DATETIME D1, DATETIME D2){
    return((Month(D1)==Month(D2))&&(Year(D1)==Year(D2))&&(Day(D1)==Day(D2))&&(TEQ(Time(D1),Time(D2))));
}

boolean DNEQ(DATETIME D1, DATETIME D2){
    return !DEQ(D1,D2);
}

boolean DLT(DATETIME D1, DATETIME D2){
    return (((24*3600*365* Year(D1)) + (3600 *24 * Day(D1)) + (3600 * 24 * 30* Month(D1)) +TIMEToDetik(Time(D1)))) < ((24*3600*365*30* Year(D2)) + (3600 *24 * Day(D2)) + (3600 * 24 * 30* Month(D2)) +TIMEToDetik(Time(D2)));
}

boolean DGT(DATETIME D1, DATETIME D2){
    return !DLT(D1,D2);
}

DATETIME DATETIMENextNDetik(DATETIME D, int N){
    DATETIME D1;
    D1 = D;
    Time(D1) = NextNDetik(Time(D1),N);

    return D1;
}

int DateToDetik(DATETIME D){
    int year = Year(D);
    int month = Month(D);
    int day = Day(D);

    return (3600 * 24 * 365 * year)+(24 * 3600 * month * 30)+(24 * 3600 *day);
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N){
    return DATETIMENextNDetik(D, -N);
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh){
    return DateToDetik(DAkh) + TIMEToDetik(Time(DAkh)) - DateToDetik(DAw) - TIMEToDetik(Time(DAw));
}

DATETIME ExtractLocalTimes() {
    DATETIME temps;
    time(&locTime);

    struct tm* timeInfo = localtime(&locTime);

    int year = 1900 + timeInfo->tm_year;
    int month = 1 + timeInfo->tm_mon;
    int day = timeInfo->tm_mday;

    int hour = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;
    int second = timeInfo->tm_sec;

    CreateDATETIME(&temps, day, month, year, hour, minute, second);

    return temps;
}
