#include <stdio.h>
#include "liststatik.h"


void CreateListStatik(ListStatik *l){
    int i;
    for(i=0;i<CAPACITY;i++){
        ELMT(*l,i) = MARK;
    }
}

int listLength(ListStatik l){
    int i,hasil;
    hasil = 0;
    for(i=0;i<CAPACITY;i++){
        if(ELMT(l,i) != MARK){
            hasil++;
        }
    }
    return hasil;
}

IdxType getFirstIdx(ListStatik l){
    int i;
    if(listLength(l)!=0){
        for(i = 0; i < listLength(l); i++){
            if(ELMT(l,i) != MARK){
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

IdxType getLastIdx(ListStatik l){
    int i;
    if(listLength(l)!=0){
        for(i = listLength(l)-1; i >= 0; i--){
            if(ELMT(l,i) != MARK){
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

boolean isIdxValid(ListStatik l, IdxType i){
    return (i >= 0 && i < CAPACITY);
}
boolean isIdxEff(ListStatik l, IdxType i){
    return (i >= 0 && i < listLength(l));
}

boolean isEmpty(ListStatik l){
    return listLength(l) == 0;
}

boolean isFull(ListStatik l){
    return listLength(l) == CAPACITY;
}

void readList(ListStatik *l){
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

void printList(ListStatik l){
    int i;
    printf("[");
    for(i = 0; i < listLength(l); i++){
        if(ELMT(l,i) != MARK){
            printf("%d", ELMT(l,i));
        }
        if(i < listLength(l)-1){
            printf(",");
        }
    }
    printf("]");
}


ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik lcopy;
    CreateListStatik(&lcopy);
    int i;
    lcopy = l1;
    if(listLength(l1) == listLength(l2)){
        if(plus){
            for(i=0;i<listLength(l1);i++){
                ELMT(lcopy,i) = ELMT(l1,i) + ELMT(l2,i);
                
            }
        }
        else{
            for(i=0;i<listLength(l1);i++){
                ELMT(lcopy,i) = ELMT(l1,i) - ELMT(l2,i);
                
            }
        }
    }
    return lcopy;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    int i;
    if(listLength(l1) != listLength(l2)){
        return 0;
    }
    for(i=0;i<listLength(l1);i++){
        if(ELMT(l1,i) != ELMT(l2,i)){
            return 0;
        }
    }
    return 1;
    
}

int indexOf(ListStatik l, ElType val){
    int i;
    for(i=getFirstIdx(l);i<listLength(l);i++){
        if(ELMT(l,i) == val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    *max = ELMT(l, getFirstIdx(l));
    *min = ELMT(l, getFirstIdx(l));
    int i;
    for(i=getFirstIdx(l); i<listLength(l);i++){
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
    for(i = 0; i < listLength(*l); i++){
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
    for(i = idx; i <= getLastIdx(*l); i++){
        ELMT(l1, i+1) = ELMT(*l,i);
    }
    ELMT(l1,idx) = val;
    *l = l1;
}

void deleteFirst(ListStatik *l, ElType *val){
    int i;
    *val = ELMT(*l,getFirstIdx(*l));
    for(i =getFirstIdx(*l); i<listLength(*l); i++){
        ELMT(*l,i) = ELMT(*l,i+1);
    }
    ELMT(*l,getLastIdx(*l) + 1) = MARK;
    
}

void insertLast(ListStatik *l, ElType val){
    ELMT(*l,listLength(*l)) = val;
}
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    int i,k;
    ListStatik l1;
    CreateListStatik(&l1);
    *val = ELMT(*l,idx);

    k = 0;
    for(i = 0; i < listLength(*l);i++){
        if(i != idx){
            ELMT(l1,k) = ELMT(*l,i);
            k++;
        }
        
    }
    *l = l1;
}

void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    ELMT(*l,getLastIdx(*l)) = MARK;
}


void sortList(ListStatik *l, boolean asc){
    int i,j, temp;

    if(asc){
        for(i = 0; i < listLength(*l); i++){
            for(j = i+1; j < listLength(*l); j++){
                if(ELMT(*l,i) > ELMT(*l,j)){
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            }
        }
    }
    else{
        for(i = 0; i < listLength(*l); i++){
            for(j = i+1; j < listLength(*l); j++){
                if(ELMT(*l,i) < ELMT(*l,j)){
                    temp = ELMT(*l,i);
                    ELMT(*l,i) = ELMT(*l,j);
                    ELMT(*l,j) = temp;
                }
            }
        }
    }
}


