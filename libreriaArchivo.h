#ifndef LIBRERIAARCHIVO_H_INCLUDED
#define LIBRERIAARCHIVO_H_INCLUDED
#include "Pacientes.h"
#include "libreriaMPacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

nodoArbol* cargarArboldeArreglo(patients arre[], nodoArbol* tree);
int cargarArregloPacientes(patients arre[],char nombrearchivo[]);
void pasar_de_arbol_al_archivo(nodoArbol*lista);
nodoArbol* cargar_arbol(nodoArbol*lista);

#endif // LIBRERIAARCHIVO_H_INCLUDED
