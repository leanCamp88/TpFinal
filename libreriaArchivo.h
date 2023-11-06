#ifndef LIBRERIAARCHIVO_H_INCLUDED
#define LIBRERIAARCHIVO_H_INCLUDED
#include "Pacientes.h"
#include "libreriaMPacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void guardarPacientesEnArchivo(nodoArbol *raiz, char nombrearchivo[]);
nodoArbol* cargarArboldeArreglo(patients arre[], nodoArbol* tree);
int cargarArregloPacientes(patients arre[],char nombrearchivo[]);

#endif // LIBRERIAARCHIVO_H_INCLUDED
