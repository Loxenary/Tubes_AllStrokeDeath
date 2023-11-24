#include "inisialisasi.h"
#include "database.h"
#include "utas.h"

#define FILENAME_MAX_LENGTH 256 // Adjust the size as needed

void displayScreen() {
    printf("%s", LIGHT_BLUE);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣾⣶⣄⣀⠀⠀⠀⠀⠀⣀⡄⠀   \n");
    printf("⠀⠀⢰⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣴⣶⣾⣿⠏⠀ ⠀\n");
    printf("⠀⠀⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣡⣤⡴⠆\n");
    printf("⠀⠀⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠏⠁⠀\n");
    printf("⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣷⣀⡀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀ ⠀\n");
    printf("⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⣤⣤⣀⣀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀\n");
    printf("⠀⠀⣄⣀⢙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀\n");
    printf("⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀\n");
    printf("⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠈⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⡀⢉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀ ⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⣀⣀⣠⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠈⠛⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠉⠛⠛⠿⠿⢿⣿⣿⣿⣿⣿⡿⡿⠿⠛⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀\n");
    printf("%s", NORMAL);
    // print the following text in pink color
    printf("%s", PINK);
    printf("✩░▒▓▆▅▃▂▁WELCOME TO▁▂▃▅▆▓▒░✩\n");
    printf("\n");
    printf("%s", NORMAL);
    printf(" ▄▄▄▄▄▄▄ ▄▄   ▄▄ ▄▄▄▄▄▄   ▄▄▄▄▄▄▄ ▄▄▄ ▄▄▄▄▄▄   \n");
    printf("█  ▄    █  █ █  █   ▄  █ █  ▄    █   █   ▄  █  \n");
    printf("█ █▄█   █  █ █  █  █ █ █ █ █▄█   █   █  █ █ █  \n");
    printf("█       █  █▄█  █   █▄▄█▄█       █   █   █▄▄█▄ \n");
    printf("█  ▄   ██       █    ▄▄  █  ▄   ██   █    ▄▄  █\n");
    printf("█ █▄█   █       █   █  █ █ █▄█   █   █   █  █ █\n");
    printf("█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄▄▄█  █▄█▄▄▄▄▄▄▄█▄▄▄█▄▄▄█  █▄█\n");
    printf("\n");
    printf("🌟  ٩◔̯◔۶");
    printf("%s", PINK);
    printf(" Klenting Biru ");
    printf("%s", NORMAL);
    // print "do your magic" in light blue
    printf("%s", LIGHT_BLUE);
    printf("do your magic");
    printf("%s", NORMAL);
    printf(" ٩◔̯◔۶  🌟\n");
    printf("\n");
}

void readLine(){
    ADVLINE();
    currentWord.TabWord[currentWord.Length] = '\0';
    currentWord.Length--;
}

void readLineDin(){
    ADVLINEDIN();
    currentWordDin.container[currentWordDin.Length] = '\0';
    currentWordDin.Length--;
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
    SwdCreateListStatik(&phone);
    SwCreateListStatik(&Weton);
    CreateListTree(&list_balasan,100);
    CreateListStatik(&JenisAkun);
    CreateListStatikMatrix(&profil);
    CreateListDinUtas(&utas_pointers, 100);

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
        readLineDin();
        // WordDin wrd;
        // CreateWord(&wrd,1000);
        SwdinsertLast(&phone,currentWordDin);
        // wrd.container = currentWord.TabWord;
        // SwinsertLastWordDin(&phone,wrd);
        // printWordDin(wrd);

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
            SinsertLast(&JenisAkun,Public);
        } else {
            SinsertLast(&JenisAkun,Private);
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
                MELMT(temp,j,k) = currentWord.TabWord[k*2];
            }
        }
        displayMatrixCharColoured(temp);
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

    return -1;
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
        // Read jumlah balasan
        readLine();
        int jumlah_balasan = toInt(currentWord);
        int j;
        for(j = 0; j < jumlah_balasan; j++){
            readLine();
            int h = 0;
            char a = currentWord.TabWord[0];
            Word temp;
            while (a != ' ')
            {
                temp.TabWord[h] = currentWord.TabWord[h];
                h++;
                a = currentWord.TabWord[h];
            }
            temp.Length = h;
            int id = toInt(temp);
            // printf("%d",id);

            a = currentWord.TabWord[h];
            Word temp2;
            int k = 0;
            while (h < currentWord.Length)
            {
                temp2.TabWord[k] = currentWord.TabWord[h];
                h++;
                a = currentWord.TabWord[h];
                k++;
            }
            temp2.Length = k;
            int id2 = toInt(temp2);
                        
            readLine();
            Word text = currentWord;

            readLine();
            Word auth = currentWord;
            
            readLine();
            
            DATETIME date = WordToDatetime(currentWord);
            printf("\n");

            bacaConfigBalasan(&list_balasan,id_kicau,id,id2,text,auth,date);
        }
        printf("ini kicauan\n\n");
        printDataKicauan(KELMT(list_kicau,id_kicau-1));
        printf("\nini balasannya\n\n");
        displayTreeFull(BELMT(list_balasan,id_kicau-1));
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
    return (c >= '0' || c <= '9');
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
    currentWord.TabWord[currentWord.Length] = '\0';
    // Read the number of users with drafts
    jumlah_Draf = toInt(currentWord);
    printf("Number of users with drafts: %d\n", jumlah_Draf);
    int _temp_amount = 0;
    CreateListStatikstack(&draf);
    int i;
    for(i = 0; i < jumlah_Draf; i++){
        _temp_amount = 0;
        readLine();
        int k = 1;
        char a = currentWord.TabWord[currentWord.Length-k];
        int multiplayer= 1;
        while (a != BLANK)
        {
            _temp_amount += (a - '0') * multiplayer;
            multiplayer *= 10;
            k++;
            a = currentWord.TabWord[currentWord.Length - k];
        }
        Word _current_user;
        int h = 0;
        int batas = currentWord.Length - k;
        for(k = 0; k < batas; k++){
            _current_user.TabWord[h] = currentWord.TabWord[k];
            h++;
        }
        _current_user.Length = h;
        printWord(_current_user);
        printf(" %d\n",_temp_amount);
        int id_kicau = SwindexOf(dataNama,_current_user);
        Stack _temp_stack;
        Stack _not_temp_stack;
        CreateEmpty(&_temp_stack);
        CreateEmpty(&_not_temp_stack);
        for(h = 0; h < _temp_amount;h++){
            readLine();
            Word text= currentWord;
            printWord(currentWord);
            printf("\n");
            readLine();
            printWord(currentWord);
            DATETIME date = WordToDatetime(currentWord);
            printf("\n");
            Push(&_temp_stack,text, date);
        }
        for(h = 0; h < _temp_amount; h++){
            Word _temp_text;
            DATETIME _temp_time;
            Pop(&_temp_stack,&_temp_text,&_temp_time);
            Push(&_not_temp_stack,_temp_text,_temp_time);
        }
        overwriteDraf(&draf,id_kicau,_not_temp_stack);
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
    kicau_have_utas = haveUtas;
    int i;
    
    for(i =0; i< haveUtas; i++){
        readLine();
        int id_kicau = toInt(currentWord);
        int j;
        readLine();
        printWord(currentWord);
        int jumlah_utas = toInt(currentWord);
        printf("\n");
        int id = 1;
        
        //akses next addres dari kicauan dgn id = id_utas

        
        ListUtas lk = (KELMT(list_kicau, i)).next_Utas;

        // INSERT TO LIST DIN UTASAN
        for(j = 0; j < jumlah_utas; j++){
            
            //TEXT
            readLine();
            Word _text = currentWord;
            printWord(_text);
            printf("\n");

            //AUTHOR
            readLine();
            Word _auth = currentWord;            
            //DATE
            readLine();
            DATETIME _time = WordToDatetime(currentWord);
            printf("\n");
            addUtas(&(KELMT(list_kicau, id_kicau).next_Utas),listLengthDinUtas(utas_pointers)+1,id_kicau,_text,_auth,_time);
            if(j == 0){
                insertLastDinUtas(&utas_pointers, KELMT(list_kicau, id_kicau).next_Utas);
            }
            id++;
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

    START();
    int i = 0;

    // Read characters until a non-alphanumeric character or MARK is encountered
    while (currentChar != MARK) {
        folder[i] = currentChar;
        ADV(); // Ensure to call ADV to move to the next character
        i++;
    }

    // Null-terminate the folder name
    folder[i] = '\0';

    char fileNames[5][20] = {"pengguna.config", "kicauan.config", "balasan.config", "draf.config", "utas.config"};

    for (int i = 0; i < 5; ++i) {
        sprintf(filename, "%s/%s", folder, fileNames[i]);
        
        // Initialize the word machine
        STARTFILEWORD(filename);
        printf("Word machine initialized\n");

        // TODO: Read data from the file using wordmachine and handle it as needed
        // Example:
        if (i == 0) {
            ReadUserData(filename);
        } else if (i == 1) {
            ReadKicauData(filename);
        } else if (i == 2) {
            ReadBalasanData(filename);
        } else if (i == 3) {
            ReadDrafData(filename);
        } else if (i == 4) {
            ReadUtasData(filename);
        }
    }
}