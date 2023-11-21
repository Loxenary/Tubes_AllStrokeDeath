#ifndef UTAS_H
#define UTAS_H

#include <stdio.h>
#include <stdlib.h>

#include "adt/boolean.h"
#include "kicau.h"
#include "listUtas.h"
#include "ListDinUtasan.h"

void CreateRootUtas(int idKicau);

void DeleteUtas(int idUtas, int indexUtas);

void SambungUtas(int idUtas, int indexUtas);

void CetakUtas(ListUtas u);

boolean isId(int index);

boolean isUtasID(int idx);

kicauan getKicau(int index);



#endif