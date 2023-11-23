#include "kicau.h"
#include "./adt/wordmachine.h"
#include "./adt/datetime.h"
#include "./ADT/listStatikWordDin.h"

typedef enum {
    Public,
    Private
} AccountType;

void displayScreen();

int isNum(char c);

void readLine();

void ReadUserData(const char * filename);

void ReadKicauData(char* filename);

void ReadBalasanData(char * filename);

void ReadDrafData(const char * filename);

void ReadUtasData(const char * filename);

int read_id_balasan();

void loadconfig(char * folder, char * filename);

void readLineDin();

