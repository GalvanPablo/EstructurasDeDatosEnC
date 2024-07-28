#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED

struct ArbolBinarioE;
typedef struct ArbolBinarioE * ArbolB;

// CONSTRUCTOR
ArbolB arbolBinario_nuevo_nodo(int dato);

// DESTRUCTOR
void arbolBinario_destruir_nodo(ArbolB a);

// INSERTAR
int arbolBinario_insertar_nodo(ArbolB a, int dato);

// ELIMINAR
ArbolB arbolBinario_eliminar_nodo(ArbolB a, int dato);

// MOSTRAR
void arbolBinario_preOrden(ArbolB a);
void arbolBinario_inOrden(ArbolB a);
void arbolBinario_postOrden(ArbolB a);

// BUSCAR
ArbolB arbolBinario_buscar(ArbolB a, int dato);

// MENOR Y MAYOR
ArbolB arbolBinario_encontrar_min(ArbolB a);
ArbolB arbolBinario_encontrar_max(ArbolB a);

// OBTENER VALOR
int arbolBinario_getValor_nodo(ArbolB a);
int arbolBinario_getPeso(ArbolB a);

#endif // ARBOLBINARIO_H_INCLUDED
