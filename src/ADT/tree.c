#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "wordmachine.h"
#include "../database.h"

addressTree newTNODE(IDType ID,WordType word)
{
    addressTree newNode = (addressTree)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        ID(newNode) = ID;
        BAUTH(newNode) = SELMT(dataNama,current_id) ;
        BDATE(newNode) = ExtractLocalTimes() ;
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
void createTree(Tree *T,IDType IDParents,WordType word)
{
    Root(*T) = newTNODE(IDParents,word);
}

void AddChild(Tree T,IDType IDParent, IDType IDChild,Word word)
{
    Tree p = T;
    addressTree parentNode = SearchTNode(p, IDParent);
    if (parentNode != NULL)
    {
        addressTree childNode = newTNODE(IDChild,word);
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

void DelChild(Tree *T,IDType IDParent, IDType IDChild)
{
    Tree p = *T;
    addressTree parentNode = SearchTNode(p, IDParent);
    if (parentNode != NULL)
    {
        addressTree prevChild = NULL;
        addressTree child = FirstChild(parentNode);
        while (child != NULL && ID(child) != IDChild)
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
    else if (ID(p) == ID)
    {
        return p;
    }
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
    return Root(T) != NULL && ID(Root(T)) == ID;
}

void displayTree(addressTree node, int depth) {
    if (node != NULL) {
        int i;
        for (i = 0; i < depth; i++) {
            printf("  ");  // Mencetak spasi untuk indentasi
        }
        printf("%d\n", ID(node));  // Mencetak ID node saat ini
        addressTree child = FirstChild(node);
        while (child != NULL) {
            displayTree(child, depth + 1);  // Rekursif ke anak-anak
            child = NextSibling(child);
        }
    }
}