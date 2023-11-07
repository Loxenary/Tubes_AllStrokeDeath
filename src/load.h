#ifndef LOAD_H
#define LOAD_H

#include "user.h"
#include "kicau.h"

void displayScreen();
void inisialisasiAplikasi();
void LoadUser(User* users, int* numUsers, FriendshipStatus* friendshipStatus, char* filename);
void LoadKicau(ListKicau* kicauList, char* filename);
#endif