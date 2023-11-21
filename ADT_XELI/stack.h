/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "boolean.h"
<<<<<<< Updated upstream:ADT_XELI/stack.h

#define Nil -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef Word infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
=======
#include "wordmachine.h"
#include "datetime.h"

/* Nil adalah stack dengan elemen kosong. */
#define Nil -1

/* Definisi ukuran awal stack. */
#define InitialSize 10

typedef Word infotype;
typedef DATETIME infodate;
typedef int address;   /* indeks tabel */

/* Versi II: dengan alokasi dinamis */
typedef struct {
  infotype *T;      /* tabel penyimpan elemen */
  infodate *TD;
  address TOP;      /* alamat TOP: elemen puncak */
  address MaxEl;    /* ukuran maksimum stack */
} Stack;

/* Definisi stack S kosong: S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack, maka akses elemen: */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor: Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define InfoTopD(S) (S).TD[(S).TOP]
>>>>>>> Stashed changes:src/ADT/stack.h

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
<<<<<<< Updated upstream:ADT_XELI/stack.h
void Push(Stack * S, infotype X);
=======
void Push(Stack * S, infotype X, infodate Y);
>>>>>>> Stashed changes:src/ADT/stack.h
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
<<<<<<< Updated upstream:ADT_XELI/stack.h
void Pop(Stack * S, infotype* X);
=======
void Pop(Stack * S, infotype* X, infodate* Y);
>>>>>>> Stashed changes:src/ADT/stack.h
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif