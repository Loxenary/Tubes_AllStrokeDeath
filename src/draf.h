#ifndef DRAF_H
#define DRAF_H

typedef struct {
    int id;
    char text[200];
    char author[50];
    char datetime[20];
} Draf;

void loadDraf(char *filename);

#endif