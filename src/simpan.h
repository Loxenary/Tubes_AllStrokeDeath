#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "./adt/wordmachine.h"
#include "./adt/boolean.h"
#include "./adt/matrixchar.h"
#include "./adt/prioqueue.h"
#include "./adt/adjacency_Matrix.h"
void copyPath(char * dest, char * src);

boolean isDirectoryExists(const char *path);


int stringLength(char * string);

int createDirectory(char *path);

void saveBalasan(Word folder_path);

void saveDraf(Word folder_path);

void saveUtas(Word folder_path);

void saveKicauan(Word folder_path);

void savePengguna(Word folder_path);

void writeFile(Word w1,FILE *f);

void Simpan();

void writeMatrixChar(MatrixChar m, FILE *f);

void readPrivatePublic(int i, FILE *f);

void writeDinFile(WordDin w1, FILE *f);

void writeAdjMatrix(AdjMatrix m, FILE *f);

void writePermintaanTeman(PrioQueue p, FILE *f);

char * WordToString(Word w);

char * copyString(char * src);

char * concadString(char * dest, char * src);