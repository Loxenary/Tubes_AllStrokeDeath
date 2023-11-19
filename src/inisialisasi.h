#include "kicau.h"
#include "loaduser.h"
#include "loadbalasan.h"
#include "loaddraf.h"
#include "loadutas.h"
#include "./adt/wordmachine.h"
#include "./adt/datetime.h"

void displayScreen();

void readLine();

void ReadUserData(const char * filename, UserData *userData);

void ReadKicauData(char* filename, kicauan* kicau);

void ReadBalasanData(char * filename, Balasan * balasan);

void ReadDrafData(const char * filename, ListDraf * listDraf);

void ReadUtasData(const char * filename, DataUtas * dataUtas);

void loadconfig(char * folder, char * filename);

