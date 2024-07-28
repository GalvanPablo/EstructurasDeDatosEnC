#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

struct Pila{
    int longitud;
    NodoPtr primero;
};

/// CONSTRUCTOR
PilaPtr pila_crear(){
    PilaPtr pila = (PilaPtr)malloc(sizeof(struct Pila));
    pila->primero = NULL;
    pila->longitud = 0;

    return pila;
};

/// DESTRUCTOR
void pila_liberar(PilaPtr pila){
    while(pila_getLongitud(pila) != 0){
        pila_desapilar(pila);
    }
    free(pila);
};

/// PRIMITIVAS
// ENCOLAR
void pila_apilar(PilaPtr pila, DatoPtr dato){
    if(pila_getLongitud(pila) < 1){
        pila->primero = nodo_crear(dato, NULL);
    } else {
        pila->primero = nodo_crear(dato, pila->primero);
    }
    pila->longitud++;
};
// DESENCOLAR
DatoPtr pila_desapilar(PilaPtr pila){
    if(pila_getLongitud(pila) == 0) return NULL;
    NodoPtr desapilado = pila->primero;
    pila->primero = getSiguiente(desapilado);
    pila->longitud--;

    DatoPtr dato = getDato(desapilado);
    nodo_liberar(desapilado);
    return dato;
};
// OBTENER
DatoPtr pila_obtener(PilaPtr pila){
    return getDato(pila->primero);
};
// OBTENER LONGITUD
int pila_getLongitud(PilaPtr pila){
    return pila->longitud;
};
