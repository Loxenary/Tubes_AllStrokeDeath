#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "./adt/wordmachine.h"
#include "database.h"
#include "kicau.h"

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
        BAUTH(newNode) = SELMT(dataNama, current_id);
        BDATE(newNode) = ExtractLocalTimes();
        BTEXT(newNode) = kicau.Text;
        FirstChild(newNode) = NULL;
        NextSibling(newNode) = NULL;
    }
    Root(*T) = newNode;
}

void AddChild(Tree *T, IDType IDParent, IDType IDChild, Word word)
{
    Tree p = *T;
    addressTree parentNode = SearchTNode(p, IDParent);
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

void DelChild(Tree *T, IDType IDParent, IDType IDChild)
{
    Tree p = *T;
    addressTree parentNode = SearchTNode(p, IDParent);
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
addressTree SearchTNode(Tree T, IDType ID)
{
    addressTree p = Root(T);
    if (p == NULL)
    {
        return NULL;
    }
    // else if (ID(p) == ID)
    // {
    //     return p;
    // }
    else
    {
        addressTree child = FirstChild(p);
        while (child != NULL)
        {
            Root(T) = child;
            addressTree result = SearchTNode(T, ID);
            if (result != NULL)
            {
                return result;
            }
            child = NextSibling(child);
        }
        return NULL;
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
    addressTree node = SearchTNode(T, ID);
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

    if (isTeman(matPertemanan,SELMT(dataNama,current_id-1), BAUTH(node)))
    {
        printf("%*s| ", (tingkatan) * 3, "");
        printWord(BAUTH(node));
        printf("\n");
        printf("%*s| ", (tingkatan) * 3, "");
        TulisDATETIME(BDATE(node));
        printf("\n");
        printf("%*s| %s\n", (tingkatan) * 3, "");
        printWord(BTEXT(node));
        printf("\n");
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
    addressTree p = Root(T);
    displayTreeLevel(p, 0);
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