#ifndef UTAS_H
#define UTAS_H

#include <stdio.h>
#include <stdlib.h>

#include "Database.h"
#include "Kicau.h"
#include "ListUtas.h"
#include "listDinUtasan.h"

void CreateRootUtas(int idKicau);

void DeleteUtas(int idUtas, int indexUtas);

void SambungUtas(int idUtas, int indexUtas);

void CetakUtas(Utas* u);

#endif