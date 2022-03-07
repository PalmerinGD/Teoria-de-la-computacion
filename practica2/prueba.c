#include <stdio.h>
#ifndef UTILS_H
#include "utils.h"
#endif
#ifndef LINKEDLIST_H
#include "LinkedList.h"
#endif
#include "LenguajeOperaciones.h"

int main()
{
    LinkedList lenguajes;
    for(int j=0; j<5; j++)
    {
        Lenguaje l;
        l.cadenas = NULL;
        for(int i=0; i<2; i++)
        {
            Data d;
            scanf("%s", d.palabra);
            l.cadenas = insert(l.cadenas, d);
        }
        insertNodeList(&lenguajes, l);
    }
    Lenguaje temp = unionLenguajes(lenguajes.front->lenguaje, lenguajes.front->next->lenguaje);
    Inorder(temp.cadenas);
    printf("\n");
}
