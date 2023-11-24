#ifndef PERMINTAANPERTEMANAN_H
#define PERMINTAANPERTEMANAN_H

#include "./adt/prioqueue.h"
#include "teman.h"
#include "database.h"

boolean isFriendRequestExist(PrioQueue friendRequests, Word sender, Word receiver);
void sendFriendRequest(PrioQueue* friendRequests, Word currentUser, int banyak_pengguna);
boolean hasPendingFriendRequests(PrioQueue friendRequests, Word user);
void displayPendingFriendRequests(PrioQueue friendRequests, Word currentUser);

#endif
