#include <stdio.h>
#include <stdlib.h>

#include "cola.h"

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
    ColaPtr cola = cola_crear();

    int n1 = 1;
    cola_encolar(cola, &n1);

    int n2 = 2;
    cola_encolar(cola, &n2);

    int n3 = 3;
    cola_encolar(cola, &n3);

    int n4 = 4;
    cola_encolar(cola, &n4);

    int n5 = 5;
    cola_encolar(cola, &n5);


    printf("Longitud: %d\n\n", cola_getLongitud(cola));


    printf("\nDesencolar -> ");
    mostrarDato(cola_desencolar(cola));

    printf("\nObtener dato: ");
    mostrarDato(cola_obtener(cola));

    printf("\nDesencolar -> ");
    mostrarDato(cola_desencolar(cola));

    printf("\nDesencolar -> ");
    mostrarDato(cola_desencolar(cola));

    printf("\n\nLongitud: %d", cola_getLongitud(cola));
    int n6 = 6;
    printf("\nEncolar %d\n", n6);
    cola_encolar(cola, &n6);
    printf("Longitud: %d\n\n", cola_getLongitud(cola));

    printf("\nDesencolar -> ");
    mostrarDato(cola_desencolar(cola));

    printf("\nDesencolar -> ");
    mostrarDato(cola_desencolar(cola));


    printf("\n\nLongitud: %d\n", cola_getLongitud(cola));
    cola_liberar(cola);
    return 0;
}
