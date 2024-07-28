#include <stdio.h>
#include <stdlib.h>

#include "fecha.h"

int main()
{
    Fecha f1 = fecha_crear(30,5,2002);
    printf("%s ", fecha_nombreDiaSemana(fecha_getDiaSemana(f1)));
    fecha_mostrar(f1);


    Fecha f2 = fecha_crear(11,8,1997);
    printf("%s ", fecha_nombreDiaSemana(fecha_getDiaSemana(f2)));
    fecha_mostrar(f2);

    Fecha f3 = fecha_crear(16,8,1997);
    printf("%s ", fecha_nombreDiaSemana(fecha_getDiaSemana(f3)));
    fecha_mostrar(f3);

    printf("\nComparar %s con %s: %d\n", fecha_toString(f2), fecha_toString(f1), fecha_comparar(f2,f1));

    return 0;
}
