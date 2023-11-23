#include <stdio.h>
#include <stdlib.h>
#include "adjacency_Matrix.h"


void CreateAdjMatrix(AdjMatrix *m , int Vertices){
    Vert(*m) = Vertices;
    //Memory Allocate
    MAT(*m) = (int**)malloc(Vertices * sizeof(int*));
    if(MAT(*m) != NULL){
        int i,j;
        for(i = 0; i < Vertices; i++){
            MAT(*m)[i] = (int *)malloc(Vertices * sizeof(int));
            for(j =0; j < Vertices;j++){
                GELMT(m,i,j) = 0;
            }
        }
    }
}

void AddEdge(AdjMatrix *m, int u, int v){
    GELMT(m,u,v) = 1;
    GELMT(m,v,u) = 1;
}

void DeleteEdge(AdjMatrix *m, int u , int v){\
    GELMT(m,u,v) = 0;
    GELMT(m,v,u) = 0;
}
void WordToAdjMatrix(AdjMatrix *m, Word currentWord, int idx){
    int i;
    for(i = 0; i < currentWord.Length; i+=2){
        int temp = currentWord.TabWord[i] - 48;
        int idx_temp = (i / 2);
        if(temp == 1){
            AddEdge(m,idx,idx_temp);
        }
    }
}

void PrintAdjMatrix(AdjMatrix m){
    int i,j;
    for(i = 0; i < Vert(m);i++){
        for(j = 0; j < Vert(m); j++){
            printf("%d",GGELMT(m,i,j)); 
            if(j < Vert(m)-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}
void expandAdjMatrix(AdjMatrix *m, int Additional){

    AdjMatrix temps;
    CreateAdjMatrix(&temps,m->Vertices + Additional);
    int i,j;
    for(i = 0; i < m->Vertices; i++){
        for(j = 0; j < m->Vertices; j++){
            GELMT(&temps,i,j) = GELMT(m,i,j);
        }
    }
    *m = temps;
}