#ifndef __TEMAN
#define __TEMAN

#include "Database.h"
#include "boolean.h"

int jumlah_Teman(AdjMatrix m, int idx);

AdjMatrix Mat_Teman();

boolean isTeman(AdjMatrix *m, int user1, int user2);

boolean isHapus(Word w);
//True jika menjawab YES, false jika menjawab NO

void Daftar_Teman(ListStatikWord dataTeman);
// void Daftar_Teman(AdjMatrix m);
//I.S. dataTeman adalah list yang terdefinisi, bisa empty
//F.S. menampilkan daftar teman sesuai spesifikasi

void Hapus_Teman(ListStatikWord* dataTeman);
//I.S. dataTeman adalah list yang terdefinisi, tidak kosong
//F.S. akan mengurangi teman sesuai dengan nama yang dicari

#endif