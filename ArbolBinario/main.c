#include <stdio.h>
#include <stdlib.h>

#include "arbolBinario.h"

#define CANT_N 11

int main()
{
    printf("######### Arbol binario #########\n");
    int numeros[CANT_N] = {15,30,41,60,50,53,46,12,13,56,53};

    ArbolB arbol = arbolBinario_nuevo_nodo(numeros[0]);
    printf("%d raiz\n", numeros[0]);
    for(int i = 0; i<CANT_N; i++){
        if(numeros[i] != numeros[0]){
            int r = arbolBinario_insertar_nodo(arbol, numeros[i]);
            switch(r){
                case -1:
                    printf("%d repetido\n", numeros[i]);
                break;
                case 0:
                    printf("%d error\n", numeros[i]);
                break;
                case 1:
                    printf("%d insertado\n", numeros[i]);
                break;
            }

        }
    }

    printf("\n\n## PreOrden\n");
    arbolBinario_preOrden(arbol);

    printf("\n\n## InOrden\n");
    arbolBinario_inOrden(arbol);

    printf("\n\n## PostOrden\n");
    arbolBinario_postOrden(arbol);

    printf("\n\n## Menor: %d", arbolBinario_getValor_nodo(arbolBinario_encontrar_min(arbol)));
    printf("\n\n## Mayor: %d", arbolBinario_getValor_nodo(arbolBinario_encontrar_max(arbol)));

    int num = 46;
    printf("\n\n## Se busca el %d\n", num);
    ArbolB resultado = arbolBinario_buscar(arbol, num);
    if(resultado != NULL){
        printf("Se encontro el nodo!!!");
    } else {
        printf("No se encontro el nodo!!!");
    }

    printf("\n\n## Eliminando el %d", num);
    arbolBinario_eliminar_nodo(arbol,num);

    printf("\n\nResultado\n");
    arbolBinario_inOrden(arbol);


    printf("\n\n## Se busca el %d\n", num);
    resultado = arbolBinario_buscar(arbol, num);
    if(resultado != NULL){
        printf("Se encontro el nodo!!!");
    } else {
        printf("No se encontro el nodo!!!");
    }


    printf("\n\n## Peso del arbol: %d\n\n", arbolBinario_getPeso(arbol));
    return 0;
}
