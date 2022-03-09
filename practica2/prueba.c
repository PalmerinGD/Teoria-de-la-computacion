#include <stdio.h>
#ifndef UTILS_H
#include "utils.h"
#endif
#ifndef LINKEDLIST_H
#include "LinkedList.h"
#endif
#include "LenguajeOperaciones.h"

void definirLenguaje(LinkedList* lenguajes);
void optionInterseccion(LinkedList* lenguaje);
void optionUnion(LinkedList* lenguaje);
void optionPotencia(LinkedList* lenguaje);
int main()
{
    LinkedList lenguajes;
    while(true)
    {
        printMenu();
        switch (readOption())
        {
        case 1:
            definirLenguaje(&lenguajes);
            break;
        case 2:
            optionInterseccion(&lenguajes);
            break;
        case 3:
            optionUnion(&lenguajes);
            break;
        case 4:
            optionPotencia(&lenguajes);
            break;
        default:
            return 0;
        }
    }
}

void definirLenguaje(LinkedList* lenguajes)
{
    int total;
    printf("Cuantas elementos: ");
    scanf("%d", &total);
    Lenguaje l;
    l.cadenas = NULL;
    for(int i=0; i<total; i++)
    {
        Data d;
        scanf("%s", d.palabra);
        l.cadenas = insert(l.cadenas, d);
    }
    insertNodeList(lenguajes, l);
    printf("Id del lenguaje: %d\n", lenguajes->back->id);
}

void optionInterseccion(LinkedList* lenguaje)
{
    int id1, id2;
    printf("Inserte dos ids: ");
    scanf("%d %d", &id1, &id2);
    NodeList* temp, *temp2;
    temp = lenguaje->front;
    temp2 = lenguaje->front;
    while(temp != NULL && temp->id != id1) temp = temp->next;
    while(temp2 != NULL && temp2->id != id2) temp2 = temp2->next;
    if(temp == NULL || temp2 == NULL) 
    {
        printf("No existe tal lenguaje");
        return;
    }
    Lenguaje l;
    l = interseccionLenguajes(temp->lenguaje, temp2->lenguaje);
    Inorder(l.cadenas);
    printf("\n");
}

void optionUnion(LinkedList* lenguaje)
{
    int id1, id2;
    printf("Inserte dos ids: ");
    scanf("%d %d", &id1, &id2);
    NodeList* temp, *temp2;
    temp = lenguaje->front;
    temp2 = lenguaje->front;
    while(temp != NULL && temp->id != id1) temp = temp->next;
    while(temp2 != NULL && temp2->id != id2) temp2 = temp2->next;
    if(temp == NULL || temp2 == NULL) 
    {
        printf("No existe tal lenguaje");
        return;
    }
    Lenguaje l;
    l = unionLenguajes(temp->lenguaje, temp2->lenguaje);
    Inorder(l.cadenas);
    printf("\n");
}

void optionPotencia(LinkedList* lenguaje)
{
    int id;
    printf("Inserte el id del lenguaje: ");
    scanf("%d", &id);
    NodeList* temp = lenguaje->front;
    while(temp!=NULL && temp->id != id)temp = temp->next;
    if(temp == NULL)
    {
        printf("No existe tal lenguaje\n");
        return;
    }
    int n;
    printf("Inserte la potencia: ");
    scanf("%d", &n);
    Lenguaje l;
    l = potenciaLenguaje(temp->lenguaje, n);
    Inorder(l.cadenas);
    printf("\n");
}