#include "../src/ADT/wordmachine.h"
#include "../src/ADT/charmachine.h"
#include "../src/ADT/boolean.h"
#include <stdio.h>
#include "../src/ADT/wordmachine.c"
#include "../src/ADT/charmachine.c"

int main()
{
    printf("input1 (usahakan lebih dari 280 elemen):\n");
    START();
    copyWordDin();
    printf("=================================\n");
    printWordDin(currentWordDin);
    currentWordDin.container[currentWordDin.Length] = '\0';
    printf("yayyy selesai :)\n");
    return 0;
}
