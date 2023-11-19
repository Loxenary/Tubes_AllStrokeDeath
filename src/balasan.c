#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "balasan.h"
#include "tree.h"

void CreateListBalasan(ListBalasan *l, int Capacity)
{
    BBUFFER(*l) = (Balasan*)malloc(BCAPACITY(l)*sizeof(Balasan));
    BNEFF(*l) = 0;
    BCAPACITY(l) = Capacity;
}

void inputBalas(ListBalasan *l,int id_k,int id_b)
{   
    if(id_k > KNEFF(id_kicau))
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n\n");
    }
    else
    {
        if(ELMT(JenisAkun,current_id) == 1) //butuh gmn teman
        {
            printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n\n");
        }
        else
        {
            printf("Masukkan balasan:\n");
            START();
            CopyWordWithSpace();
            InsertNewBalasId(l,currentWord,id_k,id_b);
            printNewBalasan((BELMT(l,id_k-1)));
        }
    }
}

void InsertNewBalasId(ListBalasan *l, Word Word,IDType id_k, IDType id_b)
{
    if (id_b == -1)
    {   
        AddChild((BELMT(*l,id_k-1)),id_k,jumlah_balasan+1,Word);
    }
    else
    {
        AddChild((BELMT(*l,id_k-1)),id_b,jumlah_balasan+1,Word);
    }
    jumlah_balasan++;
}

void printNewBalasan(Tree balas)
{
    addressTree p = SearchTNode(balas,jumlah_balasan);
    printf("Selamat! balasan telah diterbitkan!\n");
    printf("Detil balasan:");
    printWord(BTEXT(p));
    printf("| ID = %d\n",current_id); 
    printf("| ");
    printWord(SELMT(dataNama,current_id));
    printf("\n| date\n");
    printf("| balasan\n\n");
}

void hapusBalasan(ListBalasan *l,IDType id_k,IDType id_b)
{
    if (id_k > KNEFF(list_kicau))
    {
        printf("Balasan tidak ditemukan");
    }
    else
    {
        addressTree p = SearchTNode(BELMT(*l,id_k-1),id_b);
        if (p == NULL)
        {
            printf("Balasan tidak ditemukan");
        }
        else
        {
            DelChild((BELMT(*l,id_k-1)),id_b,jumlah_balasan+1);
            printf("Balasan berhasil dihapus");
        }        
    }
}   

void displayBalasan(ListBalasan l ,IDType id_k )
{
    
}