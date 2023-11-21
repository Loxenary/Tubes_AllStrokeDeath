#include <stdio.h>
#include "stack.h"

void CreateEmpty(Stack *S){
<<<<<<< Updated upstream:ADT_XELI/stack.c
    Top(*S) = Nil;
=======
    S->T = (infotype *)malloc((InitialSize) * sizeof(infotype));
    S->TD = (infodate *)malloc((InitialSize) * sizeof(infodate));
    if (S->T != NULL && S->TD != NULL)
    {
        S->MaxEl = InitialSize;
        S->TOP = Nil;
    }
>>>>>>> Stashed changes:src/ADT/stack.c
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
<<<<<<< Updated upstream:ADT_XELI/stack.c
    return Top(S) == MaxEl-1;
=======
    return Top(S) == S.MaxEl-1;
>>>>>>> Stashed changes:src/ADT/stack.c
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
<<<<<<< Updated upstream:ADT_XELI/stack.c
void Push(Stack * S, infotype X){
    if(!IsFull(*S)){
        Top(*S)++;
        InfoTop(*S) = X;
=======
void Push(Stack * S, infotype X, infodate Y){
    if (!IsFull(*S)) {
    // Stack belum penuh, penambahan elemen dilakukan
        Top(*S)++;
        InfoTop(*S) = X;
        InfoTopD(*S) = Y;
>>>>>>> Stashed changes:src/ADT/stack.c
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
<<<<<<< Updated upstream:ADT_XELI/stack.c
void Pop(Stack * S, infotype* X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
=======
void Pop(Stack * S, infotype* X, infodate* Y)
{
    if (IsEmpty(*S))
    {
        *X = InfoTop(*S);
        *Y = InfoTopD(*S);

        Top(*S)--;
        
        if (Top(*S) == Nil)
        {
            Top(*S) = Nil;
        }
    }
>>>>>>> Stashed changes:src/ADT/stack.c
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */