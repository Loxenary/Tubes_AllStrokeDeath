/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
Modified at: 23/10/2023
**/

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define BLUE "\x1B[34m"
#define LIGHT_BLUE "\x1B[94m"
#define PINK "\x1B[50;5;91m"

void print_red(char c);
void print_green(char c);
void print_blue(char c);
void print_light_blue(char c);
void print_pink(char c);