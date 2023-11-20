#include <stdio.h>
#include "listStatikWord.h"

WrdType STATICMARK = {"",-1};

void SwCreateListStatik(ListStatikWord *l){
    int i;
    for(i=0;i<SCAPACITY;i++){
        SELMT(*l,i) = STATICMARK;
    }
}

int SwlistLength(ListStatikWord l){
    int i,hasil;
    hasil = 0;
    for(i=0;i<SCAPACITY;i++){
        if(SELMT(l,i).Length != STATICMARK.Length){
            hasil++;
        }
    }
    return hasil;

}

void SwdeleteVal(ListStatikWord * l, WrdType w){
    int i;
    int idx = IDX_UNDEF;
    for(i = 0; i< SwlistLength(*l);i++){
        if(isWordEqual(SELMT(*l,i),w)){
            idx = i;
            break;
        }
    }
    if(idx == IDX_UNDEF){
        printf("Orang Tidak Ditemukan\n");
    }
    else{
        WrdType temp;
        SwdeleteAt(l,&temp,idx);
    }
}

IdxType SwgetFirstIdx(ListStatikWord l){
    int i;
    if(SwlistLength(l)!=0){
        for(i = 0; i < SwlistLength(l); i++){
            if(SELMT(l,i).Length != STATICMARK.Length){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

IdxType SwgetLastIdx(ListStatikWord l){
    int i;
    if(SwlistLength(l)!=0){
        for(i = SwlistLength(l)-1; i >= 0; i--){
            if(SELMT(l,i).Length != STATICMARK.Length){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

boolean SwisIdxEff(ListStatikWord l, IdxType i){
    return (i >= 0 && i < SwlistLength(l));
}

boolean SwisEmpty(ListStatikWord l){
    return SwlistLength(l) == 0;
}

boolean SwisFull(ListStatikWord l){
    return SwlistLength(l) == SCAPACITY;
}

boolean SwisValExist(ListStatikWord l, WrdType w){
    int i;
    Word currWord;
    for (i = 0; i < SwlistLength(l); i++)
    {
        currWord = SELMT(l,i);
        if(isWordEqual(currWord, w)){
            return TRUE;
        }
    }
    return FALSE;
}


void SwprintList(ListStatikWord l){
    int i;
    printf("[");
    for(i = 0; i < SwlistLength(l); i++){
        if(SELMT(l,i).Length != STATICMARK.Length){
            printWord(SELMT(l,i));
        }
        if(i < SwlistLength(l)-1){
            printf(",");
        }
    }
    printf("]");
}

int SwindexOf(ListStatikWord l, WrdType val){
    int i;
    for(i=SwgetFirstIdx(l);i<SwlistLength(l);i++){
        if(isWordEqual(SELMT(l,i), val)){
            return i;
        }
    }
    return IDX_UNDEF;
}


void SwinsertFirst(ListStatikWord *l, WrdType val){
    ListStatikWord l1;
    int i;
    SwCreateListStatik(&l1);
    
    SELMT(l1,0) = val;
    for(i = 0; i < SwlistLength(*l); i++){
        SELMT(l1,i+1) = SELMT(*l,i);
    }
    *l = l1;
}

void SwinsertAt(ListStatikWord *l, WrdType val, IdxType idx){
    int i;
    ListStatikWord l1;
    SwCreateListStatik(&l1);
    for(i = 0; i < idx; i++){
        SELMT(l1,i) = SELMT(*l,i);
    }
    for(i = idx; i <= SwgetLastIdx(*l); i++){
        SELMT(l1, i+1) = SELMT(*l,i);
    }
    SELMT(l1,idx) = val;
    *l = l1;
}

void SwdeleteFirst(ListStatikWord *l, WrdType *val){
    int i;
    *val = SELMT(*l,SwgetFirstIdx(*l));
    for(i =SwgetFirstIdx(*l); i<SwlistLength(*l); i++){
        SELMT(*l,i) = SELMT(*l,i+1);
    }
    SELMT(*l,SwgetLastIdx(*l) + 1) = STATICMARK;
    
}

void SwinsertLast(ListStatikWord *l, WrdType val){
    SELMT(*l,SwlistLength(*l)) = val;
}
void SwdeleteAt(ListStatikWord *l, WrdType *val, IdxType idx){
    int i,k;
    ListStatikWord l1;
    SwCreateListStatik(&l1);
    *val = SELMT(*l,idx);

    k = 0;
    for(i = 0; i < SwlistLength(*l);i++){
        if(i != idx){
            SELMT(l1,k) = SELMT(*l,i);
            k++;
        }
        
    }
    *l = l1;
}

void SwdeleteLast(ListStatikWord *l, WrdType *val){
    *val = SELMT(*l, SwgetLastIdx(*l));
    SELMT(*l,SwgetLastIdx(*l)) = STATICMARK;
}



