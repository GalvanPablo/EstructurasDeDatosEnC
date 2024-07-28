#ifndef CURSO_H_INCLUDED
#define CURSO_H_INCLUDED

#include "lista.h"
#include "persona.h"

struct Curso;
typedef struct Curso * CursoPtr;

/// CONSTRUCTOR
CursoPtr curso_crear(char nombre[20]);

/// DESTRUCTOR
void curso_destruir(CursoPtr curso);

/// MOSTRAR
void curso_mostrar(CursoPtr curso);

/// PRIMITIVAS
void curso_nuevo_estudiante(CursoPtr curso, PersonaPtr estudiante);
PersonaPtr curso_eliminar_estudiante_dni(CursoPtr curso, int dni);

/// OTROS
int curso_estudiantes_comparar_dni(DatoPtr a, DatoPtr b);

/// SETTERS

/// GETTERS

#endif // CURSO_H_INCLUDED
