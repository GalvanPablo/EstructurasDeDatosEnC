#include <stdio.h>
#include <stdlib.h>

#include "arbolBinario.h"

struct ArbolBinarioE{
    int dato;
    ArbolB izq;
    ArbolB der;
};

// CONSTRUCTOR
ArbolB arbolBinario_nuevo_nodo(int dato){
    ArbolB a = (ArbolB)malloc(sizeof(struct ArbolBinarioE));
    a->dato = dato;
    a->izq = a->der = NULL;
    return a;
};

// DESTRUCTOR
void arbolBinario_destruir_nodo(ArbolB a){
    a->izq = a->der = NULL;
    free(a);
};

// INSERTAR
int arbolBinario_insertar_nodo(ArbolB a, int dato){
    if(a == NULL){
        return 0;
    }
    if(dato == a->dato){
        return -1;
    }
    if(dato < a->dato){
        // LADO IZQUIERDO
        if(a->izq == NULL){
            a->izq = arbolBinario_nuevo_nodo(dato);
            return 1;
        } else {
            return arbolBinario_insertar_nodo(a->izq, dato);
        }
    } else {
        // LADO DERECHO
        if(a->der == NULL){
            a->der = arbolBinario_nuevo_nodo(dato);
            return 1;
        } else {
            return arbolBinario_insertar_nodo(a->der, dato);
        }
    }
};

// ELIMINAR
ArbolB arbolBinario_eliminar_nodo(ArbolB a, int dato){
    if (a == NULL){
        return a;
    }

    if (dato < a->dato) {
        a->izq = arbolBinario_eliminar_nodo(a->izq, dato);
    } else if (dato > a->dato) {
        a->der = arbolBinario_eliminar_nodo(a->der, dato);
    } else {
        if (a->izq == NULL) {
            ArbolB temp = a->der;
            arbolBinario_destruir_nodo(a);
            return temp;
        } else if (a->der == NULL) {
            ArbolB temp = a->izq;
            arbolBinario_destruir_nodo(a);
            return temp;
        }

        ArbolB temp = arbolBinario_encontrar_min(a->der);
        a->dato = temp->dato;
        a->der = arbolBinario_eliminar_nodo(a->der, temp->dato);
    }
    return a;
};

// MOSTRAR
void arbolBinario_preOrden(ArbolB a){
    if(a != NULL){
        printf("%d ", a->dato);
        arbolBinario_preOrden(a->izq);
        arbolBinario_preOrden(a->der);
    }
};
void arbolBinario_inOrden(ArbolB a){
    if(a != NULL){
        arbolBinario_inOrden(a->izq);
        printf("%d ", a->dato);
        arbolBinario_inOrden(a->der);
    }
};
void arbolBinario_postOrden(ArbolB a){
    if(a != NULL){
        arbolBinario_postOrden(a->izq);
        arbolBinario_postOrden(a->der);
        printf("%d ", a->dato);
    }
};

// BUSCAR
ArbolB arbolBinario_buscar(ArbolB a, int dato){
    if(a == NULL){
         return NULL;
    }
    if(a->dato == dato){
        return a;
    }
    if(dato < a->dato){
        return arbolBinario_buscar(a->izq, dato);
    } else {
        return arbolBinario_buscar(a->der, dato);
    }
};

// MENOR Y MAYOR
ArbolB arbolBinario_encontrar_min(ArbolB a) {
    ArbolB aux = a;
    while (aux->izq != NULL) {
        aux = aux->izq;
    }
    return aux;
}

ArbolB arbolBinario_encontrar_max(ArbolB a){
    ArbolB aux = a;
    while (aux->der != NULL) {
        aux = aux->der;
    }
    return aux;
};

// OBTENER VALOR
int arbolBinario_getValor_nodo(ArbolB a){
    return a->dato;
};

int arbolBinario_getPeso(ArbolB a){
    int num = 0;
    if(a != NULL){
        num = 1;
        num += arbolBinario_getPeso(a->izq);
        num += arbolBinario_getPeso(a->der);
    }
    return num;
};

