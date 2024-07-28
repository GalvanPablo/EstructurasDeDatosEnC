#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct FechaE;
typedef struct FechaE * Fecha;

typedef enum {DOMINGO,LUNES,MARTES,MIERCOLES,JUEVES,VIERNES,SABADO} DiaSemana;

/// CONSTRUCTOR
Fecha fecha_crear(int dia, int mes, int anio);

/// DESTRUCTOR
void fecha_destruir(Fecha f);

/// MOSTRAR
void fecha_mostrar(Fecha f);
char* fecha_toString(Fecha f);

/// PRIMITIVAS
int fecha_comparar(Fecha fA, Fecha fB);
Fecha fecha_sumar(Fecha f, int dias, int mes, int anio);    /// SIN HACER
int fecha_diasEntre(Fecha fA, Fecha fB);    /// SIN HACER

/// SETTERS
void fecha_setDia(Fecha f, int dia);
void fecha_setMes(Fecha f, int mes);
void fecha_setAnio(Fecha f, int anio);

/// GETTERS
int fecha_getDia(Fecha f);
int fecha_getMes(Fecha f);
int fecha_getAnio(Fecha f);
int fecha_getDiaSemana(Fecha f);

/// OTRAS
DiaSemana determinarDiaDeLaSemana(int day, int month, int year);
char* fecha_nombreDiaSemana(int num_dia);

#endif // FECHA_H_INCLUDED
