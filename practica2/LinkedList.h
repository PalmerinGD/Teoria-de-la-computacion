#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Lenguaje.h"
#include <stdlib.h>
typedef struct NodeList
{
    int id;
    Lenguaje lenguaje;
    struct NodeList* next;
    struct NodeList* back;
} NodeList;

typedef struct LinkedList
{
    NodeList* front;
    NodeList* back;
} LinkedList;

NodeList* createNode(Lenguaje lenguaje);
void insertNodeList(LinkedList* list, Lenguaje lenguaje);
NodeList* searchNodeList(LinkedList* list, int id);
#endif
