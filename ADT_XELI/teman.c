#include <stdio.h>
#include <stdlib.h>
#include "teman.h"
#include "database.h"

// AdjMatrix Mat_Teman(){
//     AdjMatrix m;
//     CreateAdjMatrix(&m,banyak_pengguna);
//     int i,j;
//     for(i =0; i < banyak_pengguna; i++){
//         for(j = 0; j < banyak_pengguna; j++){
//             if((matPertemanan,i,j) == 1){
//                 AddEdge(&m,i,j);
//             }
//         }
//     }
//     return m;
// }

ListStatikWord ListTeman(AdjMatrix m, int idx)
{
    ListStatikWord teman;
    SwCreateListStatik(&teman);
    int i;
    for ( i = 0; i < Vert(m); i++)
    {
        if((GELMT(&m,idx,i) == 1) && (i != idx)){
            SwinsertLast(&teman,SELMT(dataNama,i));
        }
    }
    return teman;
}

boolean isTeman(AdjMatrix TemanMat, Word user1, Word user2){
    
    if(GELMT(&TemanMat,SwindexOf(dataNama, user1),SwindexOf(dataNama, user2)) == 1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int jumlah_Teman(AdjMatrix m, int idx){
    int i;
    int sum = 0;
    for(i = 0; i < Vert(m); i++){
        if(GELMT(&m,idx,i) == 1 && (i != idx)){
            sum++;
        }
    }
    return sum;
}

boolean isHapus(Word w){
    //Asumsi input tidak disalah salahkan
    return (w.TabWord[0] == 'Y');
}

//Keperluan Debugging
void Daftar_Teman(AdjMatrix dataTeman){
    if(isLogin){
        ListStatikWord friends = ListTeman(dataTeman,current_id);
        int jumlahTeman = SwlistLength(friends);
        Word nama = SELMT(dataNama,current_id);
        if(jumlahTeman > 0){
            printWord(nama);
            printf(" memiliki %d teman\n",jumlahTeman);
            printf("Daftar teman ");
            printWord(nama);
            printf("\n");
            int i;
            for ( i = 0; i < jumlahTeman; i++)
            {
                printf("| ");
                printWord(SELMT(friends,i));
                printf("\n");
            }   
        }
        else{
            printf("Awkwkkw ");
            printWord(nama);
            printf(" Gapunya teman aduh\n");
            printf("kacian");
        }
    }
    else{
        printf("ANDA BELUM LOGIN WOY, LOGIN DULU!!!!\n");
    }
}


// void Daftar_Teman(AdjMatrix m){
//     if(isLogin){
//         ListStatikWord friends = ListTeman(m,current_id);
//         int jumlahTeman = jumlah_Teman(m, current_id);
//         Word nama = SELMT(dataNama,current_id);
//         if(jumlahTeman > 0){
//             printWord(nama);
//             printf("memiliki %d teman\n",jumlahTeman);
//             printf("\nDaftar teman");
//             printWord(nama);
//             printf("\n");
//             int i;
//             for(i = 0; i < jumlahTeman; i++){
//                 printf("| ");
//                 printWord(SELMT(friends,i));
//                 printf("\n");
//             }
//         }
//         else{
//             printf("AWKWKWKWK");
//             printWord(nama);
//             printf(" GAPUNYA TEMEN KASIHAN BEUT\n");

//         }
//     }
//     else{
//         printf("ANDA BELUM LOGIN WOY, LOGIN DULU!!!!\n");
//     }
// }


void Hapus_Teman(AdjMatrix* dataTeman){
    ListStatikWord friends = ListTeman(*dataTeman,current_id);

    if(jumlah_Teman > 0){
        printf("Masukkan nama pengguna :\n");
        STARTWORD();
        WrdType temp = currentWord;

        if(SwisValExist(dataNama,currentWord)){
            printf("Pengguna tidak ditemukan\n");
        }
        else{
            printf("Apakah anda yakin ingin\n");
            printf("menghapus ");
            printWord(temp);
            printf(" dari daftar teman\n");
            printf("anda? (YA/TIDAK)\n");
            STARTWORD();

            if(isHapus(currentWord)){
                if(!SwisValExist(friends,temp)){
                    printWord(temp);
                    printf("Bukan teman anda");
                }
                else{
                    int idx = SwindexOf(dataNama,currentWord);
                    int i,j;
                    GELMT(dataTeman,current_id,idx) = 0;
                    GELMT(dataTeman,idx,current_id) = 0;
                    printWord(temp);
                    printf(" berhasil dihapus dari\n");
                    printf("daftar teman anda \n");
                }
            }
            else{
                printf("Penghapusan teman dibatalkan \n");
            }
        }
    }
    else{
        printf("Kamu gapunya teman, ,mana bisa hapus teman\n");
        printf("hadeuh\n");
    }

}   



// void Daftar_Teman(Word current_User, Word* list_Teman){
//     int jumlah = listLength(list_Teman);
//     char name[current_User.Length];
//     name = WordToChr(current_User);
//     printf("%s ",name);
//     printf("memiliki %d teman\n"+jumlah);
//     printf("Daftar teman %s\n",name);
//     int i;
//     for (i = 0; i < jumlah; i++)
//     {
//         printf("| %s",WordToChr())
//     }
    

// }
