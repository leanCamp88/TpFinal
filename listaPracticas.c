#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"


///1 Inicializa la lista

    nodoIngresos * inicListaPractica()
    {
        return NULL;
    }

///2 Funcion que crea un nuevo nodo Practicas

    nodoPracticas * crearNodoPractica(stPracxIngreso dato)
    {

        nodoPracticas* nodoNuevo = (nodoPracticas*) malloc(sizeof(nodoPracticas));

        nodoNuevo->practica = dato;
        nodoNuevo->siguiente = NULL;

        return nodoNuevo;
    }

///3 Agrego el final de la lista

nodoPractica* agregoFinalListaPractica(nodoPracticas* listaPracticas, nodoPracticas* nuevoNodo);
{
    nodoPracticas* ultimo;
    nodoPracticas * nuevoNodo;
    nuevoNodo = crearNodoPractica(nuevo);

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

    void muestraUnaPracticaIngreso(stPracxIngreso practica)
    {
        printf("NRO ingreso %i", practica.NroIngreso);
        printf("NRO practica %i", practica.NroPractica);
        printf("RESULTADO: %s", practica.Resultado);
    }

///5 Carga de la estructura practica

stPracxIngreso cargaUnaPractica(int idIngreso){

    stPracxIngreso practica;
    nodoPracticas * ultimo = buscaUltimoID(archivoPracticasxIngresos); //funcion que busca mayor id en el archivo

    practica.nroIngreso = idIngreso;
    practica.NroPractica = buscarPractica(archivoPracticas); //libreria practicas
    strcpy(practica.Resultado,""); //resultado en vacio;}

    return practica;
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

nodoPracticas * cargaListaIngresos (char nombreArchivo[], nodoPracticas * listaPractica, int idIngreso)
{
    FILE * arch = fopen(nombreArchivo, "rb");
    stPracxIngreso ingresoPractica;

    if(arch != NULL)
    {
        while(fread(&ingresoPractica,sizeof(stPracxIngreso),1,arch)>0) //borrar los datos?
        {
            if(idIngreso == ingresoPractica.NroIngreso)
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
        stPracxIngreso practica = listaPracticas->dato;
        fwrite(&practica,sizeof(stPracxIngreso),1,arch);
        listaPracticas = listaPracticas->siguiente;
    }

    fclose(arch);
}
