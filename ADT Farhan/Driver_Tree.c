#include "../src/tree.h"
#include "../src/kicau.h"
#include "../src/adt/wordmachine.h"
#include "../src/database.h"
#include "../src/tree.c"
#include "../src/kicau.c"
#include "../src/adt/datetime.c"
#include "../src/adt/times.c"
#include "../src/adt/liststatikword.c"
#include "../src/adt/wordmachine.c"
#include "../src/adt/charmachine.c"
#include "../src/database.c"
#include "../src/teman.c"

int main() {
    // Contoh penggunaan
    Tree tree;
    DATETIME D1;
    CreateDATETIME(&D1,1,1,1,1,1,1);
    START();
    CopyWordWithSpace();
    createTree(&tree, CreateDefinedKicau(currentWord,currentWord, 0, D1, 1));

    // Menambahkan balasan pada kicauan pertama
    CreateDATETIME(&D1,2,2,2,2,2,2);
    START();
    CopyWordWithSpace();
    AddChild(&tree, 1, 2,currentWord );
    
    CreateDATETIME(&D1,3,3,3,3,3,3);
    START();
    CopyWordWithSpace();
    AddChild(&tree, 2, 3,currentWord );

    // Menambahkan balasan pada kicauan kedua
    AddChild(&tree, 3, 4,currentWord );

    // Menampilkan isi pohon dengan format khusus
    printf("Isi pohon:\n");
    displayTreeFull(tree);

    // Mencari ID maksimum

    IDType maxID = searchIDmax(Root(tree));
    printf("ID maksimum dalam pohon: %d\n", maxID);

    // Menampilkan kicauan dengan ID tertentu
    displayTreeFull(tree);

    return 0;
}