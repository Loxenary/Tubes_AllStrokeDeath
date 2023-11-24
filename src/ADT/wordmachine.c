#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;
WordDin currentWordDin;

void initialWordDin(WordDin * w, int capacity)
{
    w->container = (char *)malloc(capacity * sizeof(char));
    w->Length = 0;
    w->Capacity = capacity;
}

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
    IgnoreEnters();
    if (currentChar == ENTER) {
        EndWord = TRUE;
    } else {
        CopyLine();
    }
}


void ADVLINEDIN(){
    IgnoreBlanks();
    if (currentChar == ENTER) {
        EndWord = TRUE;
    } else {
        CopyLineDin();
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

void printWordDin(WordDin word) {
   for (int i = 0; i < word.Length; i++) {
      printf("%c", word.container[i]);
   }
}
// void printWordDin(WordDin word){
//     int i;
//     for (i = 0; i < word.Length; i++) {
//       printf("%c", word.container[i]);
//     }
//     i++;
// }

void CopyLine() {
      int i = 0;
      while ((currentChar != ENTER) && (retval != EOF)) {
         if (i == NMax){
               break;
         }
         currentWord.TabWord[i] = currentChar;
         ADV();
         i++;
      }
      currentWord.Length = i;

}


void CopyLineDin() {
    initialWordDin(&currentWordDin, 280);
    int counter = 1;
    int i = 0;
    while ((currentChar != ENTER) && (retval != EOF)) {
        currentWordDin.container[i] = currentChar;
        ADV();
        i++;

        if (i > 280 * counter) {
            // Initialize a temporary WordDin with a smaller capacity (280)
            WordDin tempWord;
            counter++;
            initialWordDin(&tempWord, 280 * counter);

            int j;
            for (j = 0; j < 280 * (counter - 1); j++) {
                tempWord.container[j] = currentWordDin.container[j];
            }

            // Update currentWordDin with the temporary WordDin
            currentWordDin = tempWord;
            free(tempWord.container);
        }
    }
    currentWordDin.Length = i;
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

boolean isWordDinEqual(WordDin w1, WordDin w2){
    int i;
    if(w1.Length != w2.Length){
        return FALSE;
    }
    else{
        for (i = 0; i < w1.Length; i++)
        {
            if(w1.container[i] != w2.container[i]){
                return FALSE;
            }
        }
        return TRUE;
    }
}

boolean isWordEqualString(Word w1, char * s1){
   int counter = 0;
   while (s1[counter] != '\0')
   {
        counter++;
   }
   
   if(w1.Length != counter){
        return FALSE;
   }
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

// void CreateWord(WordDin * word, int Capacity){
//     word->Capacity = Capacity;
//     word->Length = 0;
//     word = (char*) malloc ((Capacity+1) * sizeof(char));
// }

// void expandWord(WordDin *word, int Capacity_increase)
// {
//     int newCapacity = word->Capacity + Capacity_increase;
//     char *newTabWord = (char *)malloc((newCapacity + 1) * sizeof(char));  // +1 for the null terminator

//     if (newTabWord != NULL) {
//         // Copy existing content to the new block
//         for (int i = 0; i <= word->Length; i++) {
//             newTabWord[i] = word->container[i];
//         }

//         // Free the old block
//         free(word->container);

//         // Update fields in the WordDin structure
//         word->container = newTabWord;
//         word->Capacity = newCapacity;
//     }
// }

Word StringToWord(char* string, int size) {
    Word w;
    w.Length = size;

    for (int i = 0; i < size; i++) {
        if (i < NMax) {
            w.TabWord[i] = string[i];
        } else {
            break;
        }
    }

    // Null-terminate the TabWord array
    if (size < NMax) {
        w.TabWord[size] = '\0';
    } else {
        w.TabWord[NMax - 1] = '\0';
    }

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

void copyWordDin()
{
    if (currentWordDin.container == NULL)
    {
        currentWordDin.container = (char *)malloc(NMax * sizeof(char));
        currentWordDin.Length = 0;
        currentWordDin.Capacity = NMax;
    }
    // Mengosongkan currentWord
    currentWordDin.Length = 0;

    // Mengakuisisi kata sampai bertemu BLANK atau MARK
    while (currentChar != ';') {
        // Memastikan masih cukup kapasitas
        if (currentWordDin.Length < currentWordDin.Capacity - 1) {
            currentWordDin.container[currentWordDin.Length] = currentChar;
            currentWordDin.Length++;
        } else {
            currentWordDin.Capacity++;
            currentWordDin.container[currentWordDin.Length] = currentChar;
            currentWordDin.Length++;
        }
        ADV();
    }
}

