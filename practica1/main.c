#include <stdio.h>
#ifndef __UTILS_H__
#include  "utils.h"
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif


int main()
{
    while(true)
    {
        printMenu();
        int option = readOption();
        fflush(stdin);
        switch(option)
        {
            case 1:
                concatenacion();
                break;
            case 2:
                prefijo();
                break;
            case 3:
                sufijo();
                break;
            case 4:
                subcadena();
                break;
            case 5:
                subsecuencia();
                break;
            case 6:
                inversion();
                break;
            case 7:
                potencia();
                break;
            default:
                return 0;
        }
    }
}
