#include <stdio.h>
#include <stdlib.h>

#include "cola.h"

struct Cola{
    int longitud;
    NodoPtr primero;
    NodoPtr ultimo;
};

/// CONSTRUCTOR
ColaPtr cola_crear(){
    ColaPtr cola = (ColaPtr)malloc(sizeof(struct Cola));
    cola->primero = cola->ultimo = NULL;
    cola->longitud = 0;

    return cola;
};

/// DESTRUCTOR
void cola_liberar(ColaPtr cola){
    while(cola_getLongitud(cola) != 0){
        cola_desencolar(cola);
    }
    free(cola);
};

/// PRIMITIVAS
// ENCOLAR
void cola_encolar(ColaPtr cola, DatoPtr dato){
    if(cola == NULL) return;
    NodoPtr nuevoNodo = nodo_crear(dato, NULL);

    if(cola_getLongitud(cola) < 1){
        cola->primero = nuevoNodo;
        cola->ultimo = cola->primero;
    } else {
        setSiguiente(cola->ultimo, nuevoNodo);
        cola->ultimo = nuevoNodo;
    }
    cola->longitud++;
};
// DESENCOLAR
DatoPtr cola_desencolar(ColaPtr cola){
    if(cola_getLongitud(cola) < 1) return NULL;

    NodoPtr desencolado = cola->primero;
    cola->primero = getSiguiente(desencolado);
    cola->longitud--;

    DatoPtr dato = getDato(desencolado);
    nodo_liberar(desencolado);
    return dato;
};
// OBTENER
DatoPtr cola_obtener(ColaPtr cola){
    return getDato(cola->primero);
};
// OBTENER TAMANIO
int cola_getLongitud(ColaPtr cola){
    return cola->longitud;
};

