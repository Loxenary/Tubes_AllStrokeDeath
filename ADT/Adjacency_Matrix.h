#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include "boolean.h"

typedef int** Mats;
typedef struct
{
    int Vertices; /*Jumlah Vertices yang dapat ditampung*/
    Mats adjacencyMatrix; /*2D array untuk menyimpan adjacency matrix*/
} AdjMatrix;

#define MAT(m) (m).adjacencyMatrix
#define Vert(m) (m).Vertices
#define GELMT(graph,i,j) ((graph) -> adjacencyMatrix[i][j])

void CreateAdjMatrix(AdjMatrix *m, int Vertices);

void AddEdge(AdjMatrix * m, int u, int v);

void DeleteAdjGraph(AdjMatrix * m);

#endif
