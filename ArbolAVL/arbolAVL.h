#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED

struct ArbolAVLE;
typedef struct ArbolAVLE * ArbolAVL;


int arbolAVL_insertar(ArbolAVL * a, int dato);
int arbolAVL_eliminar(ArbolAVL * a, int dato);

/// MOSTRAR
void arbolAVL_mostrar(ArbolAVL a);
void arbolAVL_mostrar_preOrden(ArbolAVL a);
void arbolAVL_mostrar_inOrden(ArbolAVL a);
void arbolAVL_mostrar_postOrden(ArbolAVL a);

/// BUSCAR
int arbolAVL_buscar(ArbolAVL a, int);

/// BALANCER
void arbolAVL_balancear(ArbolAVL * a);
int arbolAVL_rotar_derecha(ArbolAVL * a);
int arbolAVL_rotar_izquierda(ArbolAVL * a);

/// GETTERS
int arbolAVL_getBalance(ArbolAVL a);
int arbolAVL_getAltura(ArbolAVL a);

/// OTROS
int arbolAVL_reordenar(ArbolAVL * un_arbol, ArbolAVL * aux_arbol);

#endif // ARBOLAVL_H_INCLUDED
