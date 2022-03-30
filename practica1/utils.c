#include "utils.h"

void clearBuffer()
{
    char c;
    do
    {
        c = getchar();
    } while (c != '\n' && c!=EOF);
    
}
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


    clearBuffer();
    printf("Cadena 1: ");
    scanf("%[^\n]", cadena1);
    clearBuffer();
    printf("Cadena 2: ");
    scanf("%[^\n]", cadena2);
    clearBuffer();

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
    clearBuffer();
    scanf("%[^\n]", cadena);

    int n;
    clearBuffer();
    printf("Tamanio: ");
    scanf("%d", &n);

    clearBuffer();
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
    clearBuffer();
    scanf("%[^\n]", cadena);
    int n;
    printf("Tamanio: ");
    clearBuffer();
    scanf("%d", &n);
    clearBuffer();
    char *newString = sufijoUtil(cadena, n);
    printf("Cadena resultado: %s\n", newString);

    return;
}

char* subcadenaUtil(char string[], int left, int right)
{
    int newLength = right - left + 1;
    char *newString = malloc(newLength + 1);
    for(int i=left - 1; i < right; i++)
        newString[i - left + 1] = string[i];
    newString[newLength] = '\0';
    return newString;
}

void subcadena()
{
    char cadena[MAX];
    clearBuffer();
    printf("Cadena: ");
    scanf("%[^\n]", cadena);
    clearBuffer();
    int lengthString = length(cadena);

    int left,right;
    printf("Dame los rangos de la subcadena: ");
    printf("Izquierdo: ");
    scanf("%d", &left);
    clearBuffer();
    printf("Derecho: ");
    scanf("%d", &right);
    clearBuffer();
    if(left <= 0 || right > lengthString)
    {
        printf("Intervalo fuera de rango\n");
        return;
    }
    char *newString = subcadenaUtil(cadena, left, right);
    printf("Subcadena: %s\n", newString);
    return;
}

char* subsecuenciaUtil(char string[], char indices[], int n)
{
    int lengthString = length(string);
    char* newString = malloc(lengthString);

    int temp = 0;
    for(int i=0; i<lengthString; i++)
    {
        int flag = 1;
        for(int j=0; j<n && flag; j++)
            if(string[i] == indices[j])flag = 0;
        if(flag)newString[temp++] = string[i];
    }
    newString[temp] = '\0';
    return newString;
}

void subsecuencia()
{
    char cadena[MAX];
    clearBuffer();
    printf("Cadena: ");
    scanf("%[^\n]", cadena);
    clearBuffer();
    int cadenaLength = length(cadena);
    int n;
    printf("Ingrese la cantidad de caracteres a eliminar: ");
    scanf("%d", &n);
    clearBuffer();
    if(n > cadenaLength) return;
    else if(n == cadenaLength)
    {
        printf("La cadena esta vacia\n");
        return;
    }

    char* indices = malloc(n);

    for(int i=0; i<n; i++)
    {
        printf("Caracter: ");
        scanf("%c", (indices + i));
        clearBuffer();
    }
    char* newString = subsecuenciaUtil(cadena, indices, n);
    printf("Subsecuencia: %s\n", newString);
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
    clearBuffer();
    scanf("%[^\n]", cadena);
    clearBuffer();
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
    clearBuffer();
    printf("Cadena: ");
    scanf("%[^\n]", cadena);
    clearBuffer();

    int n;
    printf("Potencia: ");
    scanf("%d", &n);
    clearBuffer();

    char * newString = potenciaUtil(cadena, n);
    printf("Cadena potencia: %s\n", newString);

    return;
}
