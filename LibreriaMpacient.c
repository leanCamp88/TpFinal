#include "Pacientes.h"
#include "libreriaMPacient.h"
#include "libreriaArchivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define nombrearchivo "archivopacientes.dat"
#define DIM 50
#define ESC 27


void menuPaciente()
{

        nodoArbol*tree=inicarbol();
    int menu = 0;
    while(menu!=27)
    {
        system("cls");
        printf("\t Menu de Pacientes\n");
        printf("\n1- Alta de Pacientes\n");
        printf("\n2- Modificacion de Pacientes\n");
        printf("\n3- Baja de Pacientes\n");
        printf("\n4- Muesta listado de paciente\n");
        printf("ESC para salir, cualquier otra tecla para continuar...");

        menu=getch();

        switch(menu)
        {
        case '1':
            system("cls");
           tree=alta_de_Paciente(tree);
            break;
        case '2':
            system("cls");
            tree=modificarPaciente(tree);
            break;
        case '3':
            printf("\nEn construccion\n");
            break;
        case '4':
            system("cls");
            muestraListado(tree);
            break;
        default:
            printf("\nPorfavor vuelva a seleccionar una opcion valida\n");
            break;
        }
    }
}


void muestraListado(nodoArbol*tree)
{
    mostrarArbol(tree);
    getch();
}
