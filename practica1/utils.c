#include "utils.h"

void printMenu()
{
    printf("\r\r===Menu===\n");
    printf("1. Concatenacion\n");
    printf("2. Prefijo\n");
    printf("3. Sufijo\n");
    printf("4. Subcadena\n");
    printf("5. Subsecuencia\n");
    printf("6. Inversion\n");
    printf("7. Potencia\n");
}

int readOption()
{
    int option;
    scanf("%d", &option);
    return option;
}

int length(char string[])
{
    int total = 0;
    while(*(string + total) != '\0')
        total++;
    return total;
}

char* concatencaionUtil(char string1[], char string2[])
{
    int lengthString1 = length(string1);
    int lengthString2 = length(string2);

    int newLength = lengthString1 + lengthString2;

    if(newLength == 0) return NULL;

    char* newString = malloc(newLength + 1);

    for(int i=0; i<newLength; i++)
    {
        if(i < lengthString1)
            newString[i] = string1[i];
        else newString[i] = string2[i - lengthString1];
    }
    newString[newLength] = '\0';

    return newString;
}

void concatenacion()
{
    char cadena1[MAX];
    char cadena2[MAX];


    printf("Cadena 1: ");
    fgets(cadena1, MAX, stdin);
    printf("Cadena 2: ");
    fgets(cadena2, MAX, stdin);

    char *newString = concatencaionUtil(cadena1, cadena2);
    printf("Cadena resultado: %s\n", newString);
    printf("Tamanio: %d\n", length(newString));

    return;
}

char* prefijoUtil(char string[], int n)
{
    int lengthString = length(string);

    if(n > lengthString) return NULL;

    char *newString = malloc(n + 1);

    for(int i=0; i<n; i++)
        newString[i] = string[i];

    newString[n] = '\0';

    return newString;
}

void prefijo()
{
    char cadena[MAX];
    printf("Cadena: ");
    scanf("%s", cadena);

    int n;
    printf("Tamanio: ");
    scanf("%d", &n);

    char *newString = prefijoUtil(cadena, n);
    printf("Cadena resultado: %s\n", newString);

    return;
}

char* sufijoUtil(char string[], int n)
{
    int lengthString = length(string);

    if(n > lengthString) return NULL;

    char *newString = malloc(n + 1);

    int j = n-1;
    for(int i=0; i<n; i++)
    {
        newString[i] = string[lengthString - i - 1];
    }

    newString[n] = '\0';

    return newString;
}

void sufijo()
{
    char cadena[MAX];
    printf("Cadena: ");
    scanf("%s", cadena);

    int n;
    printf("Tamanio: ");
    scanf("%d", &n);

    char *newString = sufijoUtil(cadena, n);
    printf("Cadena resultado: %s\n", newString);

    return;
}

void subcadena()
{

}

void subsecuencia()
{

}

void invertirCadenaUtil(char string[])
{
    int lengthString = length(string);
    int left = 0;
    int right = lengthString - 1;
    while(left < right)
    {
        char aux = string[right];
        string[right--] = string[left];
        string[left++] = aux;
    }
    return;
}

void inversion()
{
    char cadena[MAX];
    printf("Cadena: ");
    scanf("%s", cadena);
    invertirCadenaUtil(cadena);
    printf("Cadena invertida: %s\n", cadena);
    return;
}

char* potenciaUtil(char string[], int n)
{
    if(n == 0) return NULL;

    int lengthString = length(string);
    int total = (n > 0? n : -1 * n);

    if(n < 0)
        invertirCadenaUtil(string);

    int newLength = lengthString * total;
    char* newString = malloc(newLength + 1);

    for(int i=0; i<newLength; i++)
            newString[i] = string[i % lengthString];

    newString[newLength] = '\0';

    return newString;
}

void potencia()
{
    char cadena[MAX];
    printf("Cadena: ");
    scanf("%s", cadena);
    fflush(stdin);

    int n;
    printf("Potencia: ");
    scanf("%d", &n);
    fflush(stdin);

    char * newString = potenciaUtil(cadena, n);
    printf("Cadena potencia: %s\n", newString);

    return;
}
