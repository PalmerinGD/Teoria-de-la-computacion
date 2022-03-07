#include <stdio.h>

typedef struct t1
{
    char palabra[100];
}t1;
int main()
{
    t1 t;
    scanf("%s", t.palabra);
    t1 r;
    r = t;
    printf("%s\n", r.palabra);
    r.palabra[0] = 'f';
    printf("%s\n", t.palabra);
    printf("%s", r.palabra);

}