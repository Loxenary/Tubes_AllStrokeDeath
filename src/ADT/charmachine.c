/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;


void STARTFILE(char* dir)
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : dir terdefinisi, yaitu direktori file yang ingin dibaca.
   F.S. : currentChar adalah karakter pertama pada pita
   		 Jika retval != EOF maka mesin akan tetap berjalan
   		 Jika retval = EOF maka mesin akan berhenti
		    Jika file tidak bisa dibaca maka mesin akan berhenti dan file akan ditutup */
{
	pita = fopen(dir, "r");
	if (pita == NULL)
	{
		printf("Pita tidak bisa dibaca.");
		fclose(pita);
	}
	else
	{
		ADV();
	}
}
void START()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pita = stdin;
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       EOP = feof(pita);
       retval = fscanf(pita, "%c", &currentChar);
       // if(!EOP){
       // }
}
