#include "Pacientes.h"
#include "libreriaMPacient.h"
#include "libreriaArchivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



///Iniciar un Arbol
nodoArbol*inicarbol()
{
    return NULL;
}



///Crear un nuevo nodo raiz de tipo arbol de paciente

nodoArbol * createPatient(patients pers)
{

    nodoArbol*aux=(nodoArbol*)malloc(sizeof(nodoArbol));
    strcpy(aux->pers.AyN,pers.AyN);
    strcpy(aux->pers.Domicilio,pers.Domicilio);
    aux->pers.DNI=pers.DNI;
    aux->pers.Edad=pers.Edad;
    aux->pers.Eliminado=pers.Eliminado;
    strcpy(aux->pers.Telefono,pers.Telefono);

    aux->Der=inicarbol();
    aux->Izq=inicarbol();
    return aux;
}

///Insertar un nuevo nodo raiz de tipo arbol de paciente

nodoArbol* getIntoTree (nodoArbol*tree,patients neew)
{
    if(tree==NULL)
    {
        tree=createPatient(neew);
    }
    else
    {
        if(neew.DNI<tree->pers.DNI)
        {
            tree->Izq=getIntoTree(tree->Izq,neew);
        }
        else
        {
            tree->Der=getIntoTree(tree->Der,neew);
        }
    }
    return tree;
}

///Buscar un nodo raiz de tipo arbol de paciente

nodoArbol * buscar(nodoArbol*arbol, int dato)
{
    nodoArbol * buscado=inicarbol();
    if(arbol)
    {

        if(arbol->pers.DNI==dato)
        {
            buscado=arbol;
        }
        else
        {
            if(dato<arbol->pers.DNI)
            {
                buscado=buscar(arbol->Izq, dato);
            }
            else
            {
                buscado=buscar(arbol->Der,dato);
            }
        }
    }
    return buscado ;
}

///Cambiar estado de paciente

int onOffPatient()
{
    int estado=0;
    char opc;
    printf("Desea eliminar al paciente?");
    fflush(stdin);
    gets(&opc);
    if(opc=='s'||opc=='S')
    {
        estado=1;
    }
    return estado;
}

///Crear un nuevo paciente de tipo paciente

patients newPatient()
{
    patients aux;
    printf("\nIngrese Apellido y Nombre\n");
    fflush(stdin);
    gets(aux.AyN);
//
//    printf("\nDomicilio: \n");
//    fflush(stdin);
//    gets(&aux.Domicilio);

    printf("\nIngrese DNI\n");
    scanf("%d",&aux.DNI);
//
//    printf("\nIngrese Edad\n");
//    scanf("%d", &aux.Edad);
//
//    printf("\nIngrese Telefono de Contacto\n");
//    fflush(stdin);
//    gets(&aux.Telefono);


    aux.Eliminado=0;
    return aux;
}

///Crear un alta de paciente, en un nodo raiz de tipo arbol de paciente

nodoArbol* alta_de_Paciente(nodoArbol*tree)
{
    int flag=0;
    while(flag==0)
    {
        patients aux=newPatient();
        nodoArbol*buscado=buscar(tree,aux.DNI);
        if(buscado==NULL)
        {
            tree=getIntoTree(tree,aux);
        }
        else
        {
            char opc;
            printf("Paciente ya ingresado anteriormente\nDesea darlo de alta nuevamente?\n");
            fflush(stdin);
            gets(&opc);
            if(opc=='s'||opc=='S')
            {
                buscado->pers.Eliminado=onOffPatient();
            }
        }

        printf("Desea cargar otro Paciente? S/N \n");
        char opc;
        fflush(stdin);
        gets(&opc);
        if(opc=='s'||opc=='S')
            flag=0;
        else
        {
            flag=1;
        }
    }

    return tree;

}


nodoArbol * modificarPaciente (nodoArbol*tree)
{
    int dato=0;
    printf("Ingrese DNI del paciente a modificar sin puntos\n");
    scanf("%d", &dato);
    nodoArbol*aux=inicarbol();
    aux=buscar(tree,dato);
    if(aux==NULL)
    {
        printf("No se encontraron pacientes con ese DNI\n");
    }
    else
    {
        printf("Ingrese nuevamente los datos\n");
        aux->pers=newPatient();
    }

    return tree;
}


void mostrarPaciente(nodoArbol* tree)
{
    printf("--------------------------------------------------------------------------------\n");
    printf("\nApellido y nombre: %s",tree->pers.AyN);
//    printf("\nDomicilio: %s\n",tree->pers.Domicilio);
    printf("\nDNI: %i\n",tree->pers.DNI);
//    printf("\nEdad: %i\n",tree->pers.Edad);
//    printf("\nTelefono: %s\n",tree->pers.Telefono);
//    if(tree->pers.Eliminado==0)
//        printf("\nEstado: Activo\n");
//    else
//        printf("\nEstado: Inactivo\n");

}

void mostrarArbol(nodoArbol*tree)
{
    if(tree)
    {
        mostrarPaciente(tree);
        mostrarArbol(tree->Izq);
        mostrarArbol(tree->Der);
    }
}

