#include "liststatikstack.h"

void CreateListStatikstack(ListStatikStack *l)
/*membuat list statik berisi stack yang kosong*/
{
    int i;
    for (i = 0; i < LSCAPACITY; i++)
    {
        Stack empty;
        CreateEmpty(&empty);

        LSSELMT(*l, i) = empty;
    }
}

Stack ambilDrafdanDatetime(ListStatikStack l, int idx)
/*mereturn stack berisi draf milik akun pada index ke-idx pada list datanama*/
{
    return (LSSELMT(l, idx));
}

void overwriteDraf(ListStatikStack *l, int idx, Stack s)
/*meng-overwrite data draf pada liststatikstack dengan stack yang sudah diedit pada fungsi draf*/
{
    LSSELMT(*l, idx) = s;
}