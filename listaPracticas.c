#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIVOSOLOPRACTICA "laspracticas.bin"


///1 Inicializa la lista

    nodoPracticas * inicListaPractica()
    {
        return NULL;
    }

///2 Funcion que crea un nuevo nodo Practicas

    nodoPracticas * crearNodoPractica(stPracticaxIngreso dato)
    {

        nodoPracticas* nodoNuevo = (nodoPracticas*) malloc(sizeof(nodoPracticas));

        nodoNuevo->practicasxIngreso = dato;
        nodoNuevo->siguiente = NULL;

        return nodoNuevo;
    }

///3 Agrego el final de la lista

nodoPracticas * agregoFinalListaPractica(nodoPracticas* listaPracticas, stPracticaxIngreso nuevo)
{
    nodoPracticas* ultimo;
    nodoPracticas * nuevoNodo=crearNodoPractica(nuevo);

    if(listaPracticas == NULL)
    {
        listaPracticas = nuevoNodo;
    }
    else
    {
        ultimo = buscaUltimoNodoPractica(listaPracticas);
        ultimo->siguiente = nuevoNodo;
    }

    return listaPracticas;
}

///4 Muestra una practica Ingreso

    void muestraUnaPracticaIngreso(nodoPracticas* practica)
    {
        printf("NRO ingreso %i", practica->NroIngreso);
        printf("Nombre de Practica: %s", practica->practica.nombreDePractica);
        printf("NRO practica %i", practica->practica.NroPractica);
        printf("RESULTADO: %s", practica->Resultado);
    }

///5 Carga de la estructura practica
///modificar con la estructura de stPracticaxIngreso!!!
stPracticaxIngreso cargaUnaPractica(int idIngreso,int nroPractica)
{
    stPracticas practica;
    stPracticaxIngreso ingreso;
    FILE*arch=fopen(ARCHIVOSOLOPRACTICA,"rb");
    if(arch)
    {
        while(fread(&practica,sizeof(stPracticas),1,arch)>0)
        {
            if(practica.NroPractica==nroPractica)
            {
                strcpy(ingreso.nombreDePractica,practica.nombreDePractica);
                ingreso.nroPractica=practica.NroPractica;
                strcpy(ingreso.resultado,"sin resultado");
                ingreso.nroIngreso=idIngreso;
            }
        }
    }
    return ingreso;
}

///6 Muestra lista

    void muestraListaPracticas(nodoPracticas* listaPracticas)
    {
        nodoPracticas* aux = listaPracticas;

        while(aux != NULL)
        {
            muestraUnaPractica(aux->practica);
            aux = aux->siguiente;
        }

    }

///7 Busca ultimo nodo

    nodoPracticas* buscaUltimoNodoPracticas(nodoPracticas* listaPracticas)
    {
        nodoPracticas* aux = listaPracticas;

        if(aux != NULL)
        {
            while(aux->siguiente != NULL)
            {
                aux = aux->siguiente;
            }
        }

        return aux;
    }


///8 Borrar lista

nodoPracticas* borraListaPracticas(nodoPracticas* listaPracticas)
{
    nodoPracticas* aux;

    while(listaPracticas != NULL)
    {
        aux = listaPracticas;
        listaPracticas = listaPracticas->siguiente;
        free(aux);
    }

    return listaPracticas;
}

/// 9 Buscar un nodo de practica
nodoPracticas* buscarNodoPractica(nodoPracticas* listaPracticas, int id)
{

}

///10 Lee el archivo y carga la lista

nodoPracticas * cargaListaPracticas (nodoPracticas * listaPractica, int idIngreso)
{
    FILE * arch = fopen(ARCHIVOPRACTICASXINGRESO, "rb");
    stPracticaxIngreso ingresoPractica;

    if(arch != NULL)
    {
        while(fread(&ingresoPractica,sizeof(stPracticaxIngreso),1,arch)>0) //borrar los datos?
        {
            if(idIngreso == ingresoPractica.nroIngreso)
            {
                listaPractica = agregoFinalListaPractica(listaPractica,crearNodoPractica(ingresoPractica));
            }
        }
    }
    fclose(arch);
    return listaPractica;
}

///11 Carga el archivo con los datos de la lista recibida por paremetro

void cargarArchivoIngresosPracticas (nodoPracticas * listaPracticas, char nombreArchivo) //funcion que recorra el arbol y llame a esta funcion en cada raiz->punterolista
{
    FILE * arch = fopen(nombreArchivo, "wb"); //borra y reescribe

    while(listaPracticas != NULL)
    {
        stPracticas practica = listaPracticas->dato;
        fwrite(&practica,sizeof(stPracticas),1,arch);
        listaPracticas = listaPracticas->siguiente;
    }

    fclose(arch);
}
