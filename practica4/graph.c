/*
LIBRERIA: Cabecera de la estructura de datos GRAFO
AUTOR: Diego Palmerin
VERSION: 1.0.0

DESCRIPCION:
La estructura se basa en una lista de adyecencia para construir el grafo.

OBSERVACIONES:
Se necesita llamar a la funcion createGraph cada vez que se desee crear un grafo,
para ello se necesita conocer de antemano la cantidad total de vertices que el 
grafo tendra, ya que se almacena en memoria dinamica. Al acabar de usar la estructura,
llamar a la funcion de deleteGraph, para liberar espacio.
*/

/* === LIBRERIAS === */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "graph.h"

/* === DEFINICION DE FUNCIONES === */

/*
graph* createGraph(int v)
DESCRIPCION: Crea un grafo con v vertices, lo aloja en memoria dinamica y regresa su referencia.
RECIBE: int v(Cantidad de vertices).
DEVUELVE: graph*(Referencia al grafo).
OBSERVACIONES: El grafo se basa en una lista de adyecencia.
*/
graph* createGraph(int v)
{

    graph* g = ( graph* ) malloc( sizeof(graph) );
    if(g == NULL)
    {
        printf("Error memory allocation: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    g->v = v;
    g->array = (linkedList*) malloc( v * sizeof(linkedList) );
    if(g->array == NULL)
    {
        printf("Error memory allocation: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<v; i++)
        g->array[i].front = g->array[i].back = NULL;

    return g;

}

/*
void addEdge(graph* g, int src, int dest, char edge)
DESCRIPCION: Agrega una arista entre los vertices source y destiny.
RECIBE: graph* g(Referencia al grafo), int src(Numero del vertice de donde sale la arista),
int dest(Numero de vertice destino), char edge(Transicion).
DEVUELVE: void.
OBSERVACIONES: El grafo se creo previamente, y si el numero de vertice de source o destiny sobrepasa
la cantidad total de vertices no agregara el vertice.
*/
void addEdge(graph* g, int src, int dest, char edge)
{
    if(src >= g->v || dest >= g->v) return;
    if(g->array[src].front == NULL) 
    {
        g->array[src].front = g->array[src].back = createNode(dest, edge);
    }
    else 
    {
        g->array[src].back->next = createNode(dest, edge);
        g->array[src].back = g->array[src].back->next;
    }
}
