#ifndef LOAD_USER_H
#define LOAD_USER_H

#define MAX_USERS 20
#define MAX_REQUESTS 20
#define MAX_NAME_LENGTH 50
#define MAX_BIO_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_WETON_LENGTH 10

#include "./adt/wordmachine.h"

typedef enum {
    Privat,
    Publik
} AccountType;

typedef char Profil[5][5];

typedef struct {
    int banyak_pengguna;
    Word dataNama[MAX_USERS];
    Word password[MAX_USERS];
    Word bio[MAX_USERS];
    Word phone[MAX_USERS];
    Word Weton[MAX_USERS];
    AccountType JenisAkun[MAX_USERS];
    Profil profil[MAX_USERS];
    //matriks adjacency pertemanan
    int adjacencyMatrix[MAX_USERS][MAX_USERS];
    // banyak request pertemanan
    int banyak_request;
    // array request pertemanan
} UserData;
typedef struct FriendshipReques{
    int senderID;
    int receiverID;
    int status;
} FriendshipRequest;



// void ReadUserData(const char *filename, UserData *userData);

#endif // USER_H