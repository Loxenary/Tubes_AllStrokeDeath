/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "boolean.h"
#include "charmachine.h"

#define NMax 280
#define BLANK ' '
#define ENTER '\n'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

typedef Word WrdType;
/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void STARTFILEWORD(char* dir);

void IgnoreLines();

void IgnoreEnters();

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreEnters();
/* Mengabaikan satu atau beberapa ENTER
   I.S. : currentChar sembarang
   F.S. : currentChar != BLANK */

void ADVWORD();

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */




/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyLine();

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void printWord(Word word);
/* Menampilkan ke layar suatu Word*/

boolean isWordEqual(Word w1, Word w2);
/*Melakukan Check apakah dua Word memiliki isi yang sama*/

boolean isWordEqualString(Word w1, char * s1);

Word MultipleInput();
/*Mengakuisisi kata hingga ditemukan MARK tanpa skip apapun kecuali blank di awal*/

void CopyWordWithSpace();
/*Mengakuisisi kata tanpa menskip spasi*/

//Membaca sejumlah x line

int toInt(Word nums);
/*from Word to integer*/

Word StringToWord(char* string, int size);

void ADVLINE();

// concat word
Word ConcatWord(Word w1, Word w2);

#endif