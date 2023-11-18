/* File: wordmachine.c */
/* Implementasi Word Machine: Model Akuisisi Versi III */

#include <stdio.h>
#include "wordmachine.h"


/* State Mesin Word */

Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK,currentChar = MARK, atau currentChar = ENTER */
{
    while ((currentChar == BLANK) || (currentChar == ENTER))
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

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : retval = EOF dan mesin berhenti;
          atau retval != EOF, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah kata terakhir kata */
{
    START();
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
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, retval mungkin EOF
          Jika retval = EOF, mesin berhenti.
   Proses : Akuisisi kata menggunakan procedure CopyWord */
{

    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = TRUE;
    }
    else
    {

        CopyWord();
        IgnoreBlanks();
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

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = ENTER, currentChar = BLANK, atau retval = EOF;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
   int i = 0;
   while ((currentChar != ENTER) && (currentChar != BLANK) && (retval != EOF))
   {
      if (i == NMax)
         break;
      currentWord.TabWord[i] = currentChar;
      ADV();
      i++;
   }
   currentWord.Length = i;
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



void PrintWord()
/* I.S. : currentWord terdefinisi
   F.S. : currentWord tercetak pada layar */
{
   int i;
   for (i = 0; i < currentWord.Length; i++)
      printf("%c", currentWord.TabWord[i]);
   printf("\n");
}

boolean IsWordEqual(Word w1, Word w2)
/* Mengecek apakah w1 sama dengan w2 */
{
   if (w1.Length != w2.Length)
      return FALSE;

   int i = 0;
   while (i < w1.Length)
   {
      if (w1.TabWord[i] != w2.TabWord[i])
         return FALSE;
      i++;
   }

   return TRUE;
}

boolean isInt(Word w)
{
   boolean found = TRUE;
   for (int i = 0; i < w.Length; i++)
   {
      if (w.TabWord[i] < 48 || w.TabWord[i] > 57)
      {
         found = FALSE;
      }
   }
   return found;
}

int WordToInt(Word w)
{
    int i, result = 0;
    for (i = 0; i < w.Length; i++)
    {
        if (w.TabWord[i] >= '0' && w.TabWord[i] <= '9')
            result = result * 10 + (w.TabWord[i] - '0');
    }
    if (w.TabWord[0] == '-') // Jika negatif
        result = result * -1;
    return result;

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

DATETIME WordToDateTime(Word w) {
    DATETIME result;
    int day, month, year, hour, minute, second;
    
    sscanf(w.TabWord, "%d/%d/%d %d:%d:%d", &day, &month, &year, &hour, &minute, &second);

    CreateDATETIME(&result, day, month, year, hour, minute, second);

    return result;
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