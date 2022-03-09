#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void printMenu();
int readOption();

int length(char string[]);

char* concatenacionUtil(char string1[], char string2[]);
void concatenacion();

char* prefijoUtil(char string[], int n);
void prefijo();

char* sufijoUtil(char string[], int n);
void sufijo();

char* subcadenaUtil(char string[], int left, int right);
void subcadena();

char* subsecuenciaUtil(char string[], int indices[], int n);
void subsecuencia();

char* invertirCadenaUtil(char string[]);
void inversion();

char* potenciaUtil(char string[], int n);
void potencia();
#endif