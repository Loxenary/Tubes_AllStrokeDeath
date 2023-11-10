#include <stdio.h>
#include <stdlib.h>
#include "teman.h"

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

ListStatikWord ListTeman(AdjMatrix m, int idx){
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

boolean isTeman(AdjMatrix *m, int vecU, int vecV){
    if(GELMT(m,vecU,vecV) == 1){
        return TRUE;
    }
    return FALSE;
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
void Daftar_Teman(ListStatikWord dataTeman){
    if(isLogin){
        ListStatikWord friends = dataTeman;
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
            }   
        }
        else{
            printf("AWKKWW");
            printWord(nama);
            printf("GAPUNYA TEMEN KASIHAN BEUT\n");
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


void Hapus_Teman(ListStatikWord* dataTeman){
    ListStatikWord friends = *dataTeman;
    
    printf("Masukkan nama pengguna :\n");
    STARTWORD();
    WrdType temp = currentWord;
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
            SwdeleteVal(dataTeman,temp);
            printWord(temp);
            printf(" berhasil dihapus dari\n");
            printf("daftar teman anda \n");
        }
    }
    else{
        printf("Penghapusan teman dibatalkan \n");
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