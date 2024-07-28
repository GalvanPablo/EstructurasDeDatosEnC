#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;
typedef struct Lista * ListaPtr;

NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

/// CONSTRUCTOR
ListaPtr lista_crear();

/// DESTRUCTOR
void lista_liberar(ListaPtr lista);

/// MOSTRAR
void lista_mostrar(ListaPtr lista, void(*mostrar)(DatoPtr));
void lista_mostrar_int(ListaPtr lista);
void lista_mostrar_float(ListaPtr lista);
void lista_mostrar_char(ListaPtr lista);

/// PRIMITIVAS
// INSERTAR
void lista_insertar_primero(ListaPtr lista, DatoPtr dato);
void lista_insertar_posicion(ListaPtr lista, DatoPtr dato, int posicion);
void lista_insertar_ultimo(ListaPtr lista, DatoPtr dato);
void lista_insertar_enOrden(ListaPtr lista, DatoPtr dato, int(*comparar)(DatoPtr, DatoPtr));
// OBTENER
DatoPtr lista_obtener_primero(ListaPtr lista);
DatoPtr lista_obtener_posicion(ListaPtr lista, int posicion);
DatoPtr lista_obtener_ultimo(ListaPtr lista);
// ELIMINAR
DatoPtr lista_eliminar_primero(ListaPtr lista);
DatoPtr lista_eliminar_posicion(ListaPtr lista, int posicion);
DatoPtr lista_eliminar_ultimo(ListaPtr lista);
DatoPtr lista_eliminar_coincidencia(ListaPtr lista, DatoPtr dato, int(*comparar)(DatoPtr, DatoPtr));
// BUSCAR
DatoPtr lista_buscar(ListaPtr lista, DatoPtr datoBuscado, int(*comparar)(DatoPtr, DatoPtr));
// OBTENER TAMANIO
int lista_obtener_tamanio(ListaPtr lista);
// ORDENAR
void lista_ordenar(ListaPtr lista, int(*comparar)(DatoPtr, DatoPtr));
// DUPLICAR
ListaPtr lista_duplicar(ListaPtr lista);

#endif // LISTA_H_INCLUDED
