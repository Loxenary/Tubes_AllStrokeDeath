#include "liststatikstack.h"

void CreateListStatikstack(ListStatikStack *l){

}
/*membuat list statik berisi stack yang kosong*/

Stack ambilDraf(ListStatikStack l, int idx){
    return l.contents[0];
}
/*mereturn stack berisi draf milik akun pada index ke-idx pada list datanama*/

Stack ambilWaktuDraf(ListStatikStack l, int idx){
    return l.contents[idx];
}
/*mereturn stack berisi waktu terakhir draf diedit milik akun pada index ke-idx pada list datanama*/

void overwriteDraf(ListStatikStack *l, int idx, Stack s, Stack stime){
    
}
/*meng-overwrite data draf pada liststatikstack dengan stack yang sudah diedit pada fungsi draf*/

