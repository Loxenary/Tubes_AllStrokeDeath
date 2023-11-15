#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;


void IgnoreBlanks(){ // This is to Ignore the current Char when its a blank
    while(currentChar == BLANK || currentChar == '\n'){
        ADV();
    }
}

void STARTWORD(){ // Initialize the word
    START(); // Start the file
    IgnoreBlanks(); //Ignore if the current char is blank
    if(currentChar == MARK){ 
        EndWord = 1;
    }else{
        EndWord = 0;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = 1;
    }
    else{
        CopyWord();
        IgnoreBlanks();
    }
}
void CopyWord(){
    int i = 0;
    while(currentChar != MARK && currentChar != BLANK && currentChar != '\n'){
        if(currentChar != '\n'){
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    if(i > NMax){
        currentWord.Length = NMax;
    }
    else{
        currentWord.Length = i;
    }
}
void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

boolean isWordEqual(Word w1, Word w2){
    int i;
    if(w1.Length != w2.Length){
        return FALSE;
    }
    else{
        for (i = 0; i < w1.Length; i++)
        {
            if(w1.TabWord[i] != w2.TabWord[i]){
                return FALSE;
            }
        }
        return TRUE;
        
    }
}

boolean isWordEqualString(Word w1, char * s1){
   int i;
   for(i = 0; i < w1.Length; i++){
      if(w1.TabWord[i] != s1[i]){
         return FALSE;
      }
   }
   return TRUE;
}

// Word CombineWord(Word w1, Word w2){
//     Word temp;
//     if(w1.Length == 0){
//         return w2;
//     }
//     else if(w2.Length == 0){
//         return w1;
//     }
//     else{
//         int i;
//         for(i = 0; i < w1.Length; i++){
//             temp.Length = w1.Length;
//             temp.TabWord[i] = w1.TabWord[i];
//         }
//         temp.TabWord[temp.Length] = ' ';
//         temp.Length++;
//         int k = temp.Length;
//         for(i = 0; i < w2.Length; i++){
//             temp.Length = temp.Length + w2.Length;
//             temp.TabWord[i+k] = w2.TabWord[i];
//         }
//     }
//     return temp;
// }

Word MultipleInput() {
    Word temp;
    int i = 0;
    START();
    IgnoreBlanks();

    while (currentChar != MARK && currentChar != ';' && !EOP) {
        // Stop when reaching MARK, ;, or end of input
        if (currentChar != MARK) {
            temp.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }

    if (i > NMax) {
        temp.Length = NMax;
    } else {
        temp.Length = i;
    }
    return temp;
}

int toInt(Word nums){
    // asumsi bahwa isi nums adalah angka semua dalam bentuk char
    // kamus
    int  temp = 0;
    // algoritma
    for(int i = 0; i < nums.Length; i++){
        temp *= 10;
        temp += nums.TabWord[i] - 48;
    }
    return temp;

}