/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDINWORD_H
#define LISTDINWORD_H

#include "boolean.h"
#include "wordmachine.h"
/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */

typedef int IdxType;
typedef struct
{
    WrdType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListWord;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define DNEFF(l) (l).nEff
#define DBUFFER(l) (l).buffer
#define DELMT(l, i) (l).buffer[i]
#define DCAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
void DWCreateList(ListWord *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void DWdealocateList(ListWord *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

int DWlistLength(ListWord l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

void DWprintList(ListWord l);
/*Display ke Layar Suatu ListWord yang dinamis*/

void DWdeleteVal(ListWord * l, WrdType w);
/* Menghapus w dari *l, dan w harus terdefinisi*/
/* Jika w tidak terdefinisi maka akan mengirim pesan error*/



boolean DWisValExist(ListWord l, WrdType w);
/* Mengirimkan true jika w terdifinisi dalam l*/
/* Yaitu terdapat suatu nama w yang berada dalam list word l*/


void DWinsertLast(ListWord *l, WrdType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void DWdeleteLast(ListWord *l, WrdType *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

void DWexpandList(ListWord *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
#endif