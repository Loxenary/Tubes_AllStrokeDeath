/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef ListStatikWordDin_H
#define ListStatikWordDin_H

#include "boolean.h"
#include "wordmachine.h"

/*  Kamus Umum */
#define SCAPACITY 20 // Jumlah Pengguna
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct ListStatikWordDin{
   WrdDinType contents[SCAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatikWordDin;

// typedef struct ListStatikWordDin{
//    WordDin tabs[SCAPACITY];
//    int neff;
// } ListStatikWordDin;

/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatikWord, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatikWord */
/* Maka cara akses: 
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define LSWDELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void SwdCreateListStatik(ListStatikWordDin *l);

// void SwCreateListStatikWrdDin(ListStatikWordDin *l);


/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

boolean SwdisValExist(ListStatikWordDin l, WrdDinType w);
/* Mengirimkan true jika w terdifinisi dalam l*/
/* Yaitu terdapat suatu nama w yang berada dalam list word l*/

int SwdlistLength(ListStatikWordDin l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType SwdgetFirstIdx(ListStatikWordDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType SwdgetLastIdx(ListStatikWordDin l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean SwdisIdxEff(ListStatikWordDin l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean SwdisEmpty(ListStatikWordDin l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean SwdisFull(ListStatikWordDin l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
/*    Jika n = 0; hanya terbentuk List kosong */
void SwdprintList(ListStatikWordDin l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int SwdindexOf(ListStatikWordDin l, WrdDinType val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
/* *** Menambahkan elemen terakhir *** */
void SwdinsertFirst(ListStatikWordDin *l, WrdDinType val);
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void SwdinsertAt(ListStatikWordDin *l, WrdDinType val, IdxType idx);
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void SwdinsertLast(ListStatikWordDin *l, WrdDinType val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

// void SwdinsertLastWordDin(ListStatikWordDin *l, WordDin val);
/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void SwddeleteFirst(ListStatikWordDin *l, WrdDinType *val);
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void SwddeleteAt(ListStatikWordDin *l, WrdDinType *val, IdxType idx);
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void SwddeleteVal(ListStatikWordDin *l, WrdDinType w);
/* Menghapus w dari *l, dan w harus terdefinisi*/
/* Jika w tidak terdefinisi maka akan mengirim pesan error*/

void SwddeleteLast(ListStatikWordDin *l, WrdDinType *val);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

#endif