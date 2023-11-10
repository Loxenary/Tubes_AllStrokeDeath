#include <stdio.h>
#include <stdlib.h>

#include "Adjacency_Matrix.h"

void CreateAdjMatrix(AdjMatrix *m , int Vertices){
    Vert(*m) = Vertices;

    //Memory Allocate
    MAT(*m) = (int**)malloc(Vertices * sizeof(int*));
    if(MAT(*m) != NULL){
        int i,j;
        for(i = 0; i < Vertices; i++){
            for(j =0; j < Vertices;j++){
                GELMT(m,i,j) = 0;
            }
        }
   
    }
 
}

void AddEdge(AdjMatrix *m, int u, int v){
    GELMT(m,u,v) = 1;
}

void DeleteAdjGraph(AdjMatrix * m){
    int i;
    for(i = 0; i < Vert(*m);i++){
        free(MAT(*m)[i]);
    }
    free(MAT(*m));
    Vert(*m) = 0;
}
