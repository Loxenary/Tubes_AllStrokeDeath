#include <stdio.h>
#include <stdlib.h>
#include "../src/ADT/stack.h"
#include "../src/ADT/stack.c"
#include "../src/ADT/wordmachine.h"
#include "../src/ADT/wordmachine.c"
#include "../src/ADT/charmachine.h"
#include "../src/ADT/charmachine.c"
#include "../src/ADT/DATETIME.c"
#include "../src/ADT/times.c"

int main()
{
    Stack s;
    Word w;
    DATETIME l;

    CreateEmpty(&s);

    for (int i = 0;i <= 10; i++)
    {
        int k=0;
        START();
        while (currentChar != ';')
        {
            currentWord.TabWord[k] = currentChar;
            ADV();
            k++;
        }

        currentWord.Length = k;
        DATETIME d = ExtractLocalTimes();
        Push(&s, currentWord, d);
    }

    Pop(&s, &w, &l);
    printWord(w);
    printf("\n");
    TulisDATETIME(l);

    return 0;
}