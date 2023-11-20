#include <stdio.h>
#include <stdlib.h>

#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"
#include "time.h"


///FUNCION CARGAR SISTEMA

int CANT_PRACTICAS;

int main()
{

//    int * idMax = 0;
//
//
//    nodoPaciente * pacientes = inicArbol();
//
//    //pacientes = cargarArbolPacientes(pacientes,"archivoPacientes.bin");
//
//    pacientes = agregaPaciente(pacientes, cargaPaciente(42042285));
//
//    pacientes = agregaPaciente(pacientes, cargaPaciente(42042280));
//
//
//    muestraArbol(pacientes);
//
//    cargarArchivoPacientes(pacientes, "archivoPacientes.bin");



    int capacidad = 645;

    stPractica* arregloPracticas = (stPractica*)malloc(sizeof(stPractica) * (capacidad));

    int validos = 0;

    levantarArchivoArreglosPracticas(arregloPracticas,&capacidad,&validos);

    nodoPaciente* arbolPacientes = inicArbol();

    menuPrincipal(arbolPacientes,arregloPracticas,validos);




    return 0;
}
