#include "./adt/prioqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "teman.h"  // Assuming this includes necessary structures and functions
#include "database.h"  // Assuming this includes necessary structures and functions

boolean isFriendRequestExist(PrioQueue friendRequests, Word sender, Word receiver);
void removeFriendRequest(PrioQueue* friendRequests, Word sender, Word receiver);
void sendFriendRequest(PrioQueue* friendRequests, Word sender, Word receiver);
boolean hasPendingFriendRequests(PrioQueue friendRequests, Word user);
void displayPendingFriendRequests(PrioQueue friendRequests);
void processFriendRequest(PrioQueue* friendRequests, Word currentUser);