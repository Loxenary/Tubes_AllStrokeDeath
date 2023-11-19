#include <stdio.h>
#include "database.h"
#include "inisialisasi.h"
// #include <ctype.h>

#define FILENAME_MAX_LENGTH 256 // Adjust the size as needed

void displayScreen() {
    char text[] = "baby shark doo doo doo doo doo doo\n";
    printf("%s", text);
    printf("%s", text);
    printf("baby shark\n");
    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi ini sangat mirip dengan Twitter.\n");
    printf("\n");
}

void readLine(){
    ADVLINE();
    currentWord.TabWord[currentWord.Length] = '\0';
    currentWord.Length--;
}

// Implementasi fungsi ReadUserData
void ReadUserData(const char *filename, UserData *userData) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    } else {
        printf("File %s opened successfully\n", filename);
    }
    printf("Filename: %s\n", filename);

    // Initialize the word machine
    STARTFILEWORD(filename);
    printf("Word machine initialized\n");

    // Read the number of users
    banyak_pengguna = toInt(currentWord);
    // printf("Number of users: %d\n", userData->banyak_pengguna);

    int i,j;

    // Database Creation
    SwCreateListStatik(&dataNama); // Global Data untuk ListStatik
    SwCreateListStatik(&password);
    SwCreateListStatik(&bio);
    SwCreateListStatik(&phone);
    SwCreateListStatik(&Weton);
    CreateListStatik(&JenisAkun);
    CreateListStatikMatrix(&profil);

    printf("\n");
    
    SwprintList(dataNama);
    printf("\n");
    CreateAdjMatrix(&matPertemanan,banyak_pengguna);

    // Read user data
    for (i = 0; i < banyak_pengguna; i++) {
        
        printf("\nReading user %d\n", i);
        readLine();

        SwinsertLast(&dataNama,currentWord);

         // printWord(currentWord);
        // printf("\n");
        // simpan nama user

        // printf("Nama: %s\n", userData->dataNama[i].TabWord);
        
        readLine();
        SwinsertLast(&password,currentWord);
        // printWord(currentWord);
        // printf("\n");
        
        // simpan password user
        // printf("Password: %s\n", userData->password[i].TabWord);
        
        
        // printWord(currentWord);
        // printf("\n");
        readLine();
        SwinsertLast(&bio,currentWord);
        // simpan bio user
        // printf("Bio: %s\n", userData->bio[i].TabWord);
        
        
        // simpan phone user
    
        // printf("Phone: %s\n", userData->phone[i].TabWord);
        // printWord(currentWord);
        // printf("\n");
        readLine();
        SwinsertLast(&phone,currentWord);

        
        // printWord(currentWord);
        // printf("\n");
        // simpan weton user
        readLine();
        SwinsertLast(&Weton,currentWord);
        // printf("Weton: %s\n", currentWord.TabWord);


        // printWord(currentWord);
        // printf("\n");
        // simpan jenis akun user
        readLine();
        char * pub = "Publik";

        if (isWordEqualString(currentWord,pub)) {
            SinsertLast(&JenisAkun,Publik);
        } else {
            SinsertLast(&JenisAkun,Privat);
        }
        
        // printf("Jenis akun: %s\n", currentWord.TabWord);

        // Read Profile ignore blank in between words
        // printf("Profile:\n");
        
        MatrixChar temp;
        MatrixProfileDefault(&temp);
        int k;
        for ( j= 0; j < 5; j++) {
            readLine();
            for(k = 0; k < 9; k++){
                MELMT(temp,j,k*2) = currentWord.TabWord[k*2];
            }
        }
        // displayMatrixCharColoured(temp);
        LSMELMT(profil,i) = temp;

    }
    // printf("\nReading adjacency matrix:\n");
    for(i = 0; i < banyak_pengguna; i++){
        readLine();
        WordToAdjMatrix(&matPertemanan,currentWord,i);
    }

    PrintAdjMatrix(matPertemanan);
    printf("\n");
    // Read friendship requests
    readLine();
    int banyak_permintaan = toInt(currentWord);
    // printf("\nBanyak permintaan pertemanan: %d\n", banyak_permintaan);
    int senderId, receiverId, status;
    for (i = 0; i < banyak_permintaan; i++) {
        ADVLINE();

        Word temps;
        int k = 0;
        int counter = 0;
        for(j = 0; j < currentWord.Length; j++){

            if(currentWord.TabWord[j] == BLANK || j == currentWord.Length-1){
                counter++;
                temps.Length = k;
                k=0;
            
                switch (counter)
                {
                case 1:
                    senderId = toInt(temps);
                    break;
                case 2:
                    receiverId = toInt(temps);
                    break;
                case 3:
                    status = toInt(temps);
                    break;
                default:
                    break;
                }
            }
            else{
                temps.TabWord[k] = currentWord.TabWord[j]; 
                k++;
            }

        }
        // printf("%d %d %d\n",senderId,receiverId,status);
    }

    fclose(file);
}

// Implementasi fungsi ReadKicauData
void ReadKicauData(char* filename, kicauan* kicau) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    } else {
        printf("File %s opened successfully\n", filename);
    }
    printf("Filename: %s\n", filename);

    STARTFILEWORD(filename);

    // Membaca banyak kicauan
    CreateListKicau(&list_kicau, 50); //50 as starter
    jumlah_kicau = toInt(currentWord);
    printf("Jumlah kicauan: %d\n", jumlah_kicau);

    // Membaca kicauan
    for (int i = 0; i < jumlah_kicau; i++) {
        printf("\nReading kicau %d\n", i);

        // Membaca id kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        KELMT(list_kicau,i).id = toInt(currentWord);
        printWord(currentWord);
        printf("\n");

        // Membaca text kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        KELMT(list_kicau,i).Text = currentWord;
        printWord(currentWord);
        printf("\n");

        // Membaca jumlah like kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        KELMT(list_kicau,i).Likes = toInt(currentWord);
        printWord(currentWord);
        printf("\n");

        // Membaca author kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        KELMT(list_kicau,i).Auth = currentWord;

        // Membaca tanggal waktu kicauan
        DATETIME temp_time;
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        
        KELMT(list_kicau,i).dates = WordToDatetime(currentWord);
        TulisDATETIME(KELMT(list_kicau,i).dates);

    }
    printf("\n");
    printf("TESTTTTTTTT");
    fclose(file);
}


// Implementasi fungsi ReadBalasanData
void ReadBalasanData(char* filename, Balasan* balasan) {
    FILE *file = fopen(filename, "r");

    // if (file == NULL) {
    //     printf("Error: Cannot open file %s\n", filename);
    //     return;
    // } else {
    //     printf("File %s opened successfully\n", filename);
    // }
    // printf("Filename: %s\n", filename);

    // // Membaca banyak kicauan yang memiliki balasan
    // STARTFILEWORD(filename);
    // balasan->kicauBalas = toInt(currentWord);
    // printf("Jumlah balasan: %d\n", balasan->kicauBalas);

    // // Membaca id kicauan yang memiliki balasan
    // ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    // balasan->idKicau = toInt(currentWord);
    // // printf("ID: %d\n", balasan->idKicau);

    // // Membaca banyak balasan yang diterima
    // ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    // balasan->banyakBalasan = toInt(currentWord);
    // // printf("Banyak balasan: %d\n", balasan->banyakBalasan);

    // // Membaca balasan
    // for (int i = 0; i < balasan->banyakBalasan; i++) {

    //     // Membaca id parent
    //     ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
    //     balasan->idParent = toInt(currentWord);
    //     // printf("ID parent: %d\n", balasan->idParent);

    //     // Membaca id balasan
    //     ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
    //     balasan->idBalasan = toInt(currentWord);
    //     // printf("ID balasan: %d\n", balasan->idBalasan);

    //     // Membaca teks balasan
    //     ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    //     balasan->teksBalasan = currentWord;
    //     // printf("%s\n", balasan->teksBalasan.TabWord);

    //     // Membaca penulis balasan
    //     ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    //     balasan->penulis = currentWord;
    //     // printf("Nama : %s\n", balasan->penulis.TabWord);
    //     // Membaca tanggal waktu balasan
    //     ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        
    //     // printf("Datetime: %02d/%02d/%04d %02d:%02d:%02d\n", Day(balasan->dates), Month(balasan->dates), Year(balasan->dates),
    //         //    balasan->dates.T.HH, balasan->dates.T.MM, balasan->dates.T.SS);

    // }


    fclose(file);
}


// Implementasi fungsi ReadDrafData
void ReadDrafData(const char *filename, ListDraf *listDraf) {
    FILE *file = fopen(filename, "r");

    // if (file == NULL) {
    //     printf("Error: Cannot open file %s\n", filename);
    //     return;
    // } else {
    //     printf("File %s opened successfully\n", filename);
    // }
    // printf("Filename: %s\n", filename);

    // // Initialize the word machine
    // STARTFILEWORD(filename);
    // printf("Word machine initialized\n");

    // // Read the number of users with drafts
    // listDraf->banyak_pengguna = toInt(currentWord);
    // printf("Number of users with drafts: %d\n", listDraf->banyak_pengguna);

    // // Read user drafts
    // for (int i = 0; i < listDraf->banyak_pengguna; i++) {
    //     listDraf->users[i].username.Length = 0;

    //     while (1) {
    //         ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
    //         if (isdigit(currentWord.TabWord[0])) {
    //             listDraf->users[i].banyak_draf = toInt(currentWord);
    //             printf("Nama: %s\n", listDraf->users[i].username.TabWord);
    //             printf("Banyak draf: %d\n", listDraf->users[i].banyak_draf);
    //             break;
    //         } else {
    //             for (int j = 0; j < currentWord.Length; j++) {
    //                 listDraf->users[i].username.TabWord[listDraf->users[i].username.Length] = currentWord.TabWord[j];
    //                 listDraf->users[i].username.Length++;
    //             }
    //             listDraf->users[i].username.TabWord[listDraf->users[i].username.Length] = ' ';
    //         }
    //     }

    //     for (int j = 0; j < listDraf->users[i].banyak_draf; j++) {
    //         // Isi draft
    //         ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    //         listDraf->users[i].draf[j].text.Length = currentWord.Length;
    //         printf("Text draft %d: %s\n", j + 1, currentWord.TabWord);

    //         // Datetime draft
    //         ADVLINE();
    //     //     currentWord.TabWord[currentWord.Length] = '\0';
           
    //     //         Day(listDraf->users[i].draf[j].datetime),
    //     //         Month(listDraf->users[i].draf[j].datetime),
    //     //         Year(listDraf->users[i].draf[j].datetime),
    //     //         listDraf->users[i].draf[j].datetime.T.HH,
    //     //         listDraf->users[i].draf[j].datetime.T.MM,
    //     //         listDraf->users[i].draf[j].datetime.T.SS);
    //     }

    // }

    fclose(file);
}


// Implementasi fungsi ReadUtasData
void ReadUtasData(const char *filename, DataUtas *dataUtas) {
    FILE *file = fopen(filename, "r");

    // if (file == NULL) {
    //     printf("Error: Cannot open file %s\n", filename);
    //     return;
    // } else {
    //     printf("File %s opened successfully\n", filename);
    // }
    // printf("Filename: %s\n", filename);

    // // Initialize the word machine
    // STARTFILEWORD(filename);

    // // Read the number of kicauan
    // dataUtas->banyak_kicauan = toInt(currentWord);
    // printf("Number of kicauan: %d\n", dataUtas->banyak_kicauan);

    // for (int i = 0; i < dataUtas->banyak_kicauan; i++) {
    //     // Read kicauan id
    //     ADVLINE();
    //     currentWord.TabWord[currentWord.Length] = '\0';
    //     // dataUtas->kicauans[i].id_kicauan = toInt(currentWord);        
    //     //printf("ID kicauan %d: %d\n", i + 1, dataUtas->kicauans[i].id_kicauan);

    //     // Read the number of utas for this kicauan
    //     ADVLINE();
    //     currentWord.TabWord[currentWord.Length] = '\0';
    //     //dataUtas->kicauans[i].banyak_utas = toInt(currentWord);
    //     //printf("Number of utas for kicauan %d: %d\n", i + 1, dataUtas->kicauans[i].banyak_utas);

    //     // Read utas data
    // //     for (int j = 0; j < dataUtas->kicauans[i].banyak_utas && j < MAX_UTAS_PER_KICAUAN; j++) {
    // //         // Read utas text
    // //         ADVLINE();
    // //         currentWord.TabWord[currentWord.Length] = '\0';
    // //         dataUtas->kicauans[i].utas[j].text = currentWord;
    // //         printf("Text utas %d: %s\n", j + 1, dataUtas->kicauans[i].utas[j].text.TabWord);

    // //         // Read utas author
    // //         ADVLINE();
    // //         currentWord.TabWord[currentWord.Length] = '\0';
    // //         dataUtas->kicauans[i].utas[j].author = currentWord;
    // //         printf("Author utas %d: %s\n", j + 1, dataUtas->kicauans[i].utas[j].author.TabWord);

    // //         // Read utas datetime
    // //         ADVLINE();
    // //         currentWord.TabWord[currentWord.Length] = '\0';
    // //         dataUtas->kicauans[i].ut
    // //         printf("Datetime utas %d: %02d/%02d/%04d %02d:%02d:%02d\n", j + 1,
    // //             Day(dataUtas->kicauans[i].utas[j].datetime),
    // //             Month(dataUtas->kicauans[i].utas[j].datetime),
    // //             Year(dataUtas->kicauans[i].utas[j].datetime),
    // //             dataUtas->kicauans[i].utas[j].datetime.T.HH,
    // //             dataUtas->kicauans[i].utas[j].datetime.T.MM,
    // //             dataUtas->kicauans[i].utas[j].datetime.T.SS);
    // //     }
    // // }

    fclose(file);
}

void loadconfig(char *folder, char *filename) {
    displayScreen();

    printf("Masukkan nama folder konfigurasi: ");
    scanf("%s", folder);

    // Langsung load semua file config yang ada di folder
    char fileNames[5][20] = {"pengguna.config", "kicauan.config", "balasan.config", "draf.config", "utas.config"};

    for (int i = 0; i < 5; ++i) {
        sprintf(filename, "%s/%s", folder, fileNames[i]);
        // printf("Membaca file %s\n", filename);
        // FILE *file = fopen(filename, "r");

        // if (file == NULL) {
        //     printf("Error: Cannot open file %s\n", filename);
        //     continue;
        // }


        // Initialize the word machine
        STARTFILEWORD(filename);
        printf("Word machine initialized\n");


        // Read data from the file using wordmachine
        if (i == 0) {
            UserData userData;
            ReadUserData(filename, &userData);
            //Done
        } else if (i == 1) {
            // kicauan kicauData;
            // ReadKicauData(filename, &kicauData);
            //Done
            // TODO: Handle kicauan as needed
        } else if (i == 2) {
            // Balasan balasan;
            // ReadBalasanData(filename, &balasan);
            // TODO: Handle Balasan as needed
        } else if (i == 3) {
            // ListDraf listDraf;
            // ReadDrafData(filename, &listDraf);
            // TODO: Handle ListDraf as needed
        } else if (i == 4) {
            // DataUtas datautas;
            // ReadUtasData(filename, &datautas);
            // TODO: Handle DataUtas as needed
        }
    }
}