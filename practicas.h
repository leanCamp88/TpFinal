#ifndef PRACTICAS_H_INCLUDED
#define PRACTICAS_H_INCLUDED
#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"
#include "fecha.h"
#include "time.h"
#include <unistd.h>


typedef struct stPractica
{
    int nroPractica;
    char nombrePractica[30];
    int eliminado;
}stPractica;

int cargarPracticaArreglo(int validos);
void muestraPracticasDisponibles(stPractica arregloPracticas[], int validos);
stPractica buscaPracticaNombre();
int buscaPracticaDisponile(); //de verificacion

void levantarSistema();
stPractica* redimensionarPracticas(stPractica *arreglo,int *capacidad, size_t nuevo_tamano);
int comparar(const void *a, const void *b);
void levantarArchivoArreglosPracticas(stPractica* practicas,int* capacidad,int* validos);
void guardarCambiosArregloPracticas(stPractica practicas[],int validos);
void mostrarPracticas(stPractica practicas[],int validos);
int verificarID(stPractica practicas[],int validos);
void modificacionPractica(stPractica practicas[],int validos);
void muestraUnaPractica(stPractica practica);
void mostrarPorNombrePracticas(stPractica practicas[],int validos);
void mostrarPractica(stPractica practica);
void cambiarEstadoPractica(stPractica* practicas,int validos);


void mostrarPracticaPorNumero(int nmroPractica);
stPractica devuelvePractica(int nroPractica);


/*
ESTRUCTURA PRACTICA

- carga de estructura
- modificacion datos
- muestra estructura
- muestra del archivo completo

FUNCIONES EXTRA PEDIDAS

Listado general de practicas de laboratorio ordenadas por nombre.

    o Listado de practicas que “comiencen con”. En este caso debe poder filtrar todas las
practicas cuyo nombre comiencen con lo seleccionado por el usuario. Ejemplo: si se
elige la combinación “he”, deberían mostrarse practicas como: “hemograma o
hepatograma” etc.


void mostrarPracticas(char archivo []);
void modificacionPractica(char archivo[]);
int buscarporNombrePracticas(char archivo []);
void mostrarPractica(Practicas practica);
void baja_alta_practica(char archivo[]);
*/


#endif // PRACTICAS_H_INCLUDED
