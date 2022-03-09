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
    int flag = (n < 0 ? 1 : 0);
    if(flag)n *= -1;
    Lenguaje res;
    res.cadenas = NULL;
    for(int i=1; i<=n; i++)
    {
        if(i == 1 && !flag)
        {
            copy(l1.cadenas, &res.cadenas);
        }
        else if(i == 1 && flag)
        {
            copyInvert(l1.cadenas, &res.cadenas);
            l1 = res;
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