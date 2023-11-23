#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity){
      BUFFER(*l) = (int*)malloc(capacity*sizeof(int));
      NEFF(*l) = 0;
      CAPACITYD(*l) = capacity;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    

void dealocateList(ListDin *l){
      free(BUFFER(*l));
      CAPACITYD(*l) = 0;
      NEFF(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITYD(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
      return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
      return IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListDin l){
      return NEFF(l)-1;
      //asumsi disini adalah semua list yang ada di NEFF bersifat consecutive
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
      return (i > IDX_UNDEF && i <= CAPACITYD(l));
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
      return (i >= getFirstIdx(l) && i <= getLastIdx(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
      return NEFF(l) == 0;
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
      return NEFF(l) == CAPACITYD(l);
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
      int n, i;
      scanf("%d",&n);
      while(!isIdxValid(*l,n)){
            scanf("%d",&n);
      }
      NEFF(*l) = n;
      for(i=0; i<n;i++){
            scanf("%d",&ELMTD(*l,i));
      }
      
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITYD(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITYD(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l){
      int i;
      printf("[");
      for(i = 0; i < listLength(l); i++){
            if(i != listLength(l)-1){
                  printf("%d",ELMTD(l,i));
                  printf(",");
            }
            else{
                  printf("%d",ELMTD(l,i));
            }
      }
      printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
      int i;
      ListDin lcopy;
      CreateListDin(&lcopy, CAPACITYD(l1));
      NEFF(lcopy) = NEFF(l1);
      if(plus){
            for(i = 0; i < NEFF(l1); i++){
                  ELMTD(lcopy,i)  = ELMTD(l1, i) + ELMTD(l2,i);
            }
      }
      else{
            for(i = 0; i < NEFF(l1); i++){
                  ELMTD(lcopy,i)  = ELMTD(l1, i) - ELMTD(l2,i);
            }
      }
      return lcopy;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */\
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
      int i;
      if(NEFF(l1) != NEFF(l2))
      {
            return 0;
      }
      else{
            for(i = 0; i < NEFF(l1); i++){
                  if(ELMTD(l1,i) != ELMTD(l2,i)){
                        return 0;
                  }
            }
      }
      return 1;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
      int i;
      if(NEFF(l) == 0){
            return IDX_UNDEF;
      }
      for(i = 0; i < listLength(l); i ++){
            if(ELMTD(l,i) == val){
                  return i;
            }
      }
      return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
      int i;
      *max = ELMTD(l,getFirstIdx(l));
      *min = ELMTD(l, getFirstIdx(l));
      for(i = 0; i < listLength(l); i++){
            if(ELMTD(l,i) > *max){
                  *max = ELMTD(l,i);
            }
            if(ELMTD(l,i) < *min){
                  *min = ELMTD(l,i);
            }
      }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
      int i;
      CreateListDin(lOut,CAPACITYD(lIn));
      NEFF(*lOut) = NEFF(lIn);
      for(i = 0; i < listLength(lIn); i++){
            ELMTD(*lOut,i) = ELMTD(lIn,i);
      }
}

void DinsertAt(ListDin *l, ElType val, IdxType id){
      int i;
      ListDin l1;
      CreateListDin(&l1,50);
      for(i = 0; i < id; i++){
          ELMTD(l1,i) = ELMTD(*l,i);
      }
      for(i = id; i <= getLastIdx(*l); i++){
          ELMTD(l1, i+1) = ELMTD(*l,i);
      }
      ELMTD(l1,id) = val;
      *l = l1;
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
ElType sumList(ListDin l){
      int hasil, i;
      hasil = 0;
      for(i =0 ; i < NEFF(l); i++){
            hasil += ELMTD(l,i);
      }
      return hasil;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
      int hasil,i;
      hasil = 0;
      for(i = 0; i < NEFF(l); i++){
            if(ELMTD(l,i) == val){
                  hasil++;
            }
      }
      return hasil;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
      int i,j, temp;
      if(asc){
            for(i = 0; i < NEFF(*l); i++){
                  for(j = i+1; j < NEFF(*l); j++){
                        if(ELMTD(*l,i) > (ELMTD(*l,j))){
                              temp = ELMTD(*l,i);
                              ELMTD(*l,i) = ELMTD(*l,j);
                              ELMTD(*l,j) = temp; 
                        }
                  }
            }
      }
      else{
             for(i = 0; i < NEFF(*l); i++){
                  for(j = i+1; j < NEFF(*l); j++){
                        if(ELMTD(*l,i) < (ELMTD(*l,j))){
                              temp = ELMTD(*l,i);
                              ELMTD(*l,i) = ELMTD(*l,j);
                              ELMTD(*l,j) = temp; 
                        }
                  }
            }
      }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
      NEFF(*l)++;
      ELMTD(*l,getLastIdx(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
      *val = ELMTD(*l,getLastIdx(*l));
      ListDin l2;
      int i;
      CreateListDin(&l2, CAPACITYD(*l));
      NEFF(l2) = NEFF(*l)-1;
      for(i = 0; i< getLastIdx(*l); i++){
            ELMTD(l2,i) = ELMTD(*l,i);      
      }
      *l = l2;
      
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
      CAPACITYD(*l)+=num;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
      CAPACITYD(*l)-=num;
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
      CAPACITYD(*l) = NEFF(*l);
}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
