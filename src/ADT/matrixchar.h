/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MatrixChar_H
#define MatrixChar_H

#include "boolean.h"

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP_MCHAR 5
#define COL_CAP_MCHAR 10

typedef int IndexMChar; /* Index baris, kolom */
typedef char IsianMChar;
typedef struct
{
   IsianMChar mem[ROW_CAP_MCHAR][COL_CAP_MCHAR];
   int rowEfMChar; /* banyaknya/ukuran baris yg terdefinisi */
   int colEfMChar; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixChar;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
void createMatrixCharKosong(MatrixChar *m);
/* *** Konstruktor membentuk Matrix *** */

void MatrixProfileDefault(MatrixChar *m);
/* *** Selektor *** */
#define MCROW_EFF(M) (M).rowEfMChar
#define MCCOL_EFF(M) (M).colEfMChar
#define MCELMT(M, i, j) (M).mem[(i)][(j)]

IsianMChar getElmtMChar(MatrixChar m, int row, int col);
/* Mengirimkan elemen m(i,j) */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrixProfil(MatrixChar *m);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrixCharColoured(MatrixChar m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

void displayMatrixChar(MatrixChar m);

boolean isfullMatrixChar(MatrixChar m);

#endif