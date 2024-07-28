#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct Persona;
typedef struct Persona * PersonaPtr;

/// CONSTRUCTOR
PersonaPtr persona_crear(int dni, char apellido[20], char nombre[15]);

/// DESTRUCTOR
void persona_destruir(PersonaPtr p);

/// MOSTRAR
void persona_mostrar(PersonaPtr p);
void persona_mostrar_ptr(void* dato);

/// PRIMITIVAS
int persona_comparar_dni(PersonaPtr a, PersonaPtr b);
int persona_comparar_apellido(PersonaPtr a, PersonaPtr b);
int persona_comparar_nombre(PersonaPtr a, PersonaPtr b);

/// SETTERS
void persona_setDNI(PersonaPtr p, int dni);
void persona_setApellido(PersonaPtr p, char apellido[20]);
void persona_setNombre(PersonaPtr p, char nombre[15]);

/// GETTERS
int persona_getDNI(PersonaPtr p);
char* persona_getApellido(PersonaPtr p);
char* persona_getNombre(PersonaPtr p);

#endif // PERSONA_H_INCLUDED
