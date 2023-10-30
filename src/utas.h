#ifndef UTAS_H
#define UTAS_H

typedef struct {
    char text[200];
    char author[50];
    char datetime[20];
} Utas;

void loadUtas(char *filename);

#endif