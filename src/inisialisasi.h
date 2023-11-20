#include "kicau.h"
#include "./adt/wordmachine.h"
#include "./adt/datetime.h"

typedef enum {
    Privat,
    Publik
} AccountType;

void displayScreen();

int isNum(char c);

void readLine();

void readDrafHead(Word *Auth, int * amount);

void ReadUserData(const char * filename);

void ReadKicauData(char* filename);

void ReadBalasanData(char * filename);

void ReadDrafData(const char * filename);

void ReadUtasData(const char * filename);

void loadconfig(char * folder, char * filename);

