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

void AddChild(Tree *T, IDType IDParent, IDType IDChild, Word word)
{
    Tree p = *T;
    addressTree parentNode = SearchTNode(Root(p), IDParent);
    if (parentNode != NULL)
    {
        addressTree childNode = newTNODE(IDChild, word);
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

    if (isTeman(matPertemanan, SELMT(dataNama, current_id - 1), BAUTH(node)))
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
        printf("%*s| PRIVAT\n", (tingkatan) * 3, "");
    }

    // Lanjutkan ke anak pertama dengan level yang lebih dalam
    displayTreeLevel(FirstChild(node), tingkatan + 1);

    // Lanjutkan ke saudara kandung berikutnya pada level yang sama
    displayTreeLevel(NextSibling(node), tingkatan);
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
    IDType maxID = BID(p); // Inisialisasi dengan nilai simpul saat ini

    // Cari nilai maksimum di anak-anak simpul
    addressTree currentChild = FirstChild(p);
    while (currentChild != NULL)
    {
        IDType childMax = searchIDmax(currentChild);
        if (childMax > maxID)
        {
            maxID = childMax;
        }
        currentChild = NextSibling(currentChild); // Pindah ke saudara kandung berikutnya
    }
    return maxID;
}