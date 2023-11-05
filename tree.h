/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "boolean.h"
#include "liststatik.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "matrix.h"

/*  Kamus Umum */
/* Kapasitas penyimpanan */
#define CAPACITY 100

/* Definisi Type Data */
typedef int ElType;
typedef struct tNode *addressTree;
typedef struct tNode {
    int ID;
    addressTree firstChild;
    addressTree nextSibling;
} Node;

typedef struct {
    addressTree root;
} Tree;

typedef Tree ListTreeStatik_ElType;
typedef int ListTreeStatik_IdxType;
typedef struct {
    ListTreeStatik_ElType contents[CAPACITY];
} ListTreeStatik;


#define ID(P) (P)->ID
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Root(T) (T).root
#define LISTELMT(l, i) (l).contents[(i)]

/* Manajemen Memory */
addressTree newTNODE(ElType ID);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, Node dibuat dengan ID = ID, dan semua pointer diset NULL */
/* Jika alokasi gagal, mengirimkan NULL */

void dealocateTNODE(addressTree P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */

/* *** Konstruktor *** */
void createTree(Tree *T,ElType ID);
/* Mengirimkan sebuah pohon dengan satu elemen dengan ID = ID */

void AddChild(ElType IDParent, ElType IDChild, Tree* T);
/* Mengadakan seorang anak dengan ID = IDChild dari seorang induk dengan ID = IDParent pada pohon T */
/* I.S. T tidak kosong. IDChild dan IDParent adalah elemen terdefinisi, IDParent harus ada dalam T, IDChild belum ada */
/* F.S. Sebuah node dengan ID = IDChild dan Parent bertambah satu node */

void DelChild(ElType IDParent, ElType IDChild, Tree* T);
/* Menghapus seorang anak dengan ID = IDChild dari seorang induk dengan ID = IDParent pada pohon T */
/* I.S. T tidak kosong, IDChild dan IDParent adalah elemen terdefinisi */
/* F.S. Node dengan ID = IDChild dan semua subtree yang dimilikinya dihapus dari pohon */

/* *** Operasi lain *** */
addressTree SearchTNode(Tree T, ElType ID);
/* Mengirimkan address node dengan ID = ID jika ditemukan, mengirimkan NULL jika tidak ditemukan */

int NbElmt(Tree T);
/* Mengirimkan banyaknya elemen (node) pohon T */

int MaxNbElmt(Tree T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh pohon T */

boolean IsTreeEmpty(Tree T);
/* Mengirimkan true jika pohon T kosong */

boolean IsOneElmt(Tree T);
/* Mengirimkan true jika pohon T hanya memiliki 1 elemen */

boolean IsLeaf(Tree T, ElType ID);
/* Mengirimkan true jika ID adalah elemen paling bawah dari pohon T */

boolean IsRoot(Tree T, ElType ID);
/* Mengirimkan true jika ID adalah elemen root dari pohon T */

void displayTree(addressTree node, int depth);
/* Mencetak Tree di terminal */

#endif