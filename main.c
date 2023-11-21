#include <stdio.h>
#include "./src/perintah.h"
#include "./src/inisialisasi.h"
#include "./src/permintaanpertemanan.h"

int main(){
       // displayScreen();
       // inisialisasiAplikasi();
       char folder[250];
       char filename[250];
       loadconfig(folder, filename);
       SwprintList(dataNama);
       SwprintList(password);
       SwprintList(bio);
       SwprintList(Weton);
       SprintList(JenisAkun);
       printf("\n");

       // PrioQueue friendRequests;
       // PrioQueueInitialize(&friendRequests, 100);

       // // Example usage
       // sendFriendRequest(&friendRequests, StringToWord("Alice", 5), StringToWord("Bob", 3));
       // sendFriendRequest(&friendRequests, StringToWord("Alice", 5), StringToWord("Carol", 5));

       // if (!IsPrioQueueEmpty(friendRequests)) {
       //        displayPendingFriendRequests(friendRequests);
       // }

       // // Process friend requests
       // if (!IsPrioQueueEmpty(friendRequests)) {
       //        processFriendRequest(&friendRequests, StringToWord("Alice", 5));
       // }

       // // Don't forget to destroy the priority queue
       // PrioQueueDestroy(&friendRequests);
       //        return 0;

       perintah();
}
