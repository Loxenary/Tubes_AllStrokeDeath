#ifndef ListStatikStack_H
#define ListStatikStack_H

#include "boolean.h"
#include "stack.h"

/*  Kamus Umum */
#define CAPACITY 20
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Stack ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
   ElType waktu[CAPACITY]
} ListStatikStack;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]
#define telmt(l, i) (l).waktu[(i)]

void CreateListStatikstack(ListStatikStack *l);
/*membuat list statik berisi stack yang kosong*/

Stack ambilDraf(ListStatikStack l, int idx);
/*mereturn stack milik akun pada index ke-idx pada list datanama*/

void overwriteDraf(ListStatikStack *l, int idx);
/*meng-overwrite data draf pada liststatikstack dengan stack yang sudah diedit pada fungsi draf*/



#endif