#include <stdio.h>
#include <stdlib.h>
#include "database.h"

void CreateListTree(ListTree *l, int Capacity)
{
    BBUFFER(*l) = (Tree*)malloc(Capacity*sizeof(Tree));
    BNEFF(*l) = 0;
    BCAPACITY(l) = Capacity;
}

void inputNewKicauToListTree(ListTree *l,kicauan kicau,IdxType id)
{
    BNEFF(*l)++;
    Tree T;
    createTree(&T,kicau);
    BELMT(*l,id-1) = T;
}

void ubahKicauToNewBalasan(Tree *t, kicauan new)
{
    BTEXT(Root(*t)) = new.Text;
    BDATE(Root(*t)) = new.dates;
}

void InsertNewBalasId(ListTree *l, Word Word,IDType id_k, IDType id_b)
{
    IDType idnew = searchIDmax(Root(BELMT(*l,id_k-1))) + 1; 
    if (id_b == -1)
    {   
        AddChild(&(BELMT(*l,id_k-1)),id_k,idnew,Word);
        insertAt(&list_balasan,1,id_k-1);
    }
    else
    {
        AddChild(&(BELMT(*l,id_k-1)),id_b,idnew,Word);
    }
    jumlah_balasan++;
}

void printNewBalasan(Tree balas)
{
    addressTree p = SearchTNode(Root(balas),jumlah_balasan);
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
        if (id_b == -1)
        {
            int idxauthkicau = SwindexOf(dataNama,BAUTH(Root(BELMT(*l,id_k-1))));
            if(!isTeman(matPertemanan,SELMT(dataNama,current_id), BAUTH(Root(BELMT(*l,id_k-1))) ) && ELMT(JenisAkun,idxauthkicau) == 1) 
            {
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n\n");
            }
            else
            {
                if (BCAPACITY(l) == BNEFF(*l))
                {
                    expandListTree(l,BCAPACITY(l));    
                }
                printf("Masukkan balasan:\n");
                START();
                CopyWordWithSpace();
                InsertNewBalasId(l,currentWord,id_k,id_b);
                DinsertAt(&kicau_with_balasan,1,id_k);
                printNewBalasan((BELMT(*l,(id_k-1))));
            }
        }
        else
        {
            addressTree balasan = SearchTNodeWithoutRoot(Root(BELMT(*l,id_k)),id_b);
            if (balasan != NULL)
            {
                int idxauthbalasan = SwindexOf(dataNama,BAUTH(balasan));
                int idxauthkicau = SwindexOf(dataNama,BAUTH(Root(BELMT(*l,id_k-1))));
                
                if(!isTeman(matPertemanan,SELMT(dataNama,current_id-1), BAUTH(Root(BELMT(*l,id_k-1))) ) && !isTeman(matPertemanan,SELMT(dataNama,current_id-1),BAUTH(balasan)) && ELMT(JenisAkun,idxauthbalasan) && ELMT(JenisAkun,idxauthkicau)) 
                {
                    printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n\n");
                }
                else
                {
                    if (BCAPACITY(l) == BNEFF(*l))
                    {
                        expandListTree(l,BCAPACITY(l));    
                    }
                    printf("Masukkan balasan:\n");
                    START();
                    CopyWordWithSpace();
                    InsertNewBalasId(l,currentWord,id_k,id_b);
                    printNewBalasan((BELMT(*l,(id_k-1))));
                }
            }
        }   
    }
}

void hapusBalasan(ListTree *l,IDType id_k,IDType id_b)
{
    if (id_k > KNEFF(list_kicau))
    {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
    }
    else
    {
        addressTree p = SearchTNodeWithoutRoot(Root(BELMT(*l,id_k-1)),id_b);
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

void expandListTree(ListTree *l, int num)
{
      BCAPACITY(l)+=num;
}

void bacaConfigBalasan(ListTree *l, int id_k, int id_b, int id_baru, Word text, WordType Auth, DATETIME Date)
{
    if (id_b == -1)
    {
        AddChildConfig(&(BELMT(*l, id_k - 1)), id_k, id_baru, text, Date, Auth,id_b);
    }
    else
    {
        addressTree p = SearchTNodeWithoutRoot(Root(BELMT(*l, id_k - 1)), id_b);
        AddChildConfig(&(BELMT(*l, id_k - 1)), BID(p), id_baru, text, Date, Auth,id_b);
    }
}