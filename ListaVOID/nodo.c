#include <stdio.h>
#include <stdlib.h>

#include "nodo.h"

struct Nodo{
    DatoPtr dato;
    NodoPtr siguiente;
};

/// MANEJO DE DATOS
DatoPtr getDato(NodoPtr nodo){
    return nodo->dato;
};
NodoPtr getSiguiente(NodoPtr nodo){
    return nodo->siguiente;
};

void setDato(NodoPtr nodo, DatoPtr nuevoDato){
    nodo->dato = nuevoDato;
};
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSigiente){
    nodo->siguiente = nuevoSigiente;
};

/// CONSTRUCTOR
NodoPtr nodo_crear(DatoPtr dato, NodoPtr siguiente){
    NodoPtr nodo = (NodoPtr)malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->siguiente = siguiente;
    return nodo;
};

/// DESTRUCTOR
void nodo_liberar(NodoPtr nodo){
    free(nodo);
};

/// MOSTRAR
void mostrarInt(NodoPtr nodo){
    printf("%d", *(int*)(nodo->dato));
};
void mostrarChar(NodoPtr nodo){
    printf("%s", (char*)(nodo->dato));
};
void mostrarFloat(NodoPtr nodo){
    printf("%.2f", *(float*)(nodo->dato));
};
