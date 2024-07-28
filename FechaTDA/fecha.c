#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"

struct FechaE{
    int dia;
    int mes;
    int anio;
    DiaSemana diaSemana;
};

/// CONSTRUCTOR
Fecha fecha_crear(int dia, int mes, int anio){
    if(dia < 1 || dia > 31) return NULL;
    if(mes < 1 || mes > 12) return NULL;
    if(anio < 1) return NULL;

    Fecha f = (Fecha)malloc(sizeof(struct FechaE));
    f->dia = dia;
    f->mes = mes;
    f->anio = anio;
    f->diaSemana = determinarDiaDeLaSemana(dia,mes,anio);

    return f;
};

/// DESTRUCTOR
void fecha_destruir(Fecha f){
    free(f);
};

/// MOSTRAR
void fecha_mostrar(Fecha f){
    printf("%d/%d/%d\n", f->dia, f->mes, f->anio);
};
char* fecha_toString(Fecha f){
    // Calculamos el tamaño máximo de la cadena (dd/mm/aaaa + nulo)
    int tamano = snprintf(NULL, 0, "%02d/%02d/%d", f->dia, f->mes, f->anio);

    // Asignamos memoria para la cadena
    char* cadena = (char*)malloc(tamano + 1);
    if (cadena == NULL) {
        // Manejo de error si no se pudo asignar memoria
        return NULL;
    }

    // Formateamos la fecha en la cadena
    snprintf(cadena, tamano + 1, "%02d/%02d/%d", f->dia, f->mes, f->anio);

    return cadena;
};

/// PRIMITIVAS
int fecha_comparar(Fecha fA, Fecha fB){
    if(fA->anio < fB->anio){
        return -1; // A es anterior a B
    } else if(fA->anio > fB->anio){
        return 1; // A es posterior a B
    } else {
        // Mismo año, hay que comparar los meses
        if(fA->mes < fB->mes){
            return -1; // A es anterior a B
        } else if(fA->mes > fB->mes){
            return 1; // A es posterior a B
        } else {
            // Mismo año y mes, hay que comparar los días
            if(fA->dia < fB->dia){
                return -1; // A es anterior a B
            } else if(fA->dia > fB->dia){
                return 1; // A es posterior a B
            } else {
                return 0; // Las fechas son iguales
            }
        }
    }
};
Fecha fecha_sumar(Fecha f, int dias, int mes, int anio){    /// SIN HACER

};
int fecha_diasEntre(Fecha fA, Fecha fB){    /// SIN HACER

};

/// SETTERS
void fecha_setDia(Fecha f, int dia){
    if(!(dia < 1 || dia > 31)){
        f->dia = dia;
    }
};
void fecha_setMes(Fecha f, int mes){
    if(!(mes < 1 || mes > 12)){
        f->mes = mes;
    }
};
void fecha_setAnio(Fecha f, int anio){
    if(!(anio < 1)){
        f->anio = anio;
    }
};

/// GETTERS
int fecha_getDia(Fecha f){
    return f->dia;
};
int fecha_getMes(Fecha f){
    return f->mes;
};
int fecha_getAnio(Fecha f){
    return f->anio;
};
int fecha_getDiaSemana(Fecha f){
    return f->diaSemana;
};

// Funcion para determinar el dia de la semana utilizando el algoritmo de Zeller
DiaSemana determinarDiaDeLaSemana(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int K = year % 100;
    int J = year / 100;

    int dia_semana = (day + ((13 * (month + 1)) / 5) + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    switch (dia_semana) {
        case 0:
            return SABADO;
        case 1:
            return DOMINGO;
        case 2:
            return LUNES;
        case 3:
            return MARTES;
        case 4:
            return MIERCOLES;
        case 5:
            return JUEVES;
        case 6:
            return VIERNES;
    }
    //No entro al switch, igual imposible por congruencia
    return -1;
}

char* fecha_nombreDiaSemana(int num_dia) {
    switch (num_dia) {
        case 0:
            return "Domingo";
        case 1:
            return "Lunes";
        case 2:
            return "Martes";
        case 3:
            return "Miercoles";
        case 4:
            return "Jueves";
        case 5:
            return "Viernes";
        case 6:
            return "Sabado";
        default:
            return "Dia invalido";
    }
}


