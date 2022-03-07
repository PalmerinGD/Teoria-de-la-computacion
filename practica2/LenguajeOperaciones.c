#include "LenguajeOperaciones.h"

Lenguaje unionLenguajes(Lenguaje l1, Lenguaje l2)
{
    Lenguaje res;
    res.cadenas = NULL;
    res.cadenas = copy(l1.cadenas, res.cadenas);
    res.cadenas = copy(l2.cadenas, res.cadenas);
    return res;
}

Lenguaje interseccionLenguajes(Lenguaje l1, Lenguaje l2)
{
    Lenguaje res;
    return res;
}