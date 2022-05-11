#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "graph.h"

#define TOTAL_STATES 10
#define TOTAL_TRANSITIONS 10
#define MAX_LEN 10

int dfs(graph* g, char* cad, int n, int ind, int * stack, int pos, int * finalStates, int tamFinal);

int main(int argc, char* argv[]) {

    if(argc != 2) {

        printf("Error: Ingrese el nombre del archivo del automata\n");
        return 0;

    }

    FILE* fptr = fopen(argv[1], "r");

    char num[MAX_LEN];
    memset(num, '\0', MAX_LEN * sizeof(char));

    int index = 0;

    int states[TOTAL_STATES];
    memset(states, 0, TOTAL_STATES * sizeof(int));
    int indStates = 0;

    int transitions[TOTAL_TRANSITIONS];
    memset(transitions, 0, TOTAL_TRANSITIONS * sizeof(int));
    int indTransition = 0;

    int initialStates[TOTAL_STATES];
    memset(initialStates, 0, TOTAL_STATES * sizeof(int));
    int indInitialStates = 0;

    int finalStates[TOTAL_STATES];
    memset(finalStates, 0, TOTAL_STATES * sizeof(int));
    int indFinalStates = 0;

    int line = 0;
    char c;
    while((c = fgetc(fptr)) != EOF && line < 4) {

        if(c != ',' && c != '\n' && line < 4) {

            if(line == 2) transitions[indTransition++] = c;
            else num[index++] = c;

        }

        else if(line == 0) {

            states[indStates++] = atoi(num);
            index = 0;
            memset(num, '\0', MAX_LEN * sizeof(char));

        }

        else if(line == 2) {

            initialStates[indInitialStates++] = atoi(num);
            index = 0;
            memset(num, '\0', MAX_LEN * sizeof(char));

        }

        else if(line == 3) {

            finalStates[indFinalStates++] = atoi(num);
            index = 0;
            memset(num, '\0', MAX_LEN * sizeof(char));
        }

        if(c == '\n') line++;
        if(line == 4) break;

    }

    graph* g = createGraph(indStates);



    int x,y;
    char stream[1000];

    while(fscanf(fptr, "%s", stream) != EOF) {
        int j = 0;

        for(int i=0; i<3; i++) {
            memset(num, '\0', MAX_LEN * sizeof(char));
            index = 0;
            while(stream[j] != ',' && stream[j] != '\0') {
                num[index++] = stream[j++];
            }
            if(i == 0)x = atoi(num);
            else if(i == 1) c = (char)num[0];
            else y = atoi(num);
            j++;
        }
        addEdge(g, x, y, c);
    }


    fclose(fptr);


    char str[100];

    printf("Cadena: ");
    scanf("%[^\n]", str);

    int pos = 0;
    int * stack = malloc(sizeof(int) * 100);
    int flag = 0;
    for(int i=0; i<indInitialStates; i++) {
        pos = 0;
        flag |= dfs(g, str, initialStates[i], 0, stack, pos, finalStates, indFinalStates);
    }

    if(!flag) printf("No existen caminos\n");

    return 0;
}

int isFinalState(int * finalStates, int tam, int n) {
    for(int i=0; i<tam; i++)
        if(finalStates[i] == n) return 1;
    return 0;
}

int dfs(graph* g, char* cad, int n, int ind, int * stack, int pos, int * finalStates, int tamFinal)
{
    // Agrega el numero de estado al stack
    stack[pos] = n;

    // Si la cadena ya esta vacia y se encuentra en algun estado final imprime el stack
    if(cad[ind] == '\0' && isFinalState(finalStates, tamFinal, n))
    {
        for (int j = 0; j <= pos; j++)
        {
            if (j == pos)
                printf("q%d\n", stack[j]);
            else
                printf("q%d ---> ", stack[j]);
        }
        return 1;
    }
    else
    {
        int flag = 0;
        node *temp = g->array[n].front;
        while (temp != NULL)
        {
            if (temp->edge == cad[ind])
                flag |= dfs(g, cad, temp->n, ind + 1, stack, pos + 1, finalStates, tamFinal);
            temp = temp->next;
        }
        return flag;
    }
}
