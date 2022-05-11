/*
LIBRERIA: Cabecera de la estructura de datos LINKED LIST
AUTOR: Diego Palmerin
VERSION: 1.0.0

DESCRIPCION:

OBSERVACIONES:
*/

/* === DEFINICION DE LA ESTRUCTURA NODE === */
typedef struct node
{

    int n; // Numero de estado -> {q0, q1, q2, q3, ...}
    char edge; // {a,b}
    struct node * next; 

} node;

/* === DEFINICON DE LA ESTRUCTURA LINKEDLIST === */
typedef struct LinkedList
{

    node* front;
    node* back;

} linkedList;

/* === DEFINICION DE FUNCIONES === */
node* createNode(int n, char edge); //Crea un nodo y regresa su referencia.
