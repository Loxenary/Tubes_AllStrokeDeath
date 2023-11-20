#ifndef ListStatikMatrix_H
#define ListStatikMatrix_H

#include "boolean.h"
#include "matrixchar.h"

/*  Kamus Umum */
#define MXCAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef MatrixChar Isianmatrix;  /* type elemen List */
typedef int IdxType;
typedef struct {
   Isianmatrix contents[MXCAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatikMatrix;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define LSMELMT(l, i) (l).contents[(i)]

void CreateListStatikMatrix(ListStatikMatrix *l);
/*membuat list statik berisi stack yang kosong*/

MatrixChar ambilMatrixChar(ListStatikMatrix l, int idx);
/*mereturn stack milik akun pada index ke-idx pada list datanama*/

void overwriteMatrixChar(ListStatikMatrix *l, MatrixChar m, int idx);
/*meng-overwrite data matrix pada liststatikmatrix dengan matrix yang sudah diedit*/

#endif