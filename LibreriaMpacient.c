#include "Pacientes.h"
#include "libreriaMPacient.h"
#include "libreriaArchivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define nombrearchivo "archivopacientes.dat"
#define DIM 50


void menuPaciente()
{

    printf("\t Menu de Pacientes\n");
    printf("\n1- Alta de Pacientes\n");
    printf("\n2- Modificacion de Pacientes\n");
    printf("\n3- Baja de Pacientes\n");
    printf("\n4- Muesta listado de paciente\n");
    int menu = 0;
    menu=getch();

    switch(menu)
    {
    case '1':
        system("cls");
        altaPaciente();
        break;
    case '2':
        printf("\nEn construccion\n");
        break;
    case '3':
        printf("\nEn construccion\n");
        break;
         case '4':
        system("cls");
        muestraListado();
        break;
    default:
        printf("\nPorfavor vuelva a seleccionar una opcion valida\n");
        break;

    }


}




void altaPaciente()
{
    arbolPaciente*tree;
    tree=inicarbol();
    int val=0;
    sT_Paciente arre[DIM];
    val=cargarArregloPacientes(arre,nombrearchivo);
    tree=cargarArboldeArreglo(arre,tree);

    tree=alta_de_Paciente(tree,nombrearchivo);

}
 void muestraListado()
 {
     int val=0;
     sT_Paciente arre[DIM];
     arbolPaciente*tree=inicarbol();
     val=cargarArregloPacientes(arre,nombrearchivo);
     tree=cargarArboldeArreglo(arre,tree);
     mostrarPaciente(tree);
    }
