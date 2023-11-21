#include <stdio.h>
#include <stdlib.h>
#include "balasan.h"
#include "database.h"


void CreateListTree(ListTree *l, int Capacity)
{
    BBUFFER(*l) = (Tree*)malloc(BCAPACITY(l)*sizeof(Tree));
    BNEFF(*l) = 0;
    BCAPACITY(l) = Capacity;

    for (int i = 0; i < KNEFF(list_kicau); i++)
    {
        kicauan p = KELMT(list_kicau,i);
        Tree T;
        createTree(&T,p);
        BELMT(*l,i) = T;
    }
    BNEFF(*l) = KNEFF(*l);
}

void inputNewKicauToListTree(ListTree *l)
{
    BNEFF(*l)++;
    kicauan p = KELMT(list_kicau,KNEFF(list_kicau) - 1);
    Tree T;
    createTree(&T,p);
    BELMT(*l,KNEFF(list_kicau) - 1) = T;
}

void InsertNewBalasId(ListTree *l, Word Word,IDType id_k, IDType id_b)
{
    IDType idnew = searchIDmax(Root(BELMT(*l,id_k-1))) + 1; 
    if (id_b == -1)
    {   
        AddChild(&(BELMT(*l,id_k-1)),id_k,idnew,Word);
    }
    else
    {
        AddChild(&(BELMT(*l,id_k-1)),id_b,idnew,Word);
    }
    jumlah_balasan++;
}

void printNewBalasan(Tree balas)
{
    addressTree p = SearchTNode(balas,jumlah_balasan);
    printf("Selamat! balasan telah diterbitkan!\n");
    printf("Detil balasan:");
    printf("| ID = %d\n",current_id); 
    printf("| ");
    printWord(SELMT(dataNama,current_id));
    printf("\n| ");
    TulisDATETIME(BDATE(p));
    printf("\n");
    printf("| ");
    printWord(BTEXT(p));
    printf("\n");
}

void inputBalas(ListTree *l,int id_k,int id_b)
{   
    if(id_k > KNEFF(list_kicau))
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n\n");
    }
    else
    {
        
        addressTree balasan = SearchTNode(BELMT(*l,id_k-1),id_b);
        int idxauthbalasan = SwindexOf(dataNama,BAUTH(balasan));
        int idxauthkicau = SwindexOf(dataNama,BAUTH(Root(BELMT(*l,id_k-1))));
        
        if(!isTeman(matPertemanan,SELMT(dataNama,current_id-1), BAUTH(Root(BELMT(*l,id_k-1))) ) && !isTeman(matPertemanan,SELMT(dataNama,current_id-1),BAUTH(balasan)) && ELMT(JenisAkun,idxauthbalasan) && ELMT(JenisAkun,idxauthkicau)) 
        {
            printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n\n");
        }
        else
        {
            printf("Masukkan balasan:\n");
            START();
            CopyWordWithSpace();
            InsertNewBalasId(l,currentWord,id_k,id_b);
            printNewBalasan((BELMT(*l,(id_k-1))));
        }
    }
}

void hapusBalasan(ListTree *l,IDType id_k,IDType id_b)
{
    printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
    if (id_k > KNEFF(list_kicau))
    {
    }
    else
    {
        addressTree p = SearchTNode(BELMT(*l,id_k-1),id_b);
        if (p == NULL)
        {
            printf("Balasan tidak ditemukan\n");
        }

        else if (isWordEqual(BAUTH(p) ,SELMT(dataNama,current_id-1)))
        {
            printf("Balasan tidak ditemukan\n");
        }

        else
        {
            DelChild(&(BELMT(*l,id_k-1)),id_b,jumlah_balasan+1);
            printf("Balasan berhasil dihapus\n");
        }        
    }
}   

void displayBalasan(ListTree l ,IDType id_k )
{
    if (id_k > KNEFF(list_kicau))
    {
        printf("Tidak terdapat kicauan dengan id tersebut!");
    }
    else
    {   
        Tree p = BELMT(l,id_k-1);
        if(FirstChild(Root(p))  != NULL)
        {
            printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        }   
        else
        {
            displayTreeFull(p);
        }
    }
}