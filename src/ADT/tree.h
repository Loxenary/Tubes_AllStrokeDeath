/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "boolean.h"
#include "datetime.h"
#include "wordmachine.h"
#include "../kicau.h"
/*  Kamus Umum */

/* Definisi Type Data */

typedef int IDType;
typedef Word WordType;

typedef struct tNode* addressTree;
typedef struct tNode {
    int BID;
    int RID;
    Word BAuth;
    DATETIME Bdates;
    Word BText;
    addressTree firstChild;
    addressTree nextSibling;
} Node;

typedef struct {
    addressTree root;
} Tree;

// Balasan
#define BID(P) (P)->BID
#define RID(P) (P)->RID
#define BAUTH(P) (P)->BAuth
#define BDATE(P) (P)->Bdates
#define BTEXT(P) (P)->BText
#define FirstChild(P) (P)->firstChild
#define NextSibling(P) (P)->nextSibling
#define Root(T) (T).root

/* Manajemen Memory */
addressTree newTNODE(IDType ID, WordType Word);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, Node dibuat dengan ID = ID, dan semua pointer diset NULL */
/* Jika alokasi gagal, mengirimkan NULL */

addressTree newTNODEConfig(IDType ID, WordType word,WordType Auth, DATETIME Date);

void dealocateTNODE(addressTree P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */

/* *** Konstruktor *** */
void createTree(Tree *T,kicauan kicau);
/* Mengirimkan sebuah pohon dengan satu elemen dengan ID = ID */

void AddChildMinSatu(Tree *T, IDType IDParent, IDType IDChild, Word word);

void AddChild(Tree *T,IDType IDParent, IDType IDChild,Word word);
/* Mengadakan seorang anak dengan ID = IDChild dari seorang induk dengan ID = IDParent pada pohon T */
/* I.S. T tidak kosong. IDChild dan IDParent adalah elemen terdefinisi, IDParent harus ada dalam T, IDChild belum ada */
/* F.S. Sebuah node dengan ID = IDChild dan Parent bertambah satu node */
void AddChildConfig(Tree *T, IDType IDParent, IDType IDChild, Word Text,DATETIME date,WordType Auth,IDType id_b);

addressTree findParent(addressTree root, IDType targetID);

void DelChild(Tree *T, IDType IDParent, IDType IDChild);
/* Menghapus seorang anak dengan ID = IDChild dari seorang induk dengan ID = IDParent pada pohon T */
/* I.S. T tidak kosong, IDChild dan IDParent adalah elemen terdefinisi */
/* F.S. Node dengan ID = IDChild dan semua subtree yang dimilikinya dihapus dari pohon */

/* *** Operasi lain *** */
addressTree SearchTNode(addressTree root, IDType ID);
/* Mengirimkan address node dengan ID = ID jika ditemukan, mengirimkan NULL jika tidak ditemukan */

addressTree SearchTNodeWithoutRoot(addressTree root, IDType ID);

boolean hasChild(Tree T);

boolean IsTreeEmpty(Tree T);
/* Mengirimkan true jika pohon T kosong */

boolean IsOneElmt(Tree T);
/* Mengirimkan true jika pohon T hanya memiliki 1 elemen */

boolean IsLeaf(Tree T, IDType ID);
/* Mengirimkan true jika ID adalah elemen paling bawah dari pohon T */

boolean IsRoot(Tree T, IDType ID);
/* Mengirimkan true jika ID adalah elemen root dari pohon T */

void displayTreeLevel(addressTree node, int tingkatan);
/* Formatting tree */
void displayTreeLevelBalasan(addressTree node, int tingkatan);
/* Formatting Balasan */          

void displayTreeFull(Tree T);
/* Mencetak Full biasa tanpa memperhatikan teman */
void displayTreeFullBalasan(Tree T);
/* Mencetak Full dengan memperhatikan teman*/
IDType searchIDmax(addressTree p);

IDType searchIDmaxWithoutRootId(addressTree p);

#endif 