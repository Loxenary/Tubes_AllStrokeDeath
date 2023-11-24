#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CreateEmpty(Stack *S){
    S->T = (infotype *)malloc((InitialSize) * sizeof(infotype));
    S->TD = (infodate *)malloc((InitialSize) * sizeof(infodate));
    if (S->T != NULL && S->TD != NULL) {
        MaxEl(*S) = InitialSize;
        S->TOP = Nil;
    }
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S){
    return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S){
    return Top(S) == S.MaxEl-1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotype X, infodate Y){
    if(!IsFull(*S)){
        Top(*S)++;
        InfoTop(*S) = X;
        InfoTopD(*S) = Y;
    } else {
        addCapacityS(S);
        Top(*S)++;
        InfoTop(*S) = X;
        InfoTopD(*S) = Y;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotype* X, infodate *Y){
    if (!IsEmpty(*S))
    {
        *X = InfoTop(*S);
        *Y = InfoTopD(*S);
        Top(*S)--;
        if (Top(*S) == Nil)
        {
        // Setelah pengurangan, TOP menjadi Nil
        // Stack kosong, atur TOP ke Nil agar sesuai dengan kondisi stack kosong
            Top(*S) = Nil;
        }
    }
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void addCapacityS(Stack *S) {
    MaxEl(*S) += 10;
}
