#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l){
    int i;
    for(i=0;i<CAPACITY;i++){
        ELMT(*l,i) = SMARK;
    }
}

int SlistLength(ListStatik l){
    int i,hasil;
    hasil = 0;
    for(i=0;i<CAPACITY;i++){
        if(ELMT(l,i) != SMARK){
            hasil++;
        }
    }
    return hasil;
}

IdxType SgetFirstIdx(ListStatik l){
    int i;
    if(SlistLength(l)!=0){
        for(i = 0; i < SlistLength(l); i++){
            if(ELMT(l,i) != SMARK){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

IdxType SgetLastIdx(ListStatik l){
    int i;
    if(SlistLength(l)!=0){
        for(i = SlistLength(l)-1; i >= 0; i--){
            if(ELMT(l,i) != SMARK){
                return i;
            }
        }
    }
    return IDX_UNDEF;
}

boolean SisIdxValid(ListStatik l, IdxType i){
    return (i >= 0 && i < CAPACITY);
}
boolean SisIdxEff(ListStatik l, IdxType i){
    return (i >= 0 && i < SlistLength(l));
}

boolean SisEmpty(ListStatik l){
    return SlistLength(l) == 0;
}

boolean SisFull(ListStatik l){
    return SlistLength(l) == CAPACITY;
}

void SreadList(ListStatik *l){
    ListStatik l1;
    int n, i;
    CreateListStatik(&l1);
    scanf("%d",&n);
    while(n < 0 || n > CAPACITY){
        scanf("%d",&n);
    }
    for(i =0; i < n; i++){
        scanf("%d",&ELMT(l1,i));
    }

    *l = l1;
}

void SprintList(ListStatik l){
    int i;
    printf("[");
    for(i = 0; i < SlistLength(l); i++){
        if(ELMT(l,i) != SMARK){
            printf("%d", ELMT(l,i));
        }
        if(i < SlistLength(l)-1){
            printf(",");
        }
    }
    printf("]");
}


ListStatik SplusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik lcopy;
    CreateListStatik(&lcopy);
    int i;
    lcopy = l1;
    if(SlistLength(l1) == SlistLength(l2)){
        if(plus){
            for(i=0;i<SlistLength(l1);i++){
                ELMT(lcopy,i) = ELMT(l1,i) + ELMT(l2,i);
                
            }
        }
        else{
            for(i=0;i<SlistLength(l1);i++){
                ELMT(lcopy,i) = ELMT(l1,i) - ELMT(l2,i);
                
            }
        }
    }
    return lcopy;
}

boolean SisListEqual(ListStatik l1, ListStatik l2){
    int i;
    if(SlistLength(l1) != SlistLength(l2)){
        return 0;
    }
    for(i=0;i<SlistLength(l1);i++){
        if(ELMT(l1,i) != ELMT(l2,i)){
            return 0;
        }
    }
    return 1;
    
}

int SindexOf(ListStatik l, ElType val){
    int i;
    for(i=SgetFirstIdx(l);i<SlistLength(l);i++){
        if(ELMT(l,i) == val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void SextremeValues(ListStatik l, ElType *max, ElType *min){
    *max = ELMT(l, SgetFirstIdx(l));
    *min = ELMT(l, SgetFirstIdx(l));
    int i;
    for(i=SgetFirstIdx(l); i<SlistLength(l);i++){
        if(*max < ELMT(l,i)){
            *max = ELMT(l,i);
        }
        if(*min > ELMT(l,i)){
            *min = ELMT(l,i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val){
    ListStatik l1;
    int i;
    CreateListStatik(&l1);
    
    ELMT(l1,0) = val;
    for(i = 0; i < SlistLength(*l); i++){
        ELMT(l1,i+1) = ELMT(*l,i);
    }
    *l = l1;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    int i;
    ListStatik l1;
    CreateListStatik(&l1);
    for(i = 0; i < idx; i++){
        ELMT(l1,i) = ELMT(*l,i);
    }
    for(i = idx; i <= SgetLastIdx(*l); i++){
        ELMT(l1, i+1) = ELMT(*l,i);
    }
    ELMT(l1,idx) = val;
    *l = l1;
}

void deleteFirst(ListStatik *l, ElType *val){
    int i;
    *val = ELMT(*l,SgetFirstIdx(*l));
    for(i =SgetFirstIdx(*l); i<SlistLength(*l); i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    ELMT(*l,SgetLastIdx(*l) + 1) = SMARK;
    
}

void SinsertLast(ListStatik *l, ElType val){
    ELMT(*l,SlistLength(*l)) = val;
}
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    int i,k;
    ListStatik l1;
    CreateListStatik(&l1);
    *val = ELMT(*l,idx);

    k = 0;
    for(i = 0; i < SlistLength(*l);i++){
        if(i != idx){
            ELMT(l1,k) = ELMT(*l,i);
            k++;
        }
        
    }
    *l = l1;
}

void SdeleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l, SgetLastIdx(*l));
    ELMT(*l,SgetLastIdx(*l)) = SMARK;
}


void sortList(ListStatik *l, boolean asc){
    int i,j, temp;

    if(asc){
        for(i = 0; i < SlistLength(*l); i++){
            for(j = i+1; j < SlistLength(*l); j++){
                if(ELMT(*l,i) > ELMT(*l,j)){
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            }
        }
    }
    else{
        for(i = 0; i < SlistLength(*l); i++){
            for(j = i+1; j < SlistLength(*l); j++){
                if(ELMT(*l,i) < ELMT(*l,j)){
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            }
        }
    }
}


