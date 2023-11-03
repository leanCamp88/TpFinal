#ifndef LIBRERIAARCHIVO_H_INCLUDED
#define LIBRERIAARCHIVO_H_INCLUDED
#include "Pacientes.h"
#include "libreriaMPacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void guardarPacientesEnArchivo(arbolPaciente *raiz, char nombrearchivo[]);
arbolPaciente* cargarArboldeArreglo(sT_Paciente arre[], arbolPaciente* tree);
int cargarArregloPacientes(sT_Paciente arre[],char nombrearchivo[]);

#endif // LIBRERIAARCHIVO_H_INCLUDED
