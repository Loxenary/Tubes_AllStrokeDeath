#ifndef __TEMAN
#define __TEMAN

#include "./adt/boolean.h"
#include "./adt/adjacency_Matrix.h"
#include "./adt/listStatikWord.h"
#include "./adt/wordmachine.h"

int jumlah_Teman(AdjMatrix m, int idx);

ListStatikWord ListTeman(AdjMatrix m, int idx);

boolean isTeman(AdjMatrix TemanMat, Word user1, Word user2);
//True jika user 1 dan user 2 berteman

boolean isHapus(Word w);
//True jika menjawab YES, false jika menjawab NO

void Daftar_Teman(AdjMatrix dataTeman);
// void Daftar_Teman(AdjMatrix m);
//I.S. dataTeman adalah list yang terdefinisi, bisa empty
//F.S. menampilkan daftar teman sesuai spesifikasi

void Hapus_Teman(AdjMatrix* dataTeman);
//I.S. dataTeman adalah list yang terdefinisi, tidak kosong
//F.S. akan mengurangi teman sesuai dengan nama yang dicari


#endif