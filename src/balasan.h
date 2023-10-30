#ifndef BALASAN_H
#define BALASAN_H

typedef struct {
    int id_parent;
    int id_balasan;
    char text[200];
    char author[50];
    char datetime[20];
} Balasan;

void loadBalasan(char *filename);

#endif