#include "simpan.h"
#include "database.h"

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

void saveBalasan(char *folder_path){
    char *path = (char *) malloc (stringLength(folder_path) + 20);
    strcpy(path,folder_path);
    strcat(path, "/balasan.config");
    FILE *f2 = fopen(path, "w");
    if (f2 == NULL) {
        printf("Error: %s tidak dapat dibuat.\n", path);
        return;
    }



    fclose(f2);
    free(path);
}

void saveDraf(char *folder_path){
    char *path = (char *) malloc (stringLength(folder_path) + 20);
    strcpy(path, folder_path);
    strcat(path, "/draf.config");

    FILE *f2 = fopen(path, "w");
    if (f2 == NULL) {
        printf("Error: %s tidak dapat dibuat.\n", path);
        return;
    }




    fclose(f2);
    free(path);
}

void saveUtas(char *folder_path){
    char *path = (char *) malloc (stringLength(folder_path) + 20);
    strcpy(path, folder_path);
    strcat(path, "/utas.config");

    FILE *f2 = fopen(path, "w");
    if (f2 == NULL) {
        printf("Error: %s tidak dapat dibuat.\n", path);
        return;
    }

    // fprintf(f2, "%d\n", JumlahUtas);



    fclose(f2);
    free(path);

}

void saveKicauan(char *folder_path){

    char *path = (char *) malloc (stringLength(folder_path) + 20);
    strcpy(path, folder_path);
    strcat(path, "/kicauan.config");

    FILE *f2 = fopen(path, "w");
    if (f2 == NULL) {
        printf("Error: %s tidak dapat dibuat.\n", path);
        return;
    }


    fclose(f2);
    free(path);
}

void savePengguna(char *folder_path){

    char *path = (char *) malloc (stringLength(folder_path) + 17);
    strcpy(path, folder_path);
    strcat(path, "/pengguna.config");

    FILE *f2 = fopen(path, "w");
    if (f2 == NULL) {
        printf("Error: %s tidak dapat dibuat.\n", path);
        return;
    }

    //Jumlah Pengguna
    fprintf(f2,"%d\n",banyak_pengguna);
    int i;
    for(i = 0; i < banyak_pengguna; i++){
        writeFile(SELMT(dataNama,i),f2);
        writeFile(SELMT(password,i),f2);
        writeFile(SELMT(bio,i),f2);
        writeDinFile(phone.contents[i],f2);
        writeFile(SELMT(password,i),f2);
        readPrivatePublic(ELMT(JenisAkun,i),f2);
        writeMatrixChar(LSMELMT(profil,i),f2);
    }
    writeAdjMatrix(matPertemanan,f2);
    fprintf(f2,"%d\n",addFriendCounter);
    writePermintaanTeman(permintaanTeman,f2);
    fclose(f2);
    free(path);
}

void Simpan(){
    printf("Masukkan folder penyimpanan konfig: \n");

    STARTWORD();
    char *folder_path = WordToString(currentWord);
    printf("%s",folder_path);

    if (createDirectory(folder_path) == 0) {
        printf("\nFolder %s berhasil dibuat.\n", folder_path);
    } else {
        printf("\nFolder %s sudah tersedia.\n", folder_path);
    }

    savePengguna(folder_path);
    // saveKicauan(folder_path);
    // saveUtas(folder_path);
    // saveDraf(folder_path);
    // saveBalasan(folder_path);
    
 
 
 
    return;
}


char * WordToString(Word w){
    int i;
    char * c;
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
   fprintf(f,"\n");
}

void writeDinFile(WordDin w1, FILE *f){

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
        if(i == len){
            fprintf(f,"\n");+   
        }
    }
}