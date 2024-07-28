#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include "nodo.h"

struct Cola;
typedef struct Cola * ColaPtr;

/// CONSTRUCTOR
ColaPtr cola_crear();

/// DESTRUCTOR
void cola_liberar(ColaPtr cola);

/// PRIMITIVAS
// ENCOLAR
void cola_encolar(ColaPtr cola, DatoPtr dato);
// DESENCOLAR
DatoPtr cola_desencolar(ColaPtr cola);
// OBTENER
DatoPtr cola_obtener(ColaPtr cola);
// OBTENER LONGITUD
int cola_getLongitud(ColaPtr cola);

#endif // COLA_H_INCLUDED
