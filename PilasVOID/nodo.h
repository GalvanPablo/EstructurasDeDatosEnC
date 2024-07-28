#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;
typedef struct Nodo * NodoPtr;

/// MANEJO DE DATOS
typedef void * DatoPtr; //Dato del tipo puntero a cualquier cosa

DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSigiente);

/// CONSTRUCTOR
NodoPtr nodo_crear(DatoPtr dato, NodoPtr siguiente);

/// DESTRUCTOR
void nodo_liberar(NodoPtr nodo);

/// MOSTRAR
void mostrarInt(NodoPtr nodo);
void mostrarChar(NodoPtr nodo);
void mostrarFloat(NodoPtr nodo);

#endif // NODO_H_INCLUDED
