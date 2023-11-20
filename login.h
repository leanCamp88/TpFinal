#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>

#define archivoCuentas "archivoCuentas.dat"

#define ESC 27
#define DIM 30
#include "time.h"
// Definición de estructuras
typedef struct
{
    int dni;
    char apellidoYNombre[40];
    char usuario[20];
    char contrasenia[20];
    char perfil[20];
    int eliminado;
} Empleado;

int login();
int modificarEmpleado(int esAdmin);
void bajaEmpleado(Empleado darBaja);
void altaEmpleado();
int listarEmpleados(int esAdmin);
Empleado* redimensionar(Empleado *arreglo,int *capacidad, size_t nuevo_tamano);
int comparar_apellidos(const void *a, const void *b);
void muestraEmpleados(Empleado arregloEmpleados[],int validos);
void muestraEmpleadosAdmin(Empleado arregloEmpleados[],int validos);
void muestraUnEmpleadoAdmin(Empleado muestraEmpleado);
void muestraUnEmpleado(Empleado muestraEmpleado);
Empleado buscarCuenta(int dni);
void ocultarPassword(char password[DIM]);


#define DIM 30

#endif // LOGIN_H_INCLUDED
