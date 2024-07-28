#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

void mostrarDato(void* dato){
    if(dato == NULL){
        printf("NULL\n");
    } else {
        int num = *(int*)dato;
        printf("%d\n", num);
    }
}

int main()
{
    PilaPtr pila = pila_crear();

    int n1 = 1;
    pila_apilar(pila, &n1);

    int n2 = 2;
    pila_apilar(pila, &n2);

    int n3 = 3;
    pila_apilar(pila, &n3);

    int n4 = 4;
    pila_apilar(pila, &n4);

    int n5 = 5;
    pila_apilar(pila, &n5);


    printf("Longitud: %d\n\n", pila_getLongitud(pila));


    printf("\nDesencolar -> ");
    mostrarDato(pila_desapilar(pila));

    printf("\nObtener dato: ");
    mostrarDato(pila_obtener(pila));

    printf("\nDesencolar -> ");
    mostrarDato(pila_desapilar(pila));

    printf("\nDesencolar -> ");
    mostrarDato(pila_desapilar(pila));

    printf("\n\nLongitud: %d", pila_getLongitud(pila));
    int n6 = 6;
    printf("\nEncolar %d\n", n6);
    pila_apilar(pila, &n6);
    printf("Longitud: %d\n\n", pila_getLongitud(pila));

    printf("\nDesencolar -> ");
    mostrarDato(pila_desapilar(pila));

    printf("\nDesencolar -> ");
    mostrarDato(pila_desapilar(pila));


    printf("\n\nLongitud: %d\n", pila_getLongitud(pila));
    pila_liberar(pila);
    return 0;
}
