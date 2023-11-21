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

void ADVLINE() {
    IgnoreBlanks();
    if (currentChar == ENTER) {
        EndWord = TRUE;
    } else {
        CopyLine();
    }
}

void STARTFILEWORD(char* dir)  // tadi diubah
/* I.S. : currentChar sembarang
   F.S. : retval = EOF dan mesin berhenti;
          atau retval != EOF, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah kata terakhir kata */
{
    STARTFILE(dir);
    IgnoreBlanks();
    EndWord = FALSE;
    if (currentChar == MARK)
    {
        EndWord = TRUE;
    }
    else
    {
        EndWord = FALSE;
        CopyWord();
    }
}

void ADVWORD()
{
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
    while ((currentChar != ENTER) && (currentChar != BLANK) && (currentChar != MARK))
    {
       currentWord.TabWord[i] = currentChar;
       ADV();
       i++;
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

void CopyLine() {
      int i = 0;
      while ((currentChar != ENTER) && (retval != EOF)) {
         if (i == NMax)
               break;
         currentWord.TabWord[i] = currentChar;
         ADV();
         i++;
      }
      currentWord.Length = i;

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

Word MultipleInput() {
    Word temp;
    int i = 0;
    START();
    IgnoreBlanks();

    while (currentChar != MARK && currentChar != ';' ) {
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

void CopyWordWithSpace() 
{
    int i = 0;
    while(currentChar != MARK){
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


int toInt(Word nums){
    int i, result = 0;
    if(nums.TabWord[0] == '0' && nums.Length == 1){
        return 0;
    }
    for (i = 0; i < nums.Length; i++)
    {
        if (nums.TabWord[i] >= '0' && nums.TabWord[i] <= '9')
            result = result * 10 + (nums.TabWord[i] - '0');
    }
    if (nums.TabWord[0] == '-') // Jika negatif
        result = result * -1;
    return result;
}

void IgnoreLines(){
    while (currentChar == '\n')
    {
        ADV();
    }
}

void IgnoreEnters()
/* Mengabaikan satu atau beberapa ENTER
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ ENTER, currentChar = MARK, atau currentChar = BLANK */
{
    while (currentChar == ENTER)
    {
        ADV();
    }
}


Word StringToWord(char* string, int size)
/*  Mengubah array of char (string) menjadi word */
{
   Word w;
   w.Length = size;

   for (int i = 0; i < size; i++)
      w.TabWord[i] = string[i];

   return w;
}

// concat word
Word ConcatWord(Word w1, Word w2) {
    Word result;
    result.Length = w1.Length + w2.Length;
    int i;
    for (i = 0; i < w1.Length; i++) {
        result.TabWord[i] = w1.TabWord[i];
    }
    for (i = 0; i < w2.Length; i++) {
        result.TabWord[i + w1.Length] = w2.TabWord[i];
    }
    return result;
}

// concat word
Word ConcatWord(Word w1, Word w2);
