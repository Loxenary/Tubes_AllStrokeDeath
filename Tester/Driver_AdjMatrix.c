#include <stdio.h>

#include "./src/adt/adjacency_Matrix.h"

#include "./src/adt/wordmachine.c"
#include "./src/adt/adjacency_Matrix.c"
#include "./src/adt/charmachine.c"

int main(){
    AdjMatrix m;
    
    printf("Test1 : Create a new Adj Matrix\n");
    CreateAdjMatrix(&m, 3);
    PrintAdjMatrix(m);

    printf("Test2 : Add a connection of index 1 and 2 \n");
    AddEdge(&m,1,2);
    PrintAdjMatrix(m);

    printf("Test3 : Add a connection of index 0 and 1\n");
    AddEdge(&m,0,1);
    PrintAdjMatrix(m);

    printf("Test4 : Delete a connection of 1 and 2\n");
    deleteEdge(&m,1,2);    
    PrintAdjMatrix(m);

    printf("Test 5: input a Word into Adj Matrix per line\n");

    printf("New Matrix 4x4 \n");
    AdjMatrix m2;
    CreateAdjMatrix(&m2,4);
    PrintAdjMatrix(m2);
    int i;
    for(i = 0; i < 4; i++){
        STARTWORD();
        printf("Line : %d\n",i+1);
        WordToAdjMatrix(&m2, currentWord,i);
        PrintAdjMatrix(m2);
    }
    return 0;
}