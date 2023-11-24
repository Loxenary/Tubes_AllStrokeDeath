#include "../src/listUtas.h"
#include "../src/adt/wordmachine.h"


int main(){
    ListUtas u1;
    CreateUtas(&u1);
    if(u1 == NULL){
        printf("TETSSTS\n");
    }
    Word text, auth;
    strcpy(text.TabWord, "test");
    text.Length = strlen(text.TabWord);

    strcpy(auth.TabWord, "beit");
    auth.Length = strlen(auth.TabWord);

    DATETIME time = ExtractLocalTimes();

    printf("DATETIME:");
    TulisDATETIME(time);

    addUtas(&u1, 0, 1, text, auth, time);
    

    return 0;
}