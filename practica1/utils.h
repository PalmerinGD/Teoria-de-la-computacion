#include <stdio.h>
#include <stdlib.h>
#ifndef __MERGESORT_H__
#include "mergeSort.h"
#endif

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

void invertirCadenaUtil(char string[]);
void inversion();

char* potenciaUtil(char string[], int n);
void potencia();
