#include "liststatikstack.h"

void CreateListStatikstack(ListStatikStack *l)
/*membuat list statik berisi stack yang kosong*/
{
    int i;
    for (i = 0; i < CAPACITY; i++)
    {
        Stack emptyText, emptyWaktu;
        CreateEmpty(&emptyText);
        CreateEmpty(&emptyWaktu);

        LSSELMT(*l, i) = emptyText;
        LSSTELMT(*l, i) = emptyWaktu;
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