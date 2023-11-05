#include <stdio.h>
#include "matrixchar.h"
#include "charmachine.h"
#include "wordmachine.h"
#include "pcolor.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrixProfileDefault(MatrixChar *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
   MCROW_EFF(*m) = 5;
   MCCOL_EFF(*m) = 10;

   for (int i = 0; i <= 4; i++)
   {
      for (int j = 0; j <= 9; j++)
      {
         if (j % 2 == 0 || j == 0)
         {
            MCELMT(*m, i, j) = 'R';
         }
         else
         {
            MCELMT(*m, i, j) = '*';
         }
      }
   }
}

IsianMChar getElmtMChar(MatrixChar m, int row, int col)
/* Mengirimkan elemen m(i,j) */
{
    return (MCELMT(m, row, col));
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrixProfil(MatrixChar *m)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            MCELMT(*m, i, j) = ' ';
        }
    }

    int i, j = 0, temp = 0;
    while (!isfullMatrixChar(*m))
    {
        i = 0;
        temp = 0;
        START();
        IgnoreBlanks();
        while (temp != 19)
        {
            currentWord.TabWord[temp] = currentChar;
            ADV();
            temp++;
        }

        for(temp = 0; temp <= 19; temp++)
        {
            if (currentWord.TabWord[temp] != ' ')
            {
                MCELMT(*m, j, i) = currentWord.TabWord[temp];
                i++;
            }
        }

        j++;
    }
}

void displayMatrixCharColoured(MatrixChar m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 9; j+=2)
        {
            if (MCELMT(m, i, j) == 'R')
            {
                print_red(MCELMT(m, i, j+1));
            }
            else if (MCELMT(m, i, j) == 'G')
            {
                print_green(MCELMT(m, i, j+1));
            }
            else if (MCELMT(m, i, j) == 'B')
            {
                print_blue(MCELMT(m, i, j+1));
            }
        }
        printf("\n");
    }
}

void displayMatrixChar(MatrixChar m)
{
    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            printf("%c", MCELMT(m, i, j));
        }
        printf("\n");
    }
}

boolean isfullMatrixChar(MatrixChar m)
{
    int total = 0;

    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (MCELMT(m, i, j) != ' ')
            {
                total++;
            }
        }
    }

    return (total == 50);
}