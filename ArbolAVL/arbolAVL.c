#include <stdio.h>
#include <stdlib.h>

#include "arbolAVL.h"

struct ArbolAVLE{
    int dato;
    ArbolAVL izq;
    ArbolAVL der;
};

int arbolAVL_insertar(ArbolAVL * a, int dato){
    if(*a == NULL){
        *a = (ArbolAVL)malloc(sizeof(struct ArbolAVLE));
        if(*a == NULL) return 0;
        (*a)->dato = dato;
        (*a)->izq = (*a)->der = NULL;
    } else {
        if((*a)->dato == dato){
            return -1;
        } else if((*a)->dato < dato){
            arbolAVL_insertar(&((*a)->der),dato);
        } else {
            arbolAVL_insertar(&((*a)->izq),dato);
        }
    }
    arbolAVL_balancear(a);
    return 1;
};
int arbolAVL_eliminar(ArbolAVL * a, int dato){
    if(a == NULL) return 0;

    ArbolAVL * aux = NULL;
    if((*a)->dato == dato){
        if((*a)->der == NULL){
            (*a) = (*a)->izq;
            arbolAVL_balancear(a);
        }
        else if((*a)->izq == NULL){
            (*a) = (*a)->der;
            arbolAVL_balancear(a);
        } else{
            aux = a;
            arbolAVL_reordenar(&((*a)->izq), aux);
            arbolAVL_balancear(&((*a)->izq));
        }
    } else if((*a)->dato < dato){
        if((*a)->der == NULL) return 0;
        return arbolAVL_eliminar(&((*a)->der), dato);
    } else{
        if((*a)->izq == NULL) return 0;
        return arbolAVL_eliminar(&((*a)->izq), dato);
    }

    return 1;
};

/// MOSTRAR
void arbolAVL_mostrar(ArbolAVL a){
    if(a != NULL){
        printf("(");
        arbolAVL_mostrar(a->izq);
        printf(" %d ", a->dato);
        arbolAVL_mostrar(a->der);
        printf(")");
    } else {
        printf("_");
    }
};
void arbolAVL_mostrar_preOrden(ArbolAVL a){
    if(a != NULL){
        printf("%d ", a->dato);
        arbolAVL_mostrar_preOrden(a->izq);
        arbolAVL_mostrar_preOrden(a->der);
    }
};
void arbolAVL_mostrar_inOrden(ArbolAVL a){
    if(a != NULL){
        arbolAVL_mostrar_inOrden(a->izq);
        printf("%d ", a->dato);
        arbolAVL_mostrar_inOrden(a->der);
    }
};
void arbolAVL_mostrar_postOrden(ArbolAVL a){
    if(a != NULL){
        arbolAVL_mostrar_postOrden(a->izq);
        arbolAVL_mostrar_postOrden(a->der);
        printf("%d ", a->dato);
    }
};

/// BUSCAR
int arbolAVL_buscar(ArbolAVL a, int);

/// BALANCER
void arbolAVL_balancear(ArbolAVL * a){
    if(a == NULL) return;

    int aux_balance = arbolAVL_getBalance(*a);
    if(aux_balance > 1){
        if(arbolAVL_getBalance((*a)->der) >= 1){
            arbolAVL_rotar_izquierda(a);
        } else {
            arbolAVL_rotar_derecha(&((*a)->der));
            arbolAVL_rotar_izquierda(a);
        }
    } else if(aux_balance < -1){
        if(arbolAVL_getBalance((*a)->izq) <= -1){
            arbolAVL_rotar_derecha(a);
        } else {
            arbolAVL_rotar_izquierda(&((*a)->izq));
            arbolAVL_rotar_derecha(a);
        }
    }
};
int arbolAVL_rotar_derecha(ArbolAVL * a){
    if(a == NULL) return 0;

    ArbolAVL raiz = (*a);
    ArbolAVL raiz_nueva = (*a) -> izq;
    ArbolAVL auxiliar = (*a) -> izq -> der;

    (*a) = raiz_nueva;
    raiz_nueva -> der = raiz;
    raiz -> izq = auxiliar;
    return 1;
};
int arbolAVL_rotar_izquierda(ArbolAVL * a){
    if(a == NULL) return 0;

    ArbolAVL raiz = *a;
    ArbolAVL raiz_nueva = (*a) -> der;
    ArbolAVL auxiliar = (*a) -> der -> izq;

    *a = raiz_nueva;
    (*a) -> izq = raiz;
    raiz -> der = auxiliar;

    return 1;
};

/// GETTERS
int arbolAVL_getBalance(ArbolAVL a){
    if(a == NULL) return 0;
    return arbolAVL_getAltura(a->der) - arbolAVL_getAltura(a->izq);
};
int arbolAVL_getAltura(ArbolAVL a){
    if(a == NULL) return 0;
    int altura_izq = arbolAVL_getAltura(a->izq);
    int altura_der = arbolAVL_getAltura(a->der);
    if (altura_der > altura_izq){
        return altura_der + 1;
    } else{
        return altura_izq + 1;
    }

};

/// OTROS
int arbolAVL_reordenar(ArbolAVL * a, ArbolAVL * aux_a){
    if ((*a)->der == NULL){
        (*aux_a)->dato = (*a)->dato;
        *a = (*a)->izq;
    } else {
        arbolAVL_reordenar(&(*a)->der, aux_a);
    }
    return 1;
};
