#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef struct
{
    float flo[ROW_CAP][COL_CAP];
    int rowEff;
    int colEff;
} FloatMatrix;

#define FELMT(M,i,j) (M).flo[(i)][(j)]

void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    int i,j;
    for(i = 0; i < nRows; i++){
        for(j = 0; j < nCols;j++){
            MELMT(*m,i,j) = 0;
        }
    }
}
boolean isMatrixIdxValid(int i, int j){
    return (i >= 0 && i <ROW_CAP && j >= 0 && j < COL_CAP);
}
IdxType getLastIdxRow(Matrix m){
    return ROW_EFF(m)-1;
}
IdxType getLastIdxCol(Matrix m){
    return COL_EFF(m)-1;
}
boolean MisIdxEff(Matrix m, IdxType i, IdxType j){
    return (i >= 0 && j>=0 && i < ROW_EFF(m) && j < COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i){
    return(MELMT(m,i,i));
}
void copyMatrix(Matrix mIn, Matrix *mOut){
    createMatrix(ROW_EFF(mIn),COL_EFF(mIn), mOut);
    int i,j;
    for(i = 0; i < ROW_EFF(mIn); i++){
        for(j = 0; j < COL_EFF(mIn);j++){
            MELMT(*mOut,i,j) = MELMT(mIn,i,j);
        }
    }
}
void readMatrix(Matrix *m, int nRow, int nCol){
    int i,j;
    createMatrix(nRow,nCol,m);
    for(i = 0; i < nRow; i++){
        for(j = 0; j < nCol; j++){
            scanf("%d",&MELMT(*m,i,j));
        }
    }
}
void displayMatrix(Matrix m){
    int i,j;
    for(i = 0; i <= getLastIdxRow(m); i++){
        for(j = 0; j <= getLastIdxCol(m); j++){
            if(j != getLastIdxRow(m)){
                printf("%d ",MELMT(m,i,j));
            }
            else{
                printf("%d",MELMT(m,i,j));
            }
        }
        if(i != getLastIdxRow(m)){
            printf("\n");

    }
    }
    printf("\n");
}
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix Mcopy;
    createMatrix(ROW_EFF(m1),COL_EFF(m1),&Mcopy);
    int i,j;
    for(i = 0; i<= getLastIdxRow(m1);i++){
        for(j = 0; j <= getLastIdxCol(m1);j++){
            MELMT(Mcopy,i,j) = MELMT(m1,i,j)+MELMT(m2,i,j);
        }
    }
    return Mcopy;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix Mcopy;
    createMatrix(ROW_EFF(m1),COL_EFF(m1),&Mcopy);
    int i,j;
    for(i = 0; i<= getLastIdxRow(m1);i++){
        for(j = 0; j <= getLastIdxCol(m1);j++){
            MELMT(Mcopy,i,j) = MELMT(m1,i,j) - MELMT(m2,i,j);
        }
    }
    return Mcopy;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix Mcopy;
    createMatrix(ROW_EFF(m1),COL_EFF(m1),&Mcopy);
    int i,j;
    for(i = 0; i<= getLastIdxRow(m1);i++){
        for(j = 0; j <= getLastIdxCol(m1);j++){
            MELMT(Mcopy,i,j) += MELMT(m1,i,j) * MELMT(m2,i,j);
        }
    }
    return Mcopy;
}
Matrix multiplyMatrixWithMod(Matrix m1,Matrix m2,int mod){
    Matrix Mcopy;
    createMatrix(ROW_EFF(m1),COL_EFF(m1),&Mcopy);
    int i,j;
    for(i = 0; i<= getLastIdxRow(m1);i++){
        for(j = 0; j <= getLastIdxCol(m1);j++){
            MELMT(Mcopy,i,j) += (MELMT(m1,i,j) * MELMT(m2,i,j))% mod;
        }
    }
    return Mcopy;
}
Matrix multiplyByConst(Matrix m, ElType x){
    Matrix Mcopy;
    createMatrix(ROW_EFF(m),COL_EFF(m),&Mcopy);
    int i,j;
    for(i = 0; i<= getLastIdxRow(m);i++){
        for(j = 0; j <= getLastIdxCol(m);j++){
            MELMT(Mcopy,i,j) = MELMT(m,i,j) * x;
        }
    }
    return Mcopy;
}
void pMultiplyByConst(Matrix *m, ElType k){
    int i ,j;
    for(i = 0; i<= getLastIdxRow(*m);i++){
        for(j = 0; j <= getLastIdxCol(*m);j++){
            MELMT(*m,i,j) *= k;
        }
    }
}
boolean isMatrixEqual(Matrix m1, Matrix m2){
    int i,j;
    if((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))){
        return 0;
    }
    else{
        for(i = 0; i <= getLastIdxRow(m1); i++){
            for(j = 0; j <= getLastIdxCol(m1); j++){
                if(MELMT(m1,i,j) != MELMT(m2,i,j)){
                    return 0;
                }
            }
        }
        return 1;
    }
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
    return !isMatrixEqual(m1,m2);
}
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
int countElmt(Matrix m){
    return (ROW_EFF(m) * COL_EFF(m));
}
boolean isSquare(Matrix m){
    return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m){
    if(!isSquare(m)){
        return 0;
    }
    else{
        int i,j;
        for(i = 0; i <= getLastIdxRow(m);i++){
            for(j = 0; j <= getLastIdxCol(m);j++){
                if(MELMT(m,i,j) != MELMT(m,j,i)){
                    return 0;
                }
            }
        }
        return 1;
    }
}
boolean isIdentity(Matrix m){
    int i,j;
    if(!isSquare(m)){
        return 0;
    }
    else{
        for(i = 0; i <= getLastIdxRow(m); i++){
            for(j = 0; j <= getLastIdxCol(m); j++){
                if((j != i)){
                    if(MELMT(m,i,j) != 0){
                        return 0;
                    }
                }
                
                else{
                    if(MELMT(m,i,j) != 1){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
}
boolean isSparse(Matrix m){
    int sum,i,j;
    sum = 0;
    for(i = 0; i <= getLastIdxRow(m);i++){
        for(j=0; j <= getLastIdxCol(m);j++){
            if(MELMT(m,i,j)!=0){
                sum+=1;
            }
        }
    }
    float max = (0.05 * countElmt(m));
    return (sum <= max);
}
Matrix negation(Matrix m){
    Matrix Mcopy;
    createMatrix(ROW_EFF(m),COL_EFF(m),&Mcopy);
    int i,j;
    for(i = 0; i <= getLastIdxRow(m);i++){
        for(j=0 ; j <= getLastIdxCol(m);j++){
            MELMT(Mcopy,i,j) = (-1) * MELMT(m,i,j);
        }
    }
    return Mcopy;
}
void pNegation(Matrix *m){
    int i,j;
    for(i = 0; i <= getLastIdxRow(*m);i++){
        for(j = 0; j <= getLastIdxCol(*m);j++){
            MELMT(*m,i,j) = (-1) * MELMT(*m,i,j);
        }
    }
}

void gaussianElimination(FloatMatrix *m, int row_change, int col_change, int row_changer){
    int i;
    float x = (float) FELMT(*m,row_change,col_change) / FELMT(*m,row_changer,col_change);
    for(i = 0; i < (*m).colEff; i++){
        FELMT(*m,row_change,i) -= ((float) x * FELMT(*m,row_changer,i));
    } 
}

void intTofloat(FloatMatrix *m1, Matrix m2){
    int i,j;
    for(i =0; i <= getLastIdxRow(m2);i++){
        for(j=0; j <= getLastIdxCol(m2);j++){
            FELMT(*m1,i,j) = (float) MELMT(m2,i,j);
        }
    }
}

float determinant(Matrix m){
    int i,j;
    FloatMatrix M2;
    (M2).colEff = COL_EFF(m);
    (M2).rowEff = ROW_EFF(m);
    intTofloat(&M2,m);
    if(isSquare(m)){
        for(i = 0; i < ROW_EFF(m); i++){
            for(j = i+1; j < ROW_EFF(m); j++){
                gaussianElimination(&M2,j,i,i);
            }
        }
    }
    float sum;
    sum = 1;
    for(i = 0; i <= getLastIdxRow(m);i++){
        for(j=0; j <= getLastIdxCol(m); j++){
            if(j == i){
                sum *= FELMT(M2,i,j);
            }
        }   
    }
    return sum;
}
Matrix transpose(Matrix m){
    Matrix Mcopy;
    int i,j;
    createMatrix(ROW_EFF(m),COL_EFF(m),&Mcopy);
    if(isSquare(m)){
        for(i = 0; i <= getLastIdxRow(m);i++){
            for(j =0; j <= getLastIdxCol(m); j++){
                MELMT(Mcopy,i,j) = MELMT(m,j,i);
            }
        }
    }
    return  Mcopy;
}
void pTranspose(Matrix *m){
    Matrix Mcopy;
    int i,j;
    copyMatrix(*m,&Mcopy);
    if(isSquare(*m)){
        for(i = 0; i <= getLastIdxRow(*m);i++){
            for(j =0; j <= getLastIdxCol(*m); j++){
                MELMT(*m,i,j) = MELMT(Mcopy,j,i);
            }
        }
    }
}
