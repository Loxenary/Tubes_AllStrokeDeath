#include <stdio.h>
#include "listStatikWordDin.h"

WrdDinType STATICMARKDIN = {"",-1};

void SwdCreateListStatik(ListStatikWordDin *l){
    int i;
    for(i=0;i<SCAPACITY;i++){
        LSWDELMT(*l,i) = STATICMARKDIN;
    }
}

// void SwCreateListStatikWrdDin(ListStatikWordDin *l){
//     l->neff = 0;
// }

int SwdlistLength(ListStatikWordDin l){
    int i,hasil;
    hasil = 0;
    for(i=0;i<SCAPACITY;i++){
        if(LSWDELMT(l,i).Length != STATICMARKDIN.Length){
            hasil++;
        }
    }
    return hasil;

}

void SwddeleteVal(ListStatikWordDin * l, WrdDinType w){
    int i;
    int idx = IDX_UNDEF;
    for(i = 0; i< SwdlistLength(*l);i++){
        if(isWordDinEqual(LSWDELMT(*l,i),w)){
            idx = i;
            break;
        }
    }
    if(idx == IDX_UNDEF){
        printf("Orang Tidak Ditemukan\n");
    }
    else{
        WrdDinType temp;
        SwddeleteAt(l,&temp,idx);
    }
}

IdxType SwdgetFirstIdx(ListStatikWordDin l){
    int i;
    if(SwdlistLength(l)!=0){
        for(i = 0; i < SwdlistLength(l); i++){
            if(LSWDELMT(l,i).Length != STATICMARKDIN.Length){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

IdxType SwdgetLastIdx(ListStatikWordDin l){
    int i;
    if(SwdlistLength(l)!=0){
        for(i = SwdlistLength(l)-1; i >= 0; i--){
            if(LSWDELMT(l,i).Length != STATICMARKDIN.Length){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

boolean SwdisIdxEff(ListStatikWordDin l, IdxType i){
    return (i >= 0 && i < SwdlistLength(l));
}

boolean SwdisEmpty(ListStatikWordDin l){
    return SwdlistLength(l) == 0;
}

boolean SwdisFull(ListStatikWordDin l){
    return SwdlistLength(l) == SCAPACITY;
}

boolean SwdisValExist(ListStatikWordDin l, WrdDinType w){
    int i;
    WordDin currWord;
    for (i = 0; i < SwdlistLength(l); i++)
    {
        currWord = LSWDELMT(l,i);
        if(isWordDinEqual(currWord, w)){
            return TRUE;
        }
    }
    return FALSE;
}


void SwdprintList(ListStatikWordDin l){
    int i;
    printf("[");
    for(i = 0; i < SwdlistLength(l); i++){
        if(LSWDELMT(l,i).Length != STATICMARKDIN.Length){
            printWordDin(LSWDELMT(l,i));
        }
        if(i < SwdlistLength(l)-1){
            printf(",");
        }
    }
    printf("]");
}

int SwdindexOf(ListStatikWordDin l, WrdDinType val){
    int i;
    for(i=SwdgetFirstIdx(l);i<SwdlistLength(l);i++){
        if(isWordDinEqual(LSWDELMT(l,i), val)){
            return i;
        }
    }
    return IDX_UNDEF;
}


void SwdinsertFirst(ListStatikWordDin *l, WrdDinType val){
    ListStatikWordDin l1;
    int i;
    SwdCreateListStatik(&l1);
    
    LSWDELMT(l1,0) = val;
    for(i = 0; i < SwdlistLength(*l); i++){
        LSWDELMT(l1,i+1) = LSWDELMT(*l,i);
    }
    *l = l1;
}

void SwdinsertAt(ListStatikWordDin *l, WrdDinType val, IdxType idx){
    int i;
    ListStatikWordDin l1;
    SwdCreateListStatik(&l1);
    for(i = 0; i < idx; i++){
        LSWDELMT(l1,i) = LSWDELMT(*l,i);
    }
    for(i = idx; i <= SwdgetLastIdx(*l); i++){
        LSWDELMT(l1, i+1) = LSWDELMT(*l,i);
    }
    LSWDELMT(l1,idx) = val;
    *l = l1;
}

// void SwinsertLastWordDin(ListStatikWordDin *l, WordDin val)
// {
//     LSWDELMTD(*l,l->neff-1) = val;
//     l->neff++;
// }

void SwddeleteFirst(ListStatikWordDin *l, WrdDinType *val)
{
    int i;
    *val = LSWDELMT(*l,SwdgetFirstIdx(*l));
    for(i =SwdgetFirstIdx(*l); i<SwdlistLength(*l); i++){
        LSWDELMT(*l,i) = LSWDELMT(*l,i+1);
    }
    LSWDELMT(*l,SwdgetLastIdx(*l) + 1) = STATICMARKDIN;
}

void SwdinsertLast(ListStatikWordDin *l, WrdDinType val){
    LSWDELMT(*l,SwdlistLength(*l)) = val;
}
void SwddeleteAt(ListStatikWordDin *l, WrdDinType *val, IdxType idx){
    int i,k;
    ListStatikWordDin l1;
    SwdCreateListStatik(&l1);
    *val = LSWDELMT(*l,idx);

    k = 0;
    for(i = 0; i < SwdlistLength(*l);i++){
        if(i != idx){
            LSWDELMT(l1,k) = LSWDELMT(*l,i);
            k++;
        }
        
    }
    *l = l1;
}

void SwddeleteLast(ListStatikWordDin *l, WrdDinType *val){
    *val = LSWDELMT(*l, SwdgetLastIdx(*l));
    LSWDELMT(*l,SwdgetLastIdx(*l)) = STATICMARKDIN;
}



