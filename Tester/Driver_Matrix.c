#include ".../src/ADT/matrix.h"
int main() {
    Matrix m;
    int nRow, nCol;
    scanf("%d %d", &nRow, &nCol);
    readMatrix(&m, nRow, nCol);
    displayMatrix(m);
    return 0;
}
