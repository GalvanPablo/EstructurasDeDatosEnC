#include <stdio.h>
#include <stdlib.h>

#include "curso.h"
#include "persona.h"

#include "lista.h"

int main()
{
    CursoPtr curso = curso_crear("AYED");

    PersonaPtr p1 = persona_crear(44256447, "Galvan", "Pablo");
    curso_nuevo_estudiante(curso, &p1);

    PersonaPtr p2 = persona_crear(40621987, "Galvan", "Emiliano");
    curso_nuevo_estudiante(curso, &p2);

    PersonaPtr p3 = persona_crear(14326762, "Perez", "Fernando");
    curso_nuevo_estudiante(curso, &p3);

    PersonaPtr p4 = persona_crear(14326762, "Pereira", "Fernando");
    curso_nuevo_estudiante(curso, &p4);

    printf("\n");
    curso_mostrar(curso);

    printf("## ORDENAR");
    curso_estudiantes_ordenarPor_dni(curso);

    printf("\n");
    curso_mostrar(curso);

    printf("## Eliminar a: ");
    persona_mostrar(curso_eliminar_estudiante_dni(curso, 40621987));
    printf("\n");
    curso_mostrar(curso);

    return 0;
}
