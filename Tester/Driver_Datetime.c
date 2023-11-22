#include <stdio.h>

#include "../src/adt/datetime.h"
#include "../src/adt/datetime.c"
#include "../src/adt/times.c"
#include "../src/adt/wordmachine.h"
#include "../src/adt/wordmachine.c"
#include "../src/adt/charmachine.c"

int main()
{
    DATETIME tes;
    BacaDATETIME(&tes);

    if(IsDATETIMEValid(Day(tes), Month(tes), Year(tes), Hour(Time(tes)), Minute(Time(tes)), Second(Time(tes))))
    {
        TulisDATETIME(tes);
    }
    
    return 0;
}