#include "database.h"
#include "simpan.h"
#include <string.h>


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
    char *temp = (char *) malloc (stringLength(path) + 1);
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

void saveBalasan(char *folder_path){
    char *path = (char *) malloc (stringLength(folder_path) + 20);
    strcpy(path, folder_path);
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

    char *path = (char *) malloc (stringLength(folder_path) + 20);
    strcpy(path, folder_path);
    strcat(path, "/pengguna.config");

    FILE *f2 = fopen(path, "w");
    if (f2 == NULL) {
        printf("Error: %s tidak dapat dibuat.\n", path);
        return;
    }


    fclose(f2);
    free(path);
}

void Simpan(){
    printf("Masukkan folder penyimpanan konfig: \n");

    STARTWORD();
    char *folder_path = currentWord.TabWord;

    if (createDirectory(folder_path) == 0) {
        printf("\nFolder %s berhasil dibuat.\n", folder_path);
    } else {
        printf("\nFolder %s sudah tersedia.\n", folder_path);
    }

    savePengguna(folder_path);
    saveKicauan(folder_path);
    saveUtas(folder_path);
    saveDraf(folder_path);
    saveBalasan(folder_path);
    
 
 
 
    return;
}