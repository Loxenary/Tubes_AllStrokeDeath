#include <stdio.h>
#include <stdlib.h>
#include "database.h"

void CreateListTree(ListTree *l, int Capacity)
{
    BBUFFER(*l) = (Tree *)malloc(Capacity * sizeof(Tree));
    BNEFF(*l) = 0;
    BCAPACITY(l) = Capacity;
}

void inputNewKicauToListTree(ListTree *l, kicauan kicau, IdxType id)
{
    BNEFF(*l)
    ++;
    Tree T;
    createTree(&T, kicau);
    BELMT(*l, id - 1) = T;
}

void ubahKicauToNewBalasan(Tree *t, kicauan new)
{
    BTEXT(Root(*t)) = new.Text;
    BDATE(Root(*t)) = new.dates;
}

void InsertNewBalasId(ListTree *l, Word Word, IDType id_k, IDType id_b, IDType idnew)
{
    if (id_b == -1)
    {
        AddChildMinSatu(&(BELMT(*l, id_k - 1)), id_k, idnew, Word);
    }
    else
    {
        AddChild(&(BELMT(*l, id_k - 1)), id_b, idnew, Word);
    }
    jumlah_balasan++;
}

void printNewBalasan(Tree balas, IDType id_b)
{
    addressTree p = SearchTNode(Root(balas), id_b);
    printf("Selamat! balasan telah diterbitkan!\n");
    printf("Detil balasan:\n");
    printf("| ID = %d\n", BID(p));
    printf("| ");
    printWord(BAUTH(p));
    printf("\n| ");
    TulisDATETIME(BDATE(p));
    printf("\n");
    printf("| ");
    printWord(BTEXT(p));
    printf("\n\n");
}

void inputBalas(ListTree *l, int id_k, int id_b)
{

    if (id_k > KNEFF(list_kicau))
    {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n\n");
    }
    else
    {
        if (id_b == -1)
        {
            int idxauthkicau = SwindexOf(dataNama, BAUTH(Root(BELMT(*l, id_k - 1))));
            if (!isTeman(matPertemanan, SELMT(dataNama, current_id), BAUTH(Root(BELMT(*l, id_k - 1)))) && ELMT(JenisAkun, idxauthkicau) == 1)
            {
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n\n");
            }
            else
            {
                if (BCAPACITY(l) == BNEFF(*l))
                {
                    expandListTree(l, BCAPACITY(l));
                }
                printf("Masukkan balasan:\n");
                START();
                CopyWordWithSpace();
                IDType idnew ;
                if(IsOneElmt(BELMT(*l, id_k - 1)))
                {
                    idnew = 1;
                }
                else
                {
                    idnew = searchIDmaxWithoutRootId(Root(BELMT(*l, id_k - 1)));
                    idnew++;
                }       
                InsertNewBalasId(l, currentWord, id_k, id_b, idnew);
                printNewBalasan((BELMT(*l, (id_k - 1))), idnew);
            }
        }
        else
        {
            addressTree balasan = SearchTNode(Root(BELMT(*l, id_k - 1)), id_b);
            if (balasan == NULL)
            {
                printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n\n");
                return;
            }
            int idxauthbalasan = SwindexOf(dataNama, BAUTH(balasan));
            int idxauthkicau = SwindexOf(dataNama, BAUTH(Root(BELMT(*l, id_k - 1))));
            if (idxauthbalasan != -1 && idxauthkicau != -1 && !isTeman(matPertemanan, SELMT(dataNama, current_id - 1), BAUTH(Root(BELMT(*l, id_k - 1)))) && !isTeman(matPertemanan, SELMT(dataNama, current_id - 1), BAUTH(balasan)) && ELMT(JenisAkun, idxauthbalasan) && ELMT(JenisAkun, idxauthkicau))
            {
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!\n\n");
                return;
            }
            else
            {
                if (BCAPACITY(l) == BNEFF(*l))
                {
                    expandListTree(l, BCAPACITY(l));
                }
                printf("Masukkan balasan:\n");
                START();
                CopyWordWithSpace();
                IDType idnew = searchIDmaxWithoutRootId(Root(BELMT(*l, id_k - 1)));
                idnew++;
                InsertNewBalasId(l, currentWord, id_k, id_b, idnew);
                printNewBalasan((BELMT(*l, (id_k - 1))), idnew);
            }
        }
    }
}

void hapusBalasan(ListTree *l, IDType id_k, IDType id_b)
{
    if (id_k > KNEFF(list_kicau))
    {
        printf("Balasan tidak ditemukan\n");
    }
    else
    {
        addressTree p = SearchTNodeWithoutRoot(Root(BELMT(*l, id_k - 1)), id_b);
        if (p == NULL)
        {
            printf("Balasan tidak ditemukan\n");
        }

        else if (isWordEqual(BAUTH(p), SELMT(dataNama, current_id - 1)))
        {
            printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
        }

        else
        {
            addressTree p = findParent(Root(BELMT(*l, id_k - 1)), id_b);
            if (p != NULL)
            {
                DelChild(&(BELMT(*l, id_k - 1)), BID(p), id_b);
                printf("Balasan berhasil dihapus\n");
            }
            else
            {
                printf("NULL COKKK\n");
            }
        }
    }
}

void displayBalasan(ListTree l, IDType id_k)
{
    if (id_k > KNEFF(list_kicau))
    {
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
    }
    else
    {
        Tree p = BELMT(l, id_k - 1);
        if (FirstChild(Root(p)) == NULL)
        {
            printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        }
        else
        {
            displayTreeFullBalasan(p);
        }
    }
}

void expandListTree(ListTree *l, int num)
{
    ListTree temps;
    CreateListTree(&temps, BCAPACITY(l));
    int i;
    for (i = 0; i < BCAPACITY(l); i++)
    {
        BELMT(temps, i) = BELMT(*l, i);
    }
    *l = temps;
}

void bacaConfigBalasan(ListTree *l, int id_k, int id_b, int id_baru, Word text, WordType Auth, DATETIME Date)
{
    if (id_b == -1)
    {
        AddChildConfig(&(BELMT(*l, id_k - 1)), id_k, id_baru, text, Date, Auth, id_b);
    }
    else
    {
        addressTree p = SearchTNodeWithoutRoot(Root(BELMT(*l, id_k - 1)), id_b);
        AddChildConfig(&(BELMT(*l, id_k - 1)), BID(p), id_baru, text, Date, Auth, id_b);
    }
}