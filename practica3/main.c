#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "graph.h"


void dfs(graph* g, char* cad, int n, int ind, int * stack, int pos);

int main(int argc, char* argv[])
{

    /* === Creacion del automata === */
    graph* g = createGraph(5);

    addEdge(g, 0, 0, 'a');
    addEdge(g, 0, 0, 'b');
    addEdge(g, 0, 3, 'a');
    addEdge(g, 0, 1, 'b');
    addEdge(g, 3, 4, 'b');
    addEdge(g, 1, 2, 'b');
    addEdge(g, 2, 2, 'a');
    addEdge(g, 2, 2, 'b');
    addEdge(g, 4, 4, 'a');
    addEdge(g, 4, 4, 'b');

    char str[100];

    printf("Cadena: ");
    scanf("%[^\n]", str);

    int pos = 0;
    int stack[1000];
    dfs(g, str, 0, 0, stack, pos);
    return 0;
}

void dfs(graph* g, char* cad, int n, int ind, int * stack, int pos)
{
    // Agrega el numero de estado al stack
    stack[pos] = n;

    // Si la cadena ya esta vacia y se encuentra en algun estado final imprime el stack
    if(cad[ind] == '\0' && (n == 2 || n == 3 || n == 4))
    {
        for (int j = 0; j <= pos; j++)
        {
            if (j == pos)
                printf("q%d\n", stack[j]);
            else
                printf("q%d ---> ", stack[j]);
        }
    }

    node *temp = g->array[n].front;
    while (temp != NULL)
    {
        if (temp->edge == cad[ind])
            dfs(g, cad, temp->n, ind + 1, stack, pos + 1);
        temp = temp->next;
    }
    return;
}
