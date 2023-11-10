#ifndef USER_H
#define USER_H

#include "ADT/wordmachine.h"

#define MAX_USERS 20
#define MAX_NAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_BIO_LENGTH 135
#define MAX_PHONE_LENGTH 20

// Warna profil
#define RED 'R'
#define GREEN 'G'
#define BLUE 'B'

// Weton
#define PAHING "Pahing"
#define KLIWON "Kliwon"
#define WAGE "Wage"
#define PON "Pon"
#define LEGI "Legi"

typedef struct {
    Word name;
    Word password;
    Word bio;
    Word phone;
    Word weton;
    Word isPrivate;
    char profilePicture[5][5];
} User;

typedef struct {
    int** adjacencyMatrix;
    int numUsers;
} FriendshipStatus;

// Makro akses elemen dalam struktur User
#define Name(U) (U).name
#define Password(U) (U).password
#define Bio(U) (U).bio
#define Phone(U) (U).phone
#define Weton(U) (U).weton
#define IsPrivate(U) (U).isPrivate
#define Profile(U, x, y) (U).profilePicture[(x)][(y)]

// Makro akses elemen dalam struktur FriendshipStatus
#define AdjacencyMatrix(FS) (FS).adjacencyMatrix
#define NumUsers(FS) (FS).numUsers

#endif