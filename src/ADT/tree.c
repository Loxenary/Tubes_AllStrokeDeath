#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../database.h"
addressTree newTNODE(IDType ID, WordType word)
{
    addressTree newNode = (addressTree)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        BID(newNode) = ID;
        PID(newNode) = 0;
        BAUTH(newNode) = SELMT(dataNama, current_id);
        BDATE(newNode) = ExtractLocalTimes();
        BTEXT(newNode) = word;
        FirstChild(newNode) = NULL;
        NextSibling(newNode) = NULL;
    }
    return newNode;
}

addressTree newTNODEConfig(IDType ID, WordType word,WordType Auth, DATETIME Date)
{
    addressTree newNode = (addressTree)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        BID(newNode) = ID;
        PID(newNode) = 0;
        BAUTH(newNode) = Auth;
        BDATE(newNode) = Date;
        BTEXT(newNode) = word;
        FirstChild(newNode) = NULL;
        NextSibling(newNode) = NULL;
    }
    return newNode;
}

void dealocateTNODE(addressTree P)
{
    free(P);
}

/* *** Konstruktor *** */
void createTree(Tree *T, kicauan kicau)
{
    addressTree newNode = (addressTree)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        BID(newNode) = kicau.id;
        PID(newNode) = 0;
        BAUTH(newNode) = kicau.Auth;
        BDATE(newNode) = kicau.dates;
        BTEXT(newNode) = kicau.Text;
        FirstChild(newNode) = NULL;
        NextSibling(newNode) = NULL;
    }
    else
    {
        fprintf(stderr, "Alokasi memori gagal.\n");
    }
    Root(*T) = newNode;
}

void AddChildMinSatu(Tree *T, IDType IDParent, IDType IDChild, Word word)
{
    Tree p = *T;
    addressTree parentNode = SearchTNode(Root(p), IDParent);
    if (parentNode != NULL)
    {
        addressTree childNode = newTNODE(IDChild, word);
        PID(childNode) = -1;
        addressTree lastChild = FirstChild(parentNode);
        if (lastChild == NULL)
        {
            FirstChild(parentNode) = childNode;
        }
        else
        {
            while (NextSibling(lastChild) != NULL)
            {
                lastChild = NextSibling(lastChild);
            }
            NextSibling(lastChild) = childNode;
        }
    }
}

void AddChild(Tree *T, IDType IDParent, IDType IDChild, Word word)
{
    Tree p = *T;
    addressTree parentNode = SearchTNodeWithoutRoot(Root(p), IDParent);
    if (parentNode != NULL)
    {
        addressTree childNode = newTNODE(IDChild, word);
        PID(childNode) = 0;
        addressTree lastChild = FirstChild(parentNode);
        if (lastChild == NULL)
        {
            FirstChild(parentNode) = childNode;
        }
        else
        {
            while (NextSibling(lastChild) != NULL)
            {
                lastChild = NextSibling(lastChild);
            }
            NextSibling(lastChild) = childNode;
        }
    }
}

void AddChildConfig(Tree *T, IDType IDParent,IDType IDChild, Word Text, DATETIME date, WordType Auth,IDType id_b)
{
    Tree p = *T;
    addressTree parentNode;
    
    if (id_b == -1)
    {
        parentNode = SearchTNode(Root(p), IDParent);
    }
    else
    {
        parentNode = SearchTNodeWithoutRoot(Root(p), IDParent);
    }
    
    if (parentNode != NULL)
    {
        addressTree childNode = newTNODEConfig(IDChild, Text, Auth, date);
        if(id_b == -1){
            PID(childNode) = -1;
        }
        else{
            PID(childNode) = 0;
        }
        if (childNode != NULL)
        {
            addressTree lastChild = FirstChild(parentNode);

            if (lastChild == NULL)
            {
                FirstChild(parentNode) = childNode;
            }
            else
            {
                while (NextSibling(lastChild) != NULL)
                {
                    lastChild = NextSibling(lastChild);
                }

                NextSibling(lastChild) = childNode;
            }

            // Inisialisasi NextSibling dari childNode dengan NULL
            NextSibling(childNode) = NULL;
        }
        else
        {
            // Handle error ketika gagal mengalokasikan memory untuk childNode
            printf("Failed to allocate memory for childNode\n");
        }
    }
    else
    {
        // Handle error ketika parentNode tidak ditemukan
        printf("Parent node not found for IDParent = %d\n", IDParent);
    }
}

addressTree findParent(addressTree root, IDType childID) {
    if (root == NULL) {
        return NULL; 
    }

    addressTree child = FirstChild(root);
    while (child != NULL) {
        if (BID(child) == childID) {
            return root; 
        }
        child = NextSibling(child);
    }

    child = FirstChild(root);
    while (child != NULL) {
        addressTree result = findParent(child, childID);
        if (result != NULL) {
            return result;
        }
        child = NextSibling(child);
    }

    return NULL; 
}

void DelChild(Tree *T, IDType IDParent, IDType IDChild)
{
    Tree p = *T;
    addressTree parentNode = SearchTNode(Root(p), IDParent);
    if (parentNode != NULL)
    {
        addressTree prevChild = NULL;
        addressTree child = FirstChild(parentNode);
        while (child != NULL && BID(child) != IDChild)
        {
            prevChild = child;
            child = NextSibling(child);
        }
        if (child != NULL)
        {
            if (prevChild == NULL)
            {
                FirstChild(parentNode) = NextSibling(child);
            }
            else
            {
                NextSibling(prevChild) = NextSibling(child);
            }
            dealocateTNODE(child);
        }
    }
}

/* *** Operasi lain *** */
addressTree SearchTNode(addressTree t, IDType ID)
{
    // Pengecekan kondisi awal
    if (t == NULL)
    {
        return NULL;
    }

    // Cek apakah nilai pada node saat ini sama dengan targetValue
    if (BID(t) == ID)
    {
        return t; // Jika sama, kembalikan alamat node
    }

    // Cari di anak pertama
    addressTree childAddress = SearchTNode(FirstChild(t), ID);
    if (childAddress != NULL)
    {
        return childAddress; // Jika ditemukan di anak pertama, kembalikan alamat node
    }

    // Cari di saudara berikutnya
    addressTree siblingAddress = SearchTNode(NextSibling(t), ID);
    return siblingAddress; // Kembalikan alamat node, mungkin NULL jika tidak ditemukan
}

addressTree SearchTNodeWithoutRoot(addressTree t, IDType ID)
{
    addressTree p = FirstChild(t);
    if (p == NULL)
    {
        return NULL;
    }
    else
    {
        return SearchTNode(p,ID);
    }
}

boolean hasChild(Tree T)
{
    return FirstChild(Root(T)) != NULL;
}

boolean IsTreeEmpty(Tree T)
{
    return Root(T) == NULL;
}

boolean IsOneElmt(Tree T)
{
    return Root(T) != NULL && FirstChild(Root(T)) == NULL;
}

boolean IsLeaf(Tree T, IDType ID)
{
    addressTree node = SearchTNode(Root(T), ID);
    return node != NULL && FirstChild(node) == NULL;
}

boolean IsRoot(Tree T, IDType ID)
{
    return Root(T) != NULL && BID(Root(T)) == ID;
}

void displayTreeLevel(addressTree node, int tingkatan)
{

    if (node == NULL)
    {
        return;
    }
    // Menampilkan informasi dari simpul saat ini dengan format khusus
    printf("%*s| ID = %d\n", tingkatan * 3, "", BID(node));
    printf("%*s| ", (tingkatan) * 3, "");
    printWord(BAUTH(node));
    printf("\n");
    printf("%*s| ", (tingkatan) * 3, "");
    TulisDATETIME(BDATE(node));
    printf("\n");
    printf("%*s| ", (tingkatan) * 3, "");
    printWord(BTEXT(node));
    printf("\n\n");

    // Lanjutkan ke anak pertama dengan level yang lebih dalam
    displayTreeLevel(FirstChild(node), tingkatan + 1);

    // Lanjutkan ke saudara kandung berikutnya pada level yang sama
    displayTreeLevel(NextSibling(node), tingkatan);
}

void displayTreeLevelBalasan(addressTree node, int tingkatan)
{
    if (node == NULL)
    {
        return;
    }
    // Menampilkan informasi dari simpul saat ini dengan format khusus
    printf("%*s| ID = %d\n", tingkatan * 3, "", BID(node));
    int idx = SwindexOf(dataNama,BAUTH(node));
    if(ELMT(JenisAkun,idx) == 1)
    {
        if (isTeman(matPertemanan, SELMT(dataNama, current_id), BAUTH(node)))
        {
            printf("%*s| ", (tingkatan) * 3, "");
            printWord(BAUTH(node));
            printf("\n");
            printf("%*s| ", (tingkatan) * 3, "");
            TulisDATETIME(BDATE(node));
            printf("\n");
            printf("%*s| ", (tingkatan) * 3, "");
            printWord(BTEXT(node));
            printf("\n\n");
        }
        else
        {
            printf("%*s| PRIVAT\n", (tingkatan) * 3, "");
            printf("%*s| PRIVAT\n", (tingkatan) * 3, "");
            printf("%*s| PRIVAT\n\n", (tingkatan) * 3, "");
        }
    }
    else
    {
        printf("%*s| ", (tingkatan) * 3, "");
        printWord(BAUTH(node));
        printf("\n");
        printf("%*s| ", (tingkatan) * 3, "");
        TulisDATETIME(BDATE(node));
        printf("\n");
        printf("%*s| ", (tingkatan) * 3, "");
        printWord(BTEXT(node));
        printf("\n\n");
    }
    

    // Lanjutkan ke anak pertama dengan level yang lebih dalam
    displayTreeLevelBalasan(FirstChild(node), tingkatan + 1);

    // Lanjutkan ke saudara kandung berikutnya pada level yang sama
    displayTreeLevelBalasan(NextSibling(node), tingkatan);
}

void displayTreeFull(Tree T)
{
    addressTree p = FirstChild(Root(T));
    displayTreeLevel(p, 0);
}

void displayTreeFullBalasan(Tree T)
{
    addressTree p = FirstChild(Root(T));
    displayTreeLevelBalasan(p, 0);
}

IDType searchIDmax(addressTree p)
{
    if (p == NULL) {
        return -1; // Return an error code or handle accordingly
    }

    int maxChildID = BID(p); // Initialize with the ID of the node

    addressTree child = FirstChild(p);
    while (child != NULL) {
        int childID = searchIDmax(child); // Recursively find the maximum ID among the children of this child

        if (childID > maxChildID) {
            maxChildID = childID;
        }

        child = NextSibling(child);
    }

    return maxChildID;
} 

IDType searchIDmaxWithoutRootId(addressTree p)
{
    addressTree child = FirstChild(p); // Ganti nama variabel dari 'l' menjadi 'child'
    return searchIDmax(child);
}

int countChildren(addressTree p) {
    if (p == NULL) {
        return 0;
    }
    else {
        int count = 1; // count this node
        addressTree child = FirstChild(p);
        while (child != NULL) {
            count += countChildren(child); // recursively count children
            child = NextSibling(child);
        }
        return count;
    }
}