#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <stdlib.h>
#include <stdio.h>
#ifndef UTILS_H
#include "utils.h"
#endif
#define LOWER 0
#define BIGGER 1
#define EQUAL 2
#define true 1
#define false 0
#ifndef MAX
#define MAX 100
#endif

typedef struct Data
{
    char palabra[MAX];
} Data;

typedef struct Nodo
{
    Data data;
    struct Nodo* left;
    struct Nodo* right;
} Nodo;

int compare(Data data1, Data data2);
Nodo* createNodo(Data data);
Nodo* insert(Nodo* root, Data data);
Nodo* search(Nodo* root, Data data);
void Inorder(Nodo* root);
void copy(Nodo* r1, Nodo** base);
void copyInvert(Nodo* r1, Nodo** base);
void interseccion(Nodo* r1, Nodo* r2, Nodo** base);
void Multiplicar(Nodo* r1, Nodo* r2, Nodo** base);
void MultiplicarUtil(Nodo** base, Nodo* r1, Data d1);

#endif