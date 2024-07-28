#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "nodo.h"

struct Pila;
typedef struct Pila * PilaPtr;

/// CONSTRUCTOR
PilaPtr pila_crear();

/// DESTRUCTOR
void pila_liberar(PilaPtr pila);

/// PRIMITIVAS
// ENCOLAR
void pila_apilar(PilaPtr pila, DatoPtr dato);
// DESENCOLAR
DatoPtr pila_desapilar(PilaPtr pila);
// OBTENER
DatoPtr pila_obtener(PilaPtr pila);
// OBTENER LONGITUD
int pila_getLongitud(PilaPtr pila);

#endif // PILA_H_INCLUDED
