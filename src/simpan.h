#include <sys/types.h>
#include <sys/stat.h>
#include "./adt/wordmachine.h"

boolean isDirectoryExists(const char *path);

int createDirectory(char *path);

void saveBalasan(char *folder_path);

void saveDraf(char *folder_path);

void saveUtas(char *folder_path);

void saveKicauan(char *folder_path);

void savePengguna(char *folder_path);

void Simpan();