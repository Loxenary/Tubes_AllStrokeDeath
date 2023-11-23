#include <stdio.h>

#include "../src/adt/adjacency_Matrix.h"
#include "../src/adt/wordmachine.h"

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
    DeleteEdge(&m,1,2);    
    PrintAdjMatrix(m);

    printf("Test 5: Expand Matrix to 7 x 7\n");
    expandAdjMatrix(&m,4);
    PrintAdjMatrix(m);


    printf("Test 6: input a Word into Adj Matrix per line\n");
    printf("New Matrix 4x4 \n");
    AdjMatrix m2;
    CreateAdjMatrix(&m2,4);
    PrintAdjMatrix(m2);

    printf("Input:\n");
    
    char* l1 = "1 0 1 0";
    char* l2 = "0 1 0 0";
    char* l3 = "1 0 1 0";
    char* l4 = "0 0 0 1";
    Word wl1,wl2,wl3,wl4;
    wl1 = StringToWord(l1,8);
   
    wl2 = StringToWord(l2,8);
    wl3 = StringToWord(l3,8);
    wl4 = StringToWord(l4,8);
    printf("This is as a word\n");
    printf("Word 1: \n");
    printWord(wl1); printf("\n");
    printf("Word 1: \n");
    printWord(wl2); printf("\n");
    printf("Word 1: \n");
    printWord(wl3); printf("\n");
    printf("Word 1: \n");
    printWord(wl4); printf("\n");
    printf("Output:\n");
    int i;
    WordToAdjMatrix(&m2,wl1,0);
    WordToAdjMatrix(&m2,wl2,1);
    WordToAdjMatrix(&m2,wl3,2);
    WordToAdjMatrix(&m2,wl4,3);
    PrintAdjMatrix(m2);

    return 0;
}