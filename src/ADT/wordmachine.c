#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;


void IgnoreBlanks(){ // This is to Ignore the current Char when its a blank
    while(currentChar == BLANK){
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
    while(currentChar != MARK && currentChar != BLANK){
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