#include <stdlib.h>
#include <stdio.h>
#define BIGGER 1
#define LOWER 0
#define true 1
#define false 0

typedef struct Data
{
    int n;
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
