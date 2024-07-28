#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "curso.h"

struct Curso{
    char nombre[20];
    ListaPtr estudiantes;
};

/// CONSTRUCTOR
CursoPtr curso_crear(char nombre[20]){
    CursoPtr curso = (CursoPtr)malloc(sizeof(struct Curso));
    strcpy(curso->nombre, nombre);
    curso->estudiantes = lista_crear();
    return curso;
};

/// DESTRUCTOR
void curso_destruir(CursoPtr curso){
    lista_liberar(curso->estudiantes);
    free(curso);
};

/// MOSTRAR
void curso_mostrar(CursoPtr curso){
    printf("\nCurso: %s\n", curso->nombre);
    lista_mostrar(curso->estudiantes, persona_mostrar_ptr);
};

/// PRIMITIVAS
void curso_nuevo_estudiante(CursoPtr curso, PersonaPtr estudiante){
    if(lista_buscar(curso->estudiantes, estudiante, curso_estudiantes_comparar_dni) == NULL){
        lista_insertar_ultimo(curso->estudiantes, estudiante);
        printf("\nRegistrado");
    } else {
        printf("\nDNI Duplicado");
    }
};
PersonaPtr curso_eliminar_estudiante_dni(CursoPtr curso, int dni){
    PersonaPtr estudiante = persona_crear(dni,"","");
    PersonaPtr estudianteEliminado = NULL;
    if(lista_buscar(curso->estudiantes, &estudiante, curso_estudiantes_comparar_dni) != NULL){
        estudianteEliminado = *(PersonaPtr*)(lista_eliminar_coincidencia(curso->estudiantes, &estudiante, curso_estudiantes_comparar_dni));
        persona_destruir(estudiante);
        return estudianteEliminado;
    } else {
        persona_destruir(estudiante);
        return estudianteEliminado;
    }
};

/// OTROS
int curso_estudiantes_comparar_dni(DatoPtr a, DatoPtr b){
    PersonaPtr pA = *(PersonaPtr*)a;
    PersonaPtr pB = *(PersonaPtr*)b;
    return persona_comparar_dni(pA, pB);
}
void curso_estudiantes_ordenarPor_dni(CursoPtr curso){
    lista_ordenar(curso->estudiantes, curso_estudiantes_comparar_dni);
};

/// SETTERS

/// GETTERS
