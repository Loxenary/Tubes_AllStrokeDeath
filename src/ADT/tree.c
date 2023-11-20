#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

addressTree newTNODE(ElType ID)
{
    addressTree newNode = (addressTree)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        ID(newNode) = ID;
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
void createTree(Tree *T,ElType IDParents)
{
    Root(*T) = newTNODE(IDParents);
}

void AddChild(ElType IDParent, ElType IDChild, Tree *T)
{
    Tree p = *T;
    addressTree parentNode = SearchTNode(p, IDParent);
    if (parentNode != NULL)
    {
        addressTree childNode = newTNODE(IDChild);
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

void DelChild(ElType IDParent, ElType IDChild, Tree *T)
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
addressTree SearchTNode(Tree T, ElType ID)
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

int NbElmt(Tree T)
{
    if (Root(T) == NULL)
    {
        return 0;
    }
    else
    {
        int count = 1;
        addressTree child = FirstChild(Root(T));
        while (child != NULL)
        {
            Root(T) = child;
            count += NbElmt(T);
            child = NextSibling(child);
        }
        return count;
    }
}

int MaxNbElmt(Tree T)
{
    return CAPACITY;
}

boolean IsTreeEmpty(Tree T)
{
    return Root(T) == NULL;
}

boolean IsOneElmt(Tree T)
{
    return Root(T) != NULL && FirstChild(Root(T)) == NULL;
}

boolean IsLeaf(Tree T, ElType ID)
{
    addressTree node = SearchTNode(T, ID);
    return node != NULL && FirstChild(node) == NULL;
}

boolean IsRoot(Tree T, ElType ID)
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
