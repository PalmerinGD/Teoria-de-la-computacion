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
#include "linkedlist.h"

/* === DEFINICION DE LA ESTRUCTURA GRAFO === */
typedef struct Graph
{

    int v; // Numero de vertices
    linkedList* array;

} graph;

/* === DEFINICION DE FUNCIONES === */
graph* createGraph(int v); // Crea un grafo con v vertices
void addEdge(graph* g, int src, int dest, char edge); // Agrega una arista entre el vertice source y el destino.