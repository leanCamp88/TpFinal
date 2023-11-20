#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "time.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}stFecha;

stFecha cargarFecha();
stFecha obtenerFechaActual();
int verificarFechaFutura(stFecha fechaIngresada);
int esBisiesto(int anio);
int verificarFecha(stFecha fecha, stFecha fechaActual);
stFecha ingresarFecha();

#endif // FECHA_H_INCLUDED
