/*
LIBRERIA: Cabecera de la estructura de datos LINKED LIST
AUTOR: Diego Palmerin
VERSION: 1.0.0

DESCRIPCION:

OBSERVACIONES:
*/
/* === LIBRERIAS === */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "linkedlist.h"


/* === DEFINICION DE FUNCIONES === */

/*
node* createNode(int n, char edge)
DESCRIPCION: Se crea un nodo en la memoria dinamica.
RECIBE: int n(Numero de estado), char edge(Transicion).
DEVUELVE: node*(Referencia al nuevo nodo).
OBSERVACIONES: Se inicializa el siguiente nodo como NULL.
*/
node* createNode(int n, char edge)
{

    node* temp = ( node* ) malloc( sizeof(node) );
    if(temp == NULL)
    {
        printf("Error memory allocation: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    temp->n = n;
    temp->edge = edge;
    temp->next = NULL;
    return temp;

}
