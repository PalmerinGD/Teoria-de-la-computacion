#include "LenguajeOperaciones.h"

Lenguaje unionLenguajes(Lenguaje l1, Lenguaje l2)
{
    Lenguaje res;
    res.cadenas = NULL;
    copy(l1.cadenas, &res.cadenas);
    copy(l2.cadenas, &res.cadenas);
    return res;
}

Lenguaje interseccionLenguajes(Lenguaje l1, Lenguaje l2)
{
    Lenguaje res;
    res.cadenas = NULL;
    interseccion(l1.cadenas, l2.cadenas, &res.cadenas);
    return res;
}

Lenguaje potenciaLenguaje(Lenguaje l1, int n)
{
    Lenguaje res;
    res.cadenas = NULL;
    for(int i=1; i<=n; i++)
    {
        if(i == 1)
        {
            copy(l1.cadenas, &res.cadenas);
        }
        else 
        {
            Lenguaje aux;
            aux.cadenas = NULL;
            Multiplicar(l1.cadenas, res.cadenas, &aux.cadenas);
            res = aux;
        }
    }
    return res;
}