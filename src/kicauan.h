#ifndef KICAUAN_H
#define KICAUAN_H

typedef struct {
    int id;
    char text[200];
    int like;
    char author[50];
    char datetime[20];
} Kicauan;

void loadKicauan(char *filename);

#endif