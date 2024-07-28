#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista{
    NodoPtr primero;
};

NodoPtr getPrimero(ListaPtr lista){
    return lista->primero;
};
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero){
    lista->primero = nuevoPrimero;
};

/// CONSTRUCTOR
ListaPtr lista_crear(){
    ListaPtr lista = (ListaPtr)malloc(sizeof(struct Lista));
    lista->primero = NULL;
    return lista;
};

/// DESTRUCTOR
void lista_liberar(ListaPtr lista){
    NodoPtr actual = getPrimero(lista);
    NodoPtr aux;
    while(actual != NULL){
        aux = actual;
        actual = getSiguiente(actual);
        free(aux);
    }
};

/// MOSTRAR
void lista_mostrar(ListaPtr lista, void(*mostrar)(DatoPtr)){
    printf("Lista con %d elementos\n", lista_obtener_tamanio(lista));
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL){
        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");
};
void lista_mostrar_int(ListaPtr lista){
    printf("\nLista con %d elementos\n[ ", lista_obtener_tamanio(lista));
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL){
        mostrarInt(actual);
        actual = getSiguiente(actual);
        printf(" ");
    }
    printf("]\n\n");
};
void lista_mostrar_float(ListaPtr lista){
    printf("\nLista con %d elementos\n", lista_obtener_tamanio(lista));
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL){
        mostrarFloat(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");
};
void lista_mostrar_char(ListaPtr lista){
    printf("\nLista con %d elementos\n", lista_obtener_tamanio(lista));
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL){
        mostrarChar(actual);
        actual = getSiguiente(actual);
    }
    printf("\n\n");
};

/// PRIMITIVAS
// INSERTAR
void lista_insertar_primero(ListaPtr lista, DatoPtr dato){
    NodoPtr nuevoNodo = nodo_crear(dato, getPrimero(lista));
    setPrimero(lista, nuevoNodo);
};
void lista_insertar_posicion(ListaPtr lista, DatoPtr dato, int posicion){
    if(posicion < lista_obtener_tamanio(lista)){
        NodoPtr actual = getPrimero(lista);
        if(actual == NULL){
            if(posicion == 0){
                setPrimero(lista, nodo_crear(dato, NULL));
            }
        } else {
            int pos = 0;
            while(getSiguiente(actual) != NULL && pos < posicion -1){
                actual = getSiguiente(actual);
                pos++;
            }
            NodoPtr nuevoNodo = nodo_crear(dato, getSiguiente(actual));
            setSiguiente(actual, nuevoNodo);
        }
    }
};
void lista_insertar_ultimo(ListaPtr lista, DatoPtr dato){
    NodoPtr nuevoNodo = nodo_crear(dato, NULL);
    NodoPtr actual = getPrimero(lista);
    if(actual == NULL){ // Si no hay nodos en la lista
        setPrimero(lista, nuevoNodo);
    } else { // Si hay nodos en la lista
        while(getSiguiente(actual) != NULL){
            actual = getSiguiente(actual);
        }
        setSiguiente(actual, nuevoNodo);
    }
};
void lista_insertar_enOrden(ListaPtr lista, DatoPtr dato, int(*comparar)(DatoPtr, DatoPtr)){
    // En lo que se pase como FN de comparar se tiene que transformar los DatoPtr en los 2 datos a comparar para luego relizar dicha accion
    // Ej: LibroPtr lA = *(LibroPtr*)a;
    // Una vez obtenido el TDA a comparar es aconsejable usar una primitiva para hacer las comparaciones la cual debe devolver -1 menor, 0 igual, 1 mayor
    NodoPtr nuevoNodo = nodo_crear(dato, NULL);
    if (getPrimero(lista) == NULL) {
        // Si la lista esta vacia, el nuevo nodo se convierte en el primero
        setPrimero(lista, nuevoNodo);
        return;
    }

    NodoPtr actual = getPrimero(lista);
    NodoPtr anterior = NULL;
    while (actual != NULL && comparar(dato, getDato(actual)) > 0) {
        anterior = actual;
        actual = getSiguiente(actual);
    }

    if (anterior == NULL) {
        setPrimero(lista, nuevoNodo);
    } else {
        setSiguiente(anterior, nuevoNodo);
    }
    setSiguiente(nuevoNodo, actual);
}
// OBTENER
DatoPtr lista_obtener_primero(ListaPtr lista){
    return getDato(getPrimero(lista));
};
DatoPtr lista_obtener_posicion(ListaPtr lista, int posicion){
    if(posicion < lista_obtener_tamanio(lista)){
        NodoPtr actual = getPrimero(lista);
        if(posicion == 0 && actual == NULL){
            return NULL;
        } else {
            int pos = 0;
            while(getSiguiente(actual) != NULL && pos < posicion -1){
                actual = getSiguiente(actual);
                pos++;
            }
            return getDato(actual);
        }
    } else {
        return NULL;
    }
};
DatoPtr lista_obtener_ultimo(ListaPtr lista){
    NodoPtr actual = getPrimero(lista);
    while(getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }
    return getDato(actual);
};
// ELIMINAR
DatoPtr lista_eliminar_primero(ListaPtr lista){
    NodoPtr eliminado = getPrimero(lista);
    NodoPtr aux = getSiguiente(eliminado);
    setPrimero(lista, aux);
    DatoPtr dato = getDato(eliminado);
    nodo_liberar(eliminado);
    return dato;
};
DatoPtr lista_eliminar_posicion(ListaPtr lista, int posicion){
    if(posicion < lista_obtener_tamanio(lista)){
        NodoPtr actual = getPrimero(lista);
        if(posicion == 0 && actual == NULL){
            return NULL;
        } else {
            int pos = 0;
            NodoPtr anterior;
            while(getSiguiente(actual) != NULL && pos < posicion){
                anterior = actual;
                actual = getSiguiente(actual);
                pos++;
            }
            setSiguiente(anterior, getSiguiente(actual));
            DatoPtr dato = getDato(actual);
            nodo_liberar(actual);
            return dato;
        }
    } else {
        return NULL;
    }
};
DatoPtr lista_eliminar_ultimo(ListaPtr lista){
    NodoPtr anterior = NULL;
    NodoPtr actual = getPrimero(lista);
    while(getSiguiente(actual) != NULL){
        anterior = actual;
        actual = getSiguiente(actual);
    }
    setSiguiente(anterior, NULL);
    DatoPtr dato = getDato(actual);
    nodo_liberar(actual);
    return dato;;
};
DatoPtr lista_eliminar_coincidencia(ListaPtr lista, DatoPtr dato, int(*comparar)(DatoPtr, DatoPtr)){
    NodoPtr anterior = NULL;
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL && comparar(getDato(actual), dato) != 0){
        anterior = actual;
        actual = getSiguiente(actual);
    }
    if(actual != NULL){
        if(anterior == NULL){
            setPrimero(lista, getSiguiente(actual));
        } else {
            setSiguiente(anterior, getSiguiente(actual));
        }
        DatoPtr datoEliminado = getDato(actual);
        nodo_liberar(actual);
        return datoEliminado;
    } else {
        return NULL;
    }
};
// BUSCAR
DatoPtr lista_buscar(ListaPtr lista, DatoPtr datoBuscado, int(*comparar)(DatoPtr, DatoPtr)){
    // En lo que se pase como FN de comparar se tiene que transformar los DatoPtr en los 2 datos a comparar para luego relizar dicha accion
    // Ej: LibroPtr lA = *(LibroPtr*)a;
    // Una vez obtenido el TDA a comparar es aconsejable usar una primitiva para hacer las comparaciones la cual debe devolver -1 menor, 0 igual, 1 mayor
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL && comparar(getDato(actual), datoBuscado) != 0){
        actual = getSiguiente(actual);
    }
    if(actual != NULL){
        return getDato(actual);
    } else {
        return NULL;
    }
};
// OBTENER TAMANIO
int lista_obtener_tamanio(ListaPtr lista){
    int tam = 0;
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL){
        tam++;
        actual = getSiguiente(actual);
    }
    return tam;
};
// ORDENAR
void lista_ordenar(ListaPtr lista, int(*comparar)(DatoPtr, DatoPtr)){
    int permutaction;
    NodoPtr nodo;
    NodoPtr ultimo = NULL;
    if(lista_obtener_tamanio(lista) >= 2){
        do{
            permutaction = 0;
            nodo = getPrimero(lista);
            while(getSiguiente(nodo) != ultimo){
                if(comparar(getDato(nodo), getDato(getSiguiente(nodo))) > 0){
                    DatoPtr aux = getDato(nodo);
                    setDato(nodo,getDato(getSiguiente(nodo)));
                    setDato(getSiguiente(nodo),aux);
                    permutaction = 1;
                }
                nodo = getSiguiente(nodo);
            }
            ultimo = nodo;
        }while(permutaction != 0);
    }
};
// DUPLICAR
ListaPtr lista_duplicar(ListaPtr lista){
    ListaPtr nuevaLista = lista_crear();
    NodoPtr actual = getPrimero(lista);
    while(actual != NULL){
        DatoPtr dato = getDato(actual);
        lista_insertar_ultimo(nuevaLista, dato);
        actual = getSiguiente(actual);
    }
    return nuevaLista;
};
