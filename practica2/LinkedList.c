#include "LinkedList.h"

NodeList* createNode(Lenguaje lenguaje)
{
    NodeList* newNode = (NodeList*)malloc(sizeof(NodeList));
    newNode->next = newNode->back = NULL;
    newNode->lenguaje = lenguaje;
    return newNode;
}

void insertNodeList(LinkedList* list, Lenguaje lenguaje)
{
    NodeList* temp = createNode(lenguaje);
    if(list->front == NULL)
    {
        list->front = list->back = temp;
        temp->id = 0;
    }
    else 
    {
        list->back->next = temp;
        temp->back = list->back;
        temp->id = list->back->id + 1;
        list->back = temp;
    }
    return;
}

NodeList* searchNodeList(LinkedList* list, int id)
{
    NodeList* temp = list->front;
    while(temp != NULL && temp->id != id)
        temp = temp->next;
    return temp;
}
