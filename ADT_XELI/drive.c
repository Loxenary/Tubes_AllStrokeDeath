#include "matrixchar.h"
#include "matrixchar.c"
#include "pcolor.c"
#include "charmachine.c"
#include "wordmachine.c"
#include <stdio.h>

int main()
{
    MatrixChar m;

    createMatrixProfileDefault(&m);
    displayMatrixCharColoured(m);

    readMatrixProfil(&m);
    displayMatrixCharColoured(m);

    return 0;
}