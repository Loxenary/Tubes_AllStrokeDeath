#ifndef LOAD_DRAF_H
#define LOAD_DRAF_H

#include "./adt/wordmachine.h"
#include "./adt/datetime.h"

#define MAX_USERS 20
#define MAX_DRAF 20
#define MAX_TEXT_LENGTH 10000
#define MAX_DATETIME_LENGTH 20

typedef struct {
    Word username;
    int banyak_draf;
    struct {
        Word text;
        DATETIME datetime;
    } draf[MAX_DRAF];
} UserDraf;

typedef struct {
    int banyak_pengguna;
    UserDraf users[MAX_USERS];
} ListDraf;

// void ReadDrafData(const char *filename, ListDraf *listDraf);

#endif // LOADDRAF_H