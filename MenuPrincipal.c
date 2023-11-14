#include "Pacientes.h"
#include "libreriaMPacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "listaIngresos.h"
#define nombrearchivo "archivopacientes.dat"


void menuPrincipal()
{
    printf("\t\tBienvenido a la Clinica de Laboraorios Clinicos\n");

    int opc=0;
    printf("1- Analisis Clinicos\n");
    printf("2- Pacientes\n");
    printf("3- Practicas\n");

    switch(opc)
    {
    case '1':

        break;

    }
}

void menuIngresos()
{
    nodoArbol*tree;

    printf("Seleccione una opcion\n");
    printf("1-Alta de Ingresos\n");
    printf("2-Mostrar Ingresos\n");
    printf("3-Modificar Ingresos\n");

    int opc=0;

    switch(opc)
    {
    case '1':
        printf("Ingrese Dni: \n");
        int dni=0;
        scanf("%d", &dni);
        tree=buscar(tree,dni);
        if(tree==NULL)
        {
            tree=getIntoTree(tree,newPatient());
            tree->ingreso=agregoFinalListaIngresos(tree->ingreso,cargaIngreso(tree->ingreso));
        }
        break;
    case '2':
        break;
    case '3':
        break;
    default:
        break;
    }

}
