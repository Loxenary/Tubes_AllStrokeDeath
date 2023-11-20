/* ADT N-ARY TREE */

#ifndef TREE_H
#define TREE_H

#include "./adt/boolean.h"
#include "./adt/wordmachine.h"
#include "./adt/datetime.h"
#include "./kicau.h"


/*  Kamus Umum */

/* Definisi Type Data */

typedef int IDType;
typedef Word WordType;

typedef struct tNode* addressTree;
typedef struct tNode {
    int BID;
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

void dealocateTNODE(addressTree P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */

/* *** Konstruktor *** */
void createTree(Tree *T,kicauan kicau);
/* Mengirimkan sebuah pohon dengan satu elemen dengan ID = ID */

void AddChild(Tree *T,IDType IDParent, IDType IDChild,Word word);
/* Mengadakan seorang anak dengan ID = IDChild dari seorang induk dengan ID = IDParent pada pohon T */
/* I.S. T tidak kosong. IDChild dan IDParent adalah elemen terdefinisi, IDParent harus ada dalam T, IDChild belum ada */
/* F.S. Sebuah node dengan ID = IDChild dan Parent bertambah satu node */

void DelChild(Tree *T, IDType IDParent, IDType IDChild);
/* Menghapus seorang anak dengan ID = IDChild dari seorang induk dengan ID = IDParent pada pohon T */
/* I.S. T tidak kosong, IDChild dan IDParent adalah elemen terdefinisi */
/* F.S. Node dengan ID = IDChild dan semua subtree yang dimilikinya dihapus dari pohon */

/* *** Operasi lain *** */
addressTree SearchTNode(Tree T, IDType ID);
/* Mengirimkan address node dengan ID = ID jika ditemukan, mengirimkan NULL jika tidak ditemukan */

boolean IsTreeEmpty(Tree T);
/* Mengirimkan true jika pohon T kosong */

boolean IsOneElmt(Tree T);
/* Mengirimkan true jika pohon T hanya memiliki 1 elemen */

boolean IsLeaf(Tree T, IDType ID);
/* Mengirimkan true jika ID adalah elemen paling bawah dari pohon T */

boolean IsRoot(Tree T, IDType ID);
/* Mengirimkan true jika ID adalah elemen root dari pohon T */

void displayTreeLevel(addressTree node, int tingkatan);
/* Mencetak Tree di terminal */          

void displayTreeFull(Tree T);

IDType searchIDmax(addressTree p);

#endif 