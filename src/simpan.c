#include "database.h"

#include "simpan.h"

int createFolder(char *folderName){
    struct stat st = {0};
    if(stat(folderName, &st) == 0){
        printf("Folder %s already esists.\n",folderName);
        return 1;
    }
    if(mkdir(folderName) == 0){
        printf("%s sudah berhasil dibuat.\n",folderName);
        return 0;
    }
    else{
        printf("Error Creating folder");
        return -1;
    }
}

int simpan(){
    printf("Masukkan nama folder penyimpanan\n");
    STARTWORD(); // Asumsi tidak ada spasi pada Path
    int result = createFolder(currentWord.TabWord);

    if(result == 0){
        printf("Anda akan melakukan penyimpanan di %s.\n",currentWord.TabWord);

        printf("Penyimpanan telah berhasil dilakukan!\n");
    }else if (result == 1) {
        // Folder already exists, you can handle this case differently if needed
        // For now, just print a message
        printf("Anda akan melakukan penyimpanan di %s.\n", currentWord.TabWord);
        // Perform your save operation here
        printf("Penyimpanan telah berhasil dilakukan!\n");
    } else {
        // Handle folder creation failure
        printf("Penyimpanan gagal dilakukan.\n");
    }
}

void writeWord(Word wrd, char *folderName){
    char balasanPath[100];
    char drafPath[100];
    char kicauanPath[100];
    char utasPath[100];
    char PenggunaPath[100];

    // Assuming folderName is the folder where you want to store these files
    sprintf(balasanPath, "%s/balasan.config", folderName);
    sprintf(drafPath, "%s/draf.config", folderName);
    sprintf(kicauanPath, "%s/kicauan.config", folderName);
    sprintf(utasPath, "%s/utas.config", folderName);
    sprintf(PenggunaPath, "%s/pengguna.config", folderName);

    // Now you can use these paths to write the contents based on current data
    // Example:
    FILE *balasanFile = fopen(balasanPath, "w");
    if (balasanFile != NULL) {
        fprintf(balasanFile, "Content based on current data: %s\n", wrd);
        fclose(balasanFile);
    }
    // Repeat the process for other files...
}

void writeConfigFile(char *folderName) {
    // Construct the file path
    char filePath[100];
    sprintf(filePath, "%s/config.txt", folderName);

    // Open the file in write mode
    FILE *configFile = fopen(filePath, "w");

    // Check if the file opened successfully
    if (configFile == NULL) {
        perror("Error opening config file");
        return;
    }

    // Write content to the file
    fprintf(configFile, "Folder: %s\n", folderName);

    // Close the file
    fclose(configFile);
}