#include "Pacientes.h"
#include "libreriaMPacient.h"
#include "libreriaArchivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void pasar_de_arbol_al_archivo(nodoArbol*lista)
{
    FILE*archi=fopen("ArchivoDePacientes.dat","ab");
    if(archi==NULL)
    {
        printf("\nError al abrir el archivo\n");
        return(1);
    }
       else if(lista!=NULL)
        {
            patients paciente=lista->pers;
            fwrite(&paciente,sizeof(patients),1,archi);
        }
        fclose(archi);
}


nodoArbol* cargar_arbol(nodoArbol*lista)
{
    FILE*archi=fopen("ArchivoDePacientes.dat","ab");
    if(archi==NULL)
    {
        printf("\nError al abrir el archivo\n");
        return(1);
    }
    else
    {
        patients paciente;
        while(fread(&paciente,sizeof(patients),1,archi)>0)
        {
            lista=getIntoTree(lista,paciente);
        }
    }
    fclose(archi);
    return lista;
}


int cargarArregloPacientes(patients arre[],char nombrearchivo[])
{
    FILE*arch=fopen(nombrearchivo,"rb");
    patients pers;
    int i=0;
    if(arch==NULL)
    {
        printf("Error al abrir el archivo");
    }
    else
    {
        while(fread(&pers,sizeof(patients),1,arch)>0)
        {
            arre[i]=pers;
            i++;
        }
    }
    fclose(arch);
    return i;
}



nodoArbol* cargarArboldeArreglo(patients arre[], nodoArbol* tree)
{

    int i=0;
    if(tree==NULL)
    {
        tree->pers=arre[i];

    }
    else///Se me rompe aca y no se porque, no me entra
    {
        printf("Flaggggg");
        if(tree->pers.DNI<arre[i].DNI)
        {
            tree->Izq=cargarArboldeArreglo(arre,tree);
        }
        else
        {
            tree->Der=cargarArboldeArreglo(arre,tree);
        }
    }
    return tree;
}
