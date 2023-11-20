#ifndef UTAS_H
#define UTAS_H
#include "kicau.h"
#include "listUtas.h"

void CreateRootUtas(int idKicau);
void DeleteUtas(int idKicau, int indexUtas);
void SambungUtas(int idUtas, int indexUtas);
void CetakUtas();

boolean isId(int index);
kicauan getKicau(int index);
#endif