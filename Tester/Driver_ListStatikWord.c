#include "../src/adt/listStatikWord.h"
#include "../src/adt/wordmachine.h"
#include "../src/database.h"

int main(){
    // ListStatikWord l1;
    // SwCreateListStatik(&l1);
    SwCreateListStatik(&dataNama);
    printf("TEST1:\n");
    STARTWORD();
    SwinsertLast(&dataNama,currentWord);
    SwinsertLast(&dataNama,currentWord);
    SwinsertLast(&dataNama,currentWord);
    SwprintList(dataNama);

    

    return 0;
}