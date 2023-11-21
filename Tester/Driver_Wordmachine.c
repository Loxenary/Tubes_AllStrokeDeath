#include "../src/ADT/wordmachine.h"
#include "../src/ADT/charmachine.h"
#include "../src/ADT/boolean.h"
#include <stdio.h>

int main(){
    printf("Test 1: Startword\n");
    STARTWORD();
    printWord(currentWord);

    printf("Test 2: IgnoreBlanks\n");
    STARTWORD(); // dengan input <spasii> <spasi> biru
    printWord(currentWord);

    printf("Test 3: ");

    
    return 0;
}