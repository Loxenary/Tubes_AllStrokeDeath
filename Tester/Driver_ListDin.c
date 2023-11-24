#include <stdio.h>
#include "../src/adt/listdin.h"

int main(){

    ListDin l1;
    CreateListDin(&l1,50);
    DinsertAt(&l1,20,1);
    printList(l1);
    return 0;
}