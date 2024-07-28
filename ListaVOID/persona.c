#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"

struct Persona{
    int dni;
    char apellido[20];
    char nombre[15];
};

/// CONSTRUCTOR
PersonaPtr persona_crear(int dni, char apellido[20], char nombre[15]){
    PersonaPtr p = (PersonaPtr)malloc(sizeof(struct Persona));
    p->dni = dni;
    strcpy(p->apellido, apellido);
    strcpy(p->nombre, nombre);

    return p;
};

/// DESTRUCTOR
void persona_destruir(PersonaPtr p){
    free(p);
};

/// MOSTRAR
void persona_mostrar(PersonaPtr p){
    if(p == NULL){
        printf("{}");
        return;
    }
    printf("{dni: %d, apellido: %s, nombre: %s}\n", p->dni, p->apellido, p->nombre);
};
void persona_mostrar_ptr(void* dato){
    PersonaPtr p = *(PersonaPtr*)(dato);
    persona_mostrar(p);
};

/// PRIMITIVAS
int persona_comparar_dni(PersonaPtr a, PersonaPtr b){
    if(a->dni < b->dni){
        return -1;
    } else if(a->dni > b->dni){
        return 1;
    } else {
        return 0;
    }
};
int persona_comparar_apellido(PersonaPtr a, PersonaPtr b){
    return strcmp(a->apellido, b->apellido);
};
int persona_comparar_nombre(PersonaPtr a, PersonaPtr b){
    return strcmp(a->nombre, b->nombre);
};

/// SETTERS
void persona_setDNI(PersonaPtr p, int dni){
    p->dni = dni;
};
void persona_setApellido(PersonaPtr p, char apellido[20]){
    strcpy(p->apellido, apellido);
};
void persona_setNombre(PersonaPtr p, char nombre[15]){
    strcpy(p->nombre, nombre);
};

/// GETTERS
int persona_getDNI(PersonaPtr p){
    return p->dni;
};
char* persona_getApellido(PersonaPtr p){
    return p->apellido;
};
char* persona_getNombre(PersonaPtr p){
    return p->nombre;
};
