#include "liststatikstack.h"

void CreateListStatikstack(ListStatikStack *l)
/*membuat list statik berisi stack yang kosong*/
{
    for (int i = 0; i < 20; i++)
    {
        Stack empty;
        CreateEmpty(&empty);
        LSSELMT(*l, i) = empty;
        LSSTELMT(*l, i) = empty;
    }
}

Stack ambilDraf(ListStatikStack l, int idx)
/*mereturn stack berisi draf milik akun pada index ke-idx pada list datanama*/
{
    return (LSSELMT(l, idx));
}

Stack ambilWaktuDraf(ListStatikStack l, int idx)
/*mereturn stack berisi waktu terakhir draf diedit milik akun pada index ke-idx pada list datanama*/
{
    return (LSSTELMT(l, idx));
}

void overwriteDraf(ListStatikStack *l, int idx, Stack s, Stack stime)
/*meng-overwrite data draf pada liststatikstack dengan stack yang sudah diedit pada fungsi draf*/
{
    LSSELMT(*l, idx) = s;
    LSSTELMT(*l, idx) = s;
}