#include "simpan.h"
#include "database.h"
#include "kicau.h"

boolean isDirectoryExists(const char *path) {
    struct stat st;
    return stat(path, &st) == 0 && S_ISDIR(st.st_mode);
}

int stringLength(char * string){
    int i= 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}

int createDirectory(char *path) {
    char *temp = (char *) malloc (strlen(path) + 1);
    char *tempIter = temp;
    const char *pathIter = path;

    while (*pathIter != '\0') {
        if (*pathIter == '/') {
            *tempIter = '\0';
            if (!isDirectoryExists(temp) && mkdir(temp, 0777) != 0) {
                free(temp);
                return 1; 
            }
            *tempIter = '/';
        } else {
            *tempIter = *pathIter;
        }

        tempIter++;
        pathIter++;
    }

    *tempIter = '\0';

    if (mkdir(path, 0777) != 0) {
        free(temp);
        return 1;  
    }

    free(temp);
    return 0; 
}

void copyPath(char * dest, char * src){
    int i;
    for(i = 0; i < stringLength(src); i++){
        dest[i] = src[i];
    }
}

void saveBalasan(Word folder_path){
    Word addition = StringToWord("/balasan.config",15);
    Word path = ConcatWord(folder_path,addition);
    path.TabWord[path.Length] = '\0';
    FILE *f2 = fopen(path.TabWord, "w");
    if (f2 == NULL) {
        printf("Error: ");
        printWord(path);
        printf(" tidak dapat dibuat.\n");
        return;
    }
    else{
        fprintf(f2,"%d\n",kicauWithBalasan());
        int i;
        for(i = 0; i < BNEFF(list_balasan);i++){
            if(hasChild(BELMT(list_balasan,i))){
                fprintf(f2,"%d\n",BID(Root(BELMT(list_balasan,i))));
                fprintf(f2,"%d\n",countChildren(Root(BELMT(list_balasan,i)))-1);
                writeBalasan(FirstChild(Root(BELMT(list_balasan,i))),f2,i);
            }
        }
    }
    fclose(f2);


}

void saveDraf(Word folder_path){
    Word addition = StringToWord("/draf.config",12);
    Word path = ConcatWord(folder_path,addition);
    path.TabWord[path.Length] = '\0';
    FILE *f2 = fopen(path.TabWord, "w");
    if (f2 == NULL) {
        printf("Error: ");
        printWord(path);
        printf(" tidak dapat dibuat.\n");
        return;
    }
    else{
        writeStack(f2);
    }
    fclose(f2);
}

void saveUtas(Word folder_path){
    Word addition = StringToWord("/utas.config",12);
    Word path = ConcatWord(folder_path,addition);
    path.TabWord[path.Length] = '\0';
    FILE *f2 = fopen(path.TabWord, "w");
    if (f2 == NULL) {
        printf("Error: ");
        printWord(path);
        printf(" tidak dapat dibuat.\n");
        return;
    }
    else{
        fprintf(f2,"%d\n",utas_pointers.nEff);
        int i,j;
        for(i = 0; i < utas_pointers.nEff; i++){
            int k = ELMTD_LDU(utas_pointers,i)->Idkicau;
            fprintf(f2,"%d\n",k);
            int amount = length_LinkedUtas(KELMT(list_kicau,k-1).next_Utas);
            fprintf(f2,"amount: %d\n",amount);
            for(j = 0; j < amount ;j++){
                writeFile(ELMTD_LDU(utas_pointers,i)->texts,f2);
                writeFile(ELMTD_LDU(utas_pointers,i)->Author,f2);
                writeDATETIME(ELMTD_LDU(utas_pointers,i)->dateTime,f2);
            }
        }
    }
    fclose(f2);
}

void saveKicauan(Word folder_path){

    Word addition = StringToWord("/kicauan.config",15);
    Word path = ConcatWord(folder_path,addition);
    path.TabWord[path.Length] = '\0';
    FILE *f2 = fopen(path.TabWord, "w");
    if (f2 == NULL) {
        printf("Error: ");
        printWord(path);
        printf(" tidak dapat dibuat.\n");
        return;
    }
    else{
        fprintf(f2,"%d\n",list_kicau.nEff);  
        int i;
        for(i = 0; i < jumlah_kicau; i++){
            kicauan k = KELMT(list_kicau,i);
            Word text = k.Text;
            Word auth = k.Auth;
            fprintf(f2,"%d\n",k.id);
            writeFile(text,f2);
            fprintf(f2,"\n");
            fprintf(f2,"%d\n",k.Likes);
            writeFile(auth,f2);
            fprintf(f2,"\n");
            writeDATETIME(k.dates,f2);
            if(i != jumlah_kicau-1){
                fprintf(f2,"\n");
            }
        }
    }
    fclose(f2);
}

void savePengguna(Word folder_path){

    Word addition = StringToWord("/pengguna.config",16);
    Word path = ConcatWord(folder_path,addition);
    path.TabWord[path.Length] = '\0';
    FILE *f2 = fopen(path.TabWord, "w");
    if (f2 == NULL) {
        printf("Error: ");
        printWord(path);
        printf(" tidak dapat dibuat.\n");
        return;
    }
    else{

        //Jumlah Pengguna
        fprintf(f2,"%d\n",banyak_pengguna);
        int i;
        for(i = 0; i < banyak_pengguna; i++){
            writeFile(SELMT(dataNama,i),f2);
            fprintf(f2,"\n");
            writeFile(SELMT(password,i),f2);
            fprintf(f2,"\n");
            writeFile(SELMT(bio,i),f2);
            fprintf(f2,"\n");
            writeDinFile(phone.contents[i],f2);
            writeFile(SELMT(Weton,i),f2);
            fprintf(f2,"\n");
            readPrivatePublic(ELMT(JenisAkun,i),f2);
            writeMatrixChar(LSMELMT(profil,i),f2);
        }
        writeAdjMatrix(matPertemanan,f2);
        fprintf(f2,"%d\n",addFriendCounter);
        writePermintaanTeman(permintaanTeman,f2);
    }

    fclose(f2);
}

void Simpan(){
    printf("Masukkan folder penyimpanan konfig: \n");

    STARTWORD();
    currentWord.TabWord[currentWord.Length] = '\0';
    printWord(currentWord);
    if (createDirectory(currentWord.TabWord) == 0) {
        printf("\nFolder %s berhasil dibuat.\n", currentWord.TabWord);
    } else {
        printf("\nFolder %s sudah tersedia.\n", currentWord.TabWord);
    }

    savePengguna(currentWord);
    saveKicauan(currentWord);
    saveUtas(currentWord);
    saveDraf(currentWord);
    saveBalasan(currentWord);
}


char * WordToString(Word w){
    int i;
    char * c = "";
    for(i = 0; i < w.Length; i++){
        c[i] = w.TabWord[i];
    }
    return c;
}

void writeMatrixChar(MatrixChar m,FILE *f){
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            fprintf(f,"%c", MCELMT(m, i, j));
            if(j != 9){
                fprintf(f," ");
            }
        }
        fprintf(f,"\n");
    }
}

void readPrivatePublic(int i, FILE *f){
    if(i == 0){
        fprintf(f,"Publik\n");
    }
    else if(i == 1){
        fprintf(f,"Privat\n");
    }
}

void writeFile(Word w1,FILE *f){
   int i;
   for (i = 0; i < w1.Length; i++) {
      fprintf(f,"%c", w1.TabWord[i]);
   }
}


void writeDinFile(WordDin w1, FILE *f){
   int i;
   for (i = 0; i < w1.Length; i++) {
      fprintf(f,"%c", w1.container[i]);
   }
   fprintf(f,"\n");
}

void writeAdjMatrix(AdjMatrix m, FILE *f){
    int i,j;
    for(i = 0; i < Vert(m);i++){
        for(j = 0; j < Vert(m); j++){
            fprintf(f,"%d",GGELMT(m,i,j)); 
            if(j < Vert(m)-1){
                fprintf(f," ");
            }
        }
        fprintf(f,"\n");
    }
}

void writePermintaanTeman(PrioQueue p, FILE *f){
    int i;
    int len = addFriendCounter;
    for(i = 0; i < len; i++){
        fprintf(f,"%d %d %d",toInt(permintaanTeman.array[i].pengirim),toInt(permintaanTeman.array[i].penerima),permintaanTeman.array[i].kepopuleran);
        if(i != len-1){
            fprintf(f,"\n");
         }
    }
}


void writeDATETIME(DATETIME D,FILE *f){
    fprintf(f,"%d/%d/%d ",Day(D),Month(D),Year(D));
    writeTime(D.T,f);
}

void writeTime(TIME T,FILE *f){
    fprintf(f,"%02d:%02d:%02d",Hour(T),Minute(T),Second(T));
}

int kicauWithBalasan(){
    int i;
    int counter = 0;
    for(i = 0; i < BNEFF(list_balasan);i++){
        if(hasChild(BELMT(list_balasan,i))){
            counter++;
        }
    }
    return counter;
}

void writeStack(FILE *f){
    int i;
    int container = 0;
    fprintf(f,"%d\n",jumlah_Draf);
    for(i = 0; i < LSCAPACITY; i++){
        if(!IsEmpty(LSSELMT(draf,i))){
            container++;
            Word name = SELMT(dataNama,i);

            int j;
            writeFile(name,f);
            Isianstack s1 = ambilDrafdanDatetime(draf,i);
            fprintf(f," %d\n",Top(s1)+1);
            j  = 0;
            while (!IsEmpty(s1))
            {
                Word w;
                DATETIME t;
                Pop(&s1,&w,&t);
                writeFile(w,f);
                fprintf(f,"\n");
                writeDATETIME(t,f);
                if(container != jumlah_Draf || j < Top(s1)+1){
                    fprintf(f,"\n");
                }  
                j++;
            }
        }
    }
}

void writeBalasan(addressTree node,  FILE *file, int i) {
    if (node == NULL) {
        return;
    }
    
    if (PID(node) == -1)  
    {   
        fprintf(file, "%d ", -1);
    }
    else
    {   
        addressTree idparent = findParent(Root(BELMT(list_balasan,i)),BID(node));
        fprintf(file, "%d ", BID(idparent));
    }
     
    fprintf(file, "%d\n", BID(node));
    writeFile(BTEXT(node),file);
    fprintf(file,"\n");
    writeFile(BAUTH(node),file);
    fprintf(file,"\n");
    writeDATETIME(BDATE(node),file);
    fprintf(file,"\n");
    
    // Recursive
    writeBalasan(FirstChild(node),file,i);
    writeBalasan(NextSibling(node),file,i);
}