#include <stdio.h>
#include <stdlib.h>

#include "arbolAVL.h"

int main()
{
    ArbolAVL arbol = NULL;

    arbolAVL_insertar(&arbol ,1);
    arbolAVL_insertar(&arbol ,55);
    arbolAVL_insertar(&arbol ,24);
    arbolAVL_insertar(&arbol ,12);
    arbolAVL_insertar(&arbol ,13);

    arbolAVL_mostrar(arbol);
    printf("\n\n");
    arbolAVL_mostrar_inOrden(arbol);
    printf("\n\n");

    arbolAVL_eliminar(&arbol, 12);
    arbolAVL_mostrar(arbol);
    printf("\n\n");
    arbolAVL_mostrar_inOrden(arbol);
    printf("\n\n");

    return 0;
}
