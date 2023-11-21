#include <stdio.h>

#include "inisialisasi.h"
#include "database.h"
#include "utas.h"
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
void ReadUserData(const char *filename) {
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
    CreateListTree(&list_balasan,100);
    CreateListStatik(&JenisAkun);
    CreateListStatikMatrix(&profil);

    printf("\n");
    
    SwprintList(dataNama);
    printf("\n");
    CreateAdjMatrix(&matPertemanan,banyak_pengguna);
    PrioQueueInitialize(&permintaanTeman,100);

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
    addFriendCounter = toInt(currentWord);
    // printf("\nBanyak permintaan pertemanan: %d\n", banyak_permintaan);
    Word sender, receiver;
    int popularity;
    PermintaanPertemanan _friendReq_temps;
    for (i = 0; i < addFriendCounter; i++) {
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
                    sender = temps;
                    break;
                case 2:
                    receiver = temps;
                    break;
                case 3:
                    popularity = toInt(temps);
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
        _friendReq_temps.pengirim = sender;
        _friendReq_temps.penerima = receiver;
        _friendReq_temps.kepopuleran = popularity;
        printWord(_friendReq_temps.pengirim); printf(" ");
        printWord(_friendReq_temps.penerima); printf(" ");
        printf("%d",_friendReq_temps.kepopuleran); printf("\n");
        Enqueue(&permintaanTeman,_friendReq_temps);
    }

    fclose(file);
}

int read_id_balasan(){
    int i;
    Word temps;
    for(i =0; i < currentWord.Length; i++){
        char a = currentWord.TabWord[i];
        if(a == BLANK){
            temps.Length = i+1;
            return toInt(temps);
        }
        temps.TabWord[i] = a;
    }
}

// Implementasi fungsi ReadKicauData
void ReadKicauData(char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    } else {
        printf("File %s opened successfully\n", filename);
    }
    printf("Filename: %s\n", filename);

    STARTFILEWORD(filename);
    currentWord.TabWord[currentWord.Length] = '\0';
    currentWord.Length--;
    // Membaca banyak kicauan
    CreateListKicau(&list_kicau, 50); //50 as starter
    jumlah_kicau = toInt(currentWord);
    printf("Jumlah kicauan: %d\n", jumlah_kicau);

    kicauan _temp_kicau;
    Word _temp_word;
    int _temp_likes;
    Word _temp_auth;
    DATETIME _temp_time;
    int i;
    int len = jumlah_kicau;
    // Membaca kicauan
    for (i = 0; i < len; i++) {
        printf("\nReading kicau %d\n", i+1);

        // Membaca id kicauan
        readLine();
       
       
        int id = toInt(currentWord);
        // Membaca text kicauan

        readLine();
        
        _temp_word = currentWord;
       

        // Membaca jumlah like kicauan
        readLine();
        _temp_likes = toInt(currentWord);
       

        // Membaca author kicauan
        readLine(); 
        _temp_auth = currentWord;

        // Membaca tanggal waktu kicauan

        readLine();
        currentWord.Length++;
        _temp_time =  WordToDatetime(currentWord);
        
        
        _temp_kicau = CreateDefinedKicau(_temp_auth,_temp_word,_temp_likes,_temp_time,id);
        InsertDeclaredLastKicau(&list_kicau,_temp_kicau);
        DisplayKicauan(list_kicau,id);
    }
    printf("\n");

    fclose(file);
}


// Implementasi fungsi ReadBalasanData
void ReadBalasanData(char* filename) {
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
    jumlah_balasan = toInt(currentWord);
    printf("Jumlah kicau yang punya balasan: %d\n", jumlah_balasan);
    int i;
    for(i = 0; i < jumlah_balasan; i++){
        readLine();
        int id_kicau = toInt(currentWord);
        printf("%d\n",id_kicau);
        
        // Read jumlah balasan
        readLine();
        int jumlah_balasan = toInt(currentWord);
        printf("%d\n",jumlah_balasan);

        int j;
        for(j = 0; j < jumlah_balasan; j++){
            readLine();
            inputBalas(&list_balasan,id_kicau,0);
            printf("id: %d\n",read_id_balasan());
        }
    }

    // Membaca id kicauan yang memiliki balasan
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

int isNum(char c){
    if(c >= '0' || c <= '9');
}

void readDrafHead(Word *Auth, int * amount){
    int i;
    int k = 0;
    int counter = 0;
    Word temps;
    for(i = 0; i < currentWord.Length; i++){
        char a = currentWord.TabWord[i];
        if(a == BLANK || isNum(a)){
            counter++;
        }
        if(counter == 1){
            Auth->Length = k;
            k = 0;
            
        }
        else if(counter > 1){
            temps.TabWord[k] = currentWord.TabWord[i];
            k++;
        }
        else{
            Auth->TabWord[k] = currentWord.TabWord[i];
            k++;
        }
    }
    temps.Length = k;
    *amount = toInt(temps);
}

// Implementasi fungsi ReadDrafData
void ReadDrafData(const char *filename) {
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
    jumlah_Draf = toInt(currentWord);
    printf("Number of users with drafts: %d\n", jumlah_Draf);

    CreateListStatikstack(&draf);
    Isianstack _Auth_Temps;
    Isianstack _Time_Temps;
    Word _Auth_Word;
    int _amount_Temps;
    int j;
    CreateEmpty(&_Auth_Temps);
    printf("test");
    // Read user drafts
    for (int i = 0; i < jumlah_Draf; i++) {
        readLine();
        readDrafHead(&_Auth_Word, &_amount_Temps);
        int id = SwindexOf(dataNama,_Auth_Word);
        printWord(_Auth_Word);
        printf("\n");
        printf("%d\n",_amount_Temps);
        for(j= 0; j < _amount_Temps; j++){
            readLine();
            Push(&_Auth_Temps,currentWord);
            LSSELMT(draf,id) = _Auth_Temps;
            readLine();
            Push(&_Auth_Temps, currentWord);
            LSSTELMT(draf,id) = _Time_Temps;
        }
    }
    fclose(file);
}


// Implementasi fungsi ReadUtasData
void ReadUtasData(const char *filename) {
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

    int haveUtas = toInt(currentWord);
    
    int i;
    CreateListDinUtas(&utas_pointers, 100);
    for(i =0; i< haveUtas; i++){
        readLine();
        int id_utas = toInt(currentWord);
        int j;
        readLine();
        printWord(currentWord);
        int jumlah_utas = toInt(currentWord);
        printf("\n");
        int id = 1;
        for(j = 0; j < jumlah_utas; j++){
            ListUtas temps;
            CreateUtas(&temps);
            
            //TEXT
            readLine();
            Word _text = currentWord;
            printWord(_text);
            printf("\n");

            //AUTHOR
            readLine();
            Word _auth = currentWord;
            printWord(_auth);
            printf("\n");
            
            //DATE
            readLine();
            DATETIME _time = WordToDatetime(currentWord);
            TulisDATETIME(_time);
            printf("\n");
            addUtas(&temps,id,id_utas,_text,_auth,_time);
            id++;
            if(temps == NULL){
                printf("llalalapopop");
                break;
            }
            CetakUtas(temps);
        }
        
    }
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

            ReadUserData(filename);
            //Done
        } else if (i == 1) {
            ReadKicauData(filename);
            //Done
            // TODO: Handle kicauan as needed
        } else if (i == 2) {
            // ReadBalasanData(filename);
            // TODO: Handle Balasan as needed
        } else if (i == 3) {
            // ListDraf listDraf;
            // ReadDrafData(filename, &listDraf);
            // TODO: Handle ListDraf as needed
        } else if (i == 4) {
            // DataUtas datautas;
            ReadUtasData(filename);
            // TODO: Handle DataUtas as needed
        }
    }
}