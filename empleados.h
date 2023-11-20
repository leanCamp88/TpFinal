#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include "time.h"

typedef struct stEmpleado
{
    int dni;
    char ApellidoyNombre[40];
    char Usuario[20];
//    char contraseña[20];
    char perfil[20];

}stEmpleado;




/*
ESTRUCTURA EMPLEADOS
- carga de estructura
- modificacion datos


FUNCIONES EXTRA PEDIDAS

• Empleados de Laboratorio:
o Listado general de empleados ordenado por apellido y nombre.
o Consulta de 1 empleado en particular, filtrado por dni.
o Nota: solo en caso de estar logueado un usuario “administrador”, debe poder verse la
contraseña que usa el empleado para ingresar al sistema. Caso contrario mostrar
“*****” (asteriscos) como contraseña.

*/

#endif // EMPLEADOS_H_INCLUDED
