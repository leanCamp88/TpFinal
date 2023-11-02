#include "Pacientes.h"
#include "libreriaMPacient.h"
#include "libreriaArchivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



void guardarPacientesEnArchivo(arbolPaciente * raiz,char nombrearchivo[])
{
    FILE*arch=fopen(nombrearchivo,"ab");
    if(arch==NULL)
    {
        printf("Error al abrir el archivo");
    }
    else
    {
        if(raiz)
        {
            sT_Paciente dato=raiz->pers;
            fwrite(&dato,sizeof(sT_Paciente),1,arch);
            fclose(arch);
            guardarPacientesEnArchivo(raiz->Izq,nombrearchivo);
            guardarPacientesEnArchivo(raiz->Der, nombrearchivo);
        }
    }
}


arbolPaciente *cargarArbolDesdeArchivo(char nombrearchivo[])
{
    FILE*arch=fopen(nombrearchivo,"rb");
   arbolPaciente*nuevoNodo=inicarbol();
    sT_Paciente paciente;
    if(arch==NULL)
    {
        printf("Error al abrir el archivo");
    }
    else
    {
        if(fread(&paciente,sizeof(sT_Paciente),1,arch)>0)
        {

                nuevoNodo = (arbolPaciente *)malloc(sizeof(arbolPaciente));
                nuevoNodo->pers = paciente;
                nuevoNodo->Izq = cargarArbolDesdeArchivo(nombrearchivo);
                nuevoNodo->Der = cargarArbolDesdeArchivo(nombrearchivo);
            }
        }
    return nuevoNodo;

    }
