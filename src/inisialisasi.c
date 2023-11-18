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
    userData->banyak_pengguna = toInt(currentWord);
    // printf("Number of users: %d\n", userData->banyak_pengguna);

    // Read user data
    for (int i = 0; i < userData->banyak_pengguna; i++) {
        printf("\nReading user %d\n", i);

        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        // simpan nama user
        userData->dataNama[i] = currentWord;
        // printf("Nama: %s\n", userData->dataNama[i].TabWord);

        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        // simpan password user
        userData->password[i] = currentWord;
        // printf("Password: %s\n", userData->password[i].TabWord);

        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        // simpan bio user
        userData->bio[i] = currentWord;
        // printf("Bio: %s\n", userData->bio[i].TabWord);

        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        // simpan phone user
        userData->phone[i] = currentWord;
        // printf("Phone: %s\n", userData->phone[i].TabWord);

        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        // simpan weton user
        userData->Weton[i] = currentWord;
        // printf("Weton: %s\n", currentWord.TabWord);

        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        // simpan jenis akun user
        if (currentWord.TabWord[0] == 'P') {
            userData->JenisAkun[i] = Publik;
        } else {
            userData->JenisAkun[i] = Privat;
        }
        // printf("Jenis akun: %s\n", currentWord.TabWord);

        // Read Profile ignore blank in between words
        // printf("Profile:\n");
        for (int j = 0; j < 5; j++) {
            ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
            // printf("%s\n", currentWord.TabWord);
        }
    }
    // printf("\nReading adjacency matrix:\n");
    for (int i = 0; i < userData->banyak_pengguna; i++) {
        for (int j = 0; j < userData->banyak_pengguna; j++) {
            ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
            userData->adjacencyMatrix[i][j] = toInt(currentWord);
            printf("%d ", userData->adjacencyMatrix[i][j]);
        }
        // printf("\n");
    }

    // Read friendship requests
    ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    int banyak_permintaan = toInt(currentWord);
    // printf("\nBanyak permintaan pertemanan: %d\n", banyak_permintaan);

    for (int i = 0; i < banyak_permintaan; i++) {
        ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
        int senderID = toInt(currentWord);
        
        ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
        int receiverID = toInt(currentWord);
        
        ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
        int friendCount = toInt(currentWord);
        
        // printf("%d %d %d\n", senderID, receiverID, friendCount);
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
    jumlah_kicau = toInt(currentWord);
    printf("Jumlah kicauan: %d\n", jumlah_kicau);

    // Membaca kicauan
    for (int i = 0; i < jumlah_kicau; i++) {
        printf("\nReading kicau %d\n", i);

        // Membaca id kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        kicau->id = toInt(currentWord);
        printf("ID: %d\n", kicau->id);

        // Membaca text kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        kicau->Text.Length = currentWord.Length;
        for (int j = 0; j < currentWord.Length; j++) {
            kicau->Text.TabWord[j] = currentWord.TabWord[j];
        }
        printf("Text: %s\n", kicau->Text.TabWord);

        // Membaca jumlah like kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        kicau->Likes = toInt(currentWord);
        printf("Likes: %d\n", kicau->Likes);

        // Membaca author kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        kicau->Auth.Length = currentWord.Length;
        for (int j = 0; j < currentWord.Length; j++) {
            kicau->Auth.TabWord[j] = currentWord.TabWord[j];
        }

        // Membaca tanggal waktu kicauan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        kicau->dates = WordToDateTime(currentWord);
        printf("Datetime: %02d/%02d/%04d %02d:%02d:%02d\n", Day(kicau->dates), Month(kicau->dates), Year(kicau->dates),
               kicau->dates.T.HH, kicau->dates.T.MM, kicau->dates.T.SS);
    
    }
    fclose(file);
}


// Implementasi fungsi ReadBalasanData
void ReadBalasanData(char* filename, Balasan* balasan) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    } else {
        printf("File %s opened successfully\n", filename);
    }
    printf("Filename: %s\n", filename);

    // Membaca banyak kicauan yang memiliki balasan
    STARTFILEWORD(filename);
    balasan->kicauBalas = toInt(currentWord);
    printf("Jumlah balasan: %d\n", balasan->kicauBalas);

    // Membaca id kicauan yang memiliki balasan
    ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    balasan->idKicau = toInt(currentWord);
    // printf("ID: %d\n", balasan->idKicau);

    // Membaca banyak balasan yang diterima
    ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
    balasan->banyakBalasan = toInt(currentWord);
    // printf("Banyak balasan: %d\n", balasan->banyakBalasan);

    // Membaca balasan
    for (int i = 0; i < balasan->banyakBalasan; i++) {

        // Membaca id parent
        ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
        balasan->idParent = toInt(currentWord);
        // printf("ID parent: %d\n", balasan->idParent);

        // Membaca id balasan
        ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
        balasan->idBalasan = toInt(currentWord);
        // printf("ID balasan: %d\n", balasan->idBalasan);

        // Membaca teks balasan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        balasan->teksBalasan = currentWord;
        // printf("%s\n", balasan->teksBalasan.TabWord);

        // Membaca penulis balasan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        balasan->penulis = currentWord;
        // printf("Nama : %s\n", balasan->penulis.TabWord);
        // Membaca tanggal waktu balasan
        ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
        balasan->dates = WordToDateTime(currentWord);
        // printf("Datetime: %02d/%02d/%04d %02d:%02d:%02d\n", Day(balasan->dates), Month(balasan->dates), Year(balasan->dates),
            //    balasan->dates.T.HH, balasan->dates.T.MM, balasan->dates.T.SS);

    }


    fclose(file);
}


// Implementasi fungsi ReadDrafData
void ReadDrafData(const char *filename, ListDraf *listDraf) {
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

    // Read the number of users with drafts
    listDraf->banyak_pengguna = toInt(currentWord);
    printf("Number of users with drafts: %d\n", listDraf->banyak_pengguna);

    // Read user drafts
    for (int i = 0; i < listDraf->banyak_pengguna; i++) {
        listDraf->users[i].username.Length = 0;

        while (1) {
            ADVWORD(); currentWord.TabWord[currentWord.Length] = '\0';
            if (isdigit(currentWord.TabWord[0])) {
                listDraf->users[i].banyak_draf = toInt(currentWord);
                printf("Nama: %s\n", listDraf->users[i].username.TabWord);
                printf("Banyak draf: %d\n", listDraf->users[i].banyak_draf);
                break;
            } else {
                for (int j = 0; j < currentWord.Length; j++) {
                    listDraf->users[i].username.TabWord[listDraf->users[i].username.Length] = currentWord.TabWord[j];
                    listDraf->users[i].username.Length++;
                }
                listDraf->users[i].username.TabWord[listDraf->users[i].username.Length] = ' ';
            }
        }

        for (int j = 0; j < listDraf->users[i].banyak_draf; j++) {
            // Isi draft
            ADVLINE(); currentWord.TabWord[currentWord.Length] = '\0';
            listDraf->users[i].draf[j].text.Length = currentWord.Length;
            printf("Text draft %d: %s\n", j + 1, currentWord.TabWord);

            // Datetime draft
            ADVLINE();
            currentWord.TabWord[currentWord.Length] = '\0';
            listDraf->users[i].draf[j].datetime = WordToDateTime(currentWord);
            printf("Datetime draft %d: %02d/%02d/%04d %02d:%02d:%02d\n", j + 1,
                Day(listDraf->users[i].draf[j].datetime),
                Month(listDraf->users[i].draf[j].datetime),
                Year(listDraf->users[i].draf[j].datetime),
                listDraf->users[i].draf[j].datetime.T.HH,
                listDraf->users[i].draf[j].datetime.T.MM,
                listDraf->users[i].draf[j].datetime.T.SS);
        }

    }

    fclose(file);
}


// Implementasi fungsi ReadUtasData
void ReadUtasData(const char *filename, DataUtas *dataUtas) {
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

    // Read the number of kicauan
    dataUtas->banyak_kicauan = toInt(currentWord);
    printf("Number of kicauan: %d\n", dataUtas->banyak_kicauan);

    for (int i = 0; i < dataUtas->banyak_kicauan; i++) {
        // Read kicauan id
        ADVLINE();
        currentWord.TabWord[currentWord.Length] = '\0';
        dataUtas->kicauans[i].id_kicauan = toInt(currentWord);
        printf("ID kicauan %d: %d\n", i + 1, dataUtas->kicauans[i].id_kicauan);

        // Read the number of utas for this kicauan
        ADVLINE();
        currentWord.TabWord[currentWord.Length] = '\0';
        dataUtas->kicauans[i].banyak_utas = toInt(currentWord);
        printf("Number of utas for kicauan %d: %d\n", i + 1, dataUtas->kicauans[i].banyak_utas);

        // Read utas data
        for (int j = 0; j < dataUtas->kicauans[i].banyak_utas && j < MAX_UTAS_PER_KICAUAN; j++) {
            // Read utas text
            ADVLINE();
            currentWord.TabWord[currentWord.Length] = '\0';
            dataUtas->kicauans[i].utas[j].text = currentWord;
            printf("Text utas %d: %s\n", j + 1, dataUtas->kicauans[i].utas[j].text.TabWord);

            // Read utas author
            ADVLINE();
            currentWord.TabWord[currentWord.Length] = '\0';
            dataUtas->kicauans[i].utas[j].author = currentWord;
            printf("Author utas %d: %s\n", j + 1, dataUtas->kicauans[i].utas[j].author.TabWord);

            // Read utas datetime
            ADVLINE();
            currentWord.TabWord[currentWord.Length] = '\0';
            dataUtas->kicauans[i].utas[j].datetime = WordToDateTime(currentWord);
            printf("Datetime utas %d: %02d/%02d/%04d %02d:%02d:%02d\n", j + 1,
                Day(dataUtas->kicauans[i].utas[j].datetime),
                Month(dataUtas->kicauans[i].utas[j].datetime),
                Year(dataUtas->kicauans[i].utas[j].datetime),
                dataUtas->kicauans[i].utas[j].datetime.T.HH,
                dataUtas->kicauans[i].utas[j].datetime.T.MM,
                dataUtas->kicauans[i].utas[j].datetime.T.SS);
        }
    }

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
        printf("Membaca file %s\n", filename);
        FILE *file = fopen(filename, "r");

        if (file == NULL) {
            printf("Error: Cannot open file %s\n", filename);
            continue;
        }


        // Initialize the word machine
        STARTFILEWORD(filename);
        printf("Word machine initialized\n");

        // Read data from the file using wordmachine
        if (i == 0) {
            UserData userData;
            ReadUserData(filename, &userData);
            // TODO: Handle UserData as needed
        } else if (i == 1) {
            kicauan kicauData;
            ReadKicauData(filename, &kicauData);
            // TODO: Handle kicauan as needed
        } else if (i == 2) {
            Balasan balasan;
            ReadBalasanData(filename, &balasan);
            // TODO: Handle Balasan as needed
        } else if (i == 3) {
            ListDraf listDraf;
            ReadDrafData(filename, &listDraf);
            // TODO: Handle ListDraf as needed
        } else if (i == 4) {
            DataUtas datautas;
            ReadUtasData(filename, &datautas);
            // TODO: Handle DataUtas as needed
        }

        fclose(file);
    }
}