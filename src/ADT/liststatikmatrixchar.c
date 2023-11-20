#include "liststatikmatrixchar.h"

void CreateListStatikMatrix(ListStatikMatrix *l)
/*membuat list statik berisi stack yang kosong*/
{
    for (int i = 0; i <= 19; i++)
    {
        MatrixChar m;
        createMatrixCharKosong(&m);
        LSMELMT(*l, i) = m;
    }
}

MatrixChar ambilMatrixChar(ListStatikMatrix l, int idx)
/*mereturn stack milik akun pada index ke-idx pada list datanama*/
{
    return (LSMELMT(l, idx));
}

void overwriteMatrixChar(ListStatikMatrix *l, MatrixChar m, int idx)
/*meng-overwrite data matrix pada liststatikmatrix dengan matrix yang sudah diedit*/
{
    LSMELMT(*l, idx) = m;
}