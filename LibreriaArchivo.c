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
        printf("Flagggg");
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


int cargarArregloPacientes(sT_Paciente arre[],char nombrearchivo[])
{
    FILE*arch=fopen(nombrearchivo,"rb");
    sT_Paciente pers;
    int i=0;
    if(arch==NULL)
    {
        printf("Error al abrir el archivo");
    }
    else
    {
        while(fread(&pers,sizeof(sT_Paciente),1,arch)>0)
        {
            arre[i]=pers;
            i++;
        }
    }
    fclose(arch);
    return i;
}

arbolPaciente* cargarArboldeArreglo(sT_Paciente arre[], arbolPaciente* tree)
{

    int i=0;
    if(tree==NULL)
    {
        tree->pers=arre[i];
    }
    else///Se me rompe aca y no se porque, no me entra
    {
        printf("Flaggggg");        if(tree->pers.DNI<arre[i].DNI)
        {
            tree->Izq=cargarArboldeArreglo(arre+1,tree);
        }else
        {
            tree->Der=cargarArboldeArreglo(arre+1,tree);
        }
    }
    return tree;
}
