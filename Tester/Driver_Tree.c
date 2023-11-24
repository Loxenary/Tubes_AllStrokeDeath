#include "../src/kicau.h"
#include "../src/adt/wordmachine.h"
#include "../src/database.h"
#include "../src/adt/tree.h"
#include "../src/adt/tree.c"
#include "../src/kicau.c"
#include "../src/Balasan.h"
#include "../src/Balasan.c"
#include "../src/adt/datetime.c"
#include "../src/adt/times.c"
#include "../src/adt/liststatikword.c"
#include "../src/adt/wordmachine.c"
#include "../src/adt/charmachine.c"
#include "../src/database.c"
#include "../src/teman.c"


int main() {
    Tree tree;
    DATETIME D1;
    // inisialisasi
    current_id = 1;
    SwCreateListStatik(&dataNama);
    START();
    CopyWordWithSpace();
    SwinsertAt(&dataNama,currentWord,1);
    START();
    CopyWordWithSpace();
    SwinsertAt(&dataNama,currentWord,2);

    // create tree
    CreateDATETIME(&D1,1,1,1,1,1,1);
    START();
    CopyWordWithSpace();
    createTree(&tree, CreateDefinedKicau(currentWord,currentWord, 0, D1, 1));

    // Menambahkan child
    CopyWordWithSpace();
    AddChildMinSatu(&tree, 1, 2,currentWord );
    
    START();
    CopyWordWithSpace();
    AddChildMinSatu(&tree, 2, 3,currentWord );

    AddChildMinSatu(&tree, 2, 4,currentWord );

    // Menampilkan isi pohon 
    printf("Isi pohon:\n");
    displayTreeLevel(Root(tree),0);

    // Mencari ID maksimum
    IDType maxID = searchIDmax(Root(tree));
    printf("ID maksimum dalam pohon: %d\n\n", maxID);

    // delete tree
    DelChild(&tree, 2, 4);
    displayTreeLevel(Root(tree),0);

    // Mencari node
    addressTree node = SearchTNode(Root(tree), 3);
    printf("INI Node dengan ID 3: %d\n\n", BID(node));

    // APAKAH PUNYA ANAK
    printf("Apakah punya anak? %d\n\n", hasChild(tree));

    // APAKAH PUNYA 1 elmen saja
    printf("Apakah punya 1 elemen saja? %d\n\n", IsOneElmt(tree));

    // HITUNG JUMLAH ANAK
    printf("Jumlah anak: %d\n\n", countChildren(node));
    return 0;
}