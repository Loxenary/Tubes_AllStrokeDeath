#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"
#include "ListDinWord.h"

/* Konstruktor : create list kosong  */
void DWCreateListWord(ListWord *l, int DCAPACITY){
    DBUFFER(*l) = (WrdType*)malloc(DCAPACITY*sizeof(WrdType));
    DNEFF(*l) = 0;
    DCAPACITY(*l) = DCAPACITY;
}
/* I.S. l sembarang, DCAPACITY > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas DCAPACITY */

void DWdealocateList(ListWord *l){
    free(DBUFFER(*l));
    DCAPACITY(*l) = 0;
    DNEFF(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, DCAPACITY(l)=0; DNEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int DWlistLength(ListWord l){
    return DNEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

char* WordToChr(Word word){
    int i;
    char* chr = malloc(word.Length + 1);
    for (i = 0; i < word.Length; i++)
    {
        chr[i] = word.TabWord[i];
    }
    chr[word.Length] = '\0';
    return chr;
}


void DWprintList(ListWord l){
      int i;
      printf("[");
      for(i = 0; i < DWlistLength(l); i++){
            if(i != DWlistLength(l)-1){
                printWord(DELMT(l,i));
                printf(",");
            }
            else{
                  printWord(DELMT(l,i));
            }
      }
      printf("]");
}

boolean isWordEqual(WrdType w1, WrdType w2){
    int i;
    if(w1.Length != w2.Length){
        return FALSE;
    }
    else{
        for (i = 0; i < w1.Length; i++)
        {
            if(w1.TabWord[i] != w2.TabWord[i]){
                return FALSE;
            }
        }
        return TRUE;
        
    }
}

boolean DWisValExist(ListWord l, WrdType w){
    int i;
    Word currWord;
    for (i = 0; i < DWlistLength(l); i++)
    {
        currWord = DELMT(l,i);
        if(isWordEqual(currWord, w)){
            return TRUE;
        }
    }
    return FALSE;
}
/* Mengirimkan true jika w terdifinisi dalam l*/
/* Yaitu terdapat suatu nama w yang berada dalam list word l*/
/* *** Selektor INDEKS *** */

void DWdeleteVal(ListWord * l, WrdType w){
    int i;
    int idx = IDX_UNDEF;
    for(i = 0; i< DWlistLength(*l);i++){
        if(isWordEqual(DELMT(*l,i),w)){
            idx = i;
            break;
        }
    }
    if(idx == IDX_UNDEF){
        printf("Orang Tidak Ditemukan\n");
    }
    else{
        for (i = idx; i < DWlistLength(*l) - 1; i++) {
            DELMT(*l, i) = DELMT(*l, i + 1);
        }
        DNEFF(*l)--;
    }
}
/* Menghapus w dari *l, dan w harus terdefinisi*/
/* Jika w tidak terdefinisi maka akan mengirim pesan error*/
void DWinsertLast(ListWord *l, WrdType val){
      
      DNEFF(*l)++;
      DELMT(*l,DWlistLength(*l)-1) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

void DWdeleteLast(ListWord *l, WrdType *val){
    *val = DELMT(*l,DNEFF(*l)-1);
    
    DNEFF(*l)--;
}
void DWexpandList(ListWord *l, int num)
{
    DCAPACITY(*l)+= num;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */