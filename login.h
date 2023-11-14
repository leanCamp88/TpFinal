#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED


#include <string.h>

#define archivoCuentas "archivoCuentas.dat"
#define ESC 27

// Definición de estructuras
typedef struct
{
    int dni;
    char apellidoYNombre[30];
    char usuario[20];
    char contrasenia[20];
    char perfil[20];
} Empleado;


#define DIM 30


#endif // LOGIN_H_INCLUDED
