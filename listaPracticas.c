#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"

#define ESC 27

extern int IDGLOBAL;

///1 Inicializa la lista

nodoPracticas * inicListaPractica()
{
    return NULL;
}

///2 Funcion que crea un nuevo nodo Practicas

nodoPracticas * crearNodoPractica(stPracxIngreso dato)
{

    nodoPracticas * nodoNuevo = (nodoPracticas*) malloc(sizeof(nodoPracticas));

    nodoNuevo->practica = dato;
    nodoNuevo->siguiente = NULL;

    return nodoNuevo;
}

///7 Busca ultimo nodo

nodoPracticas * buscaUltimoNodoPractica(nodoPracticas * listaPracticas)
{
    nodoPracticas * aux = listaPracticas;

    if(aux != NULL)
    {
        while(aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
    }

    return aux;
}

///3 Agrego el final de la lista

nodoPracticas * agregoFinalListaPractica(nodoPracticas* listaPracticas,stPracxIngreso nuevo)
{
    nodoPracticas * ultimo;
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
    printf("NRO ingreso %i", practica.nroIngreso);
    printf("NRO practica %i", practica.NroPractica);
    printf("RESULTADO: %s", practica.Resultado);
}

///5 Carga de practicas hasta que quiera el usuario

nodoPracticas * cargaPracticas(int idIngreso,nodoPracticas * listaPracticas,stPractica* practicas,int validos) //stPractica arregloPracticas[], int * validos (parametros que va a necesitar para verificaciones
{
    char opc = 0;
    int nroPractica = 0;
    stPracxIngreso practicaIngreso;

    mostrarPorNombrePracticas(practicas,validos);


    system("pause");
    int id = verificarID(practicas,validos);

    while(opc != ESC)
    {
        if(id)
        {
            IDGLOBAL++;

            practicaIngreso.nroIngreso = IDGLOBAL;
            practicaIngreso.NroPractica = id;
            strcpy(practicaIngreso.Resultado,"Sin Resultados");
        }

        listaPracticas = agregoFinalListaPractica(listaPracticas,practicaIngreso);

        printf("Cualquiera para continuar cargando practicas o ESC para salir /n");

        fflush(stdin);

        opc = getchar();
    }

return listaPracticas;
}



///6 Muestra lista

void muestraListaPracticas(nodoPracticas* listaPracticas)
{
    nodoPracticas * aux = listaPracticas;

    while(aux != NULL)
    {
        muestraUnaPracticaIngreso(aux->practica);
        aux = aux->siguiente;
    }

}


///8 Borrar lista

nodoPracticas * borraListaPracticas(nodoPracticas * listaPracticas)
{
    nodoPracticas * aux;

    while(listaPracticas != NULL)
    {
        aux = listaPracticas;
        listaPracticas = listaPracticas->siguiente;
        free(aux);
    }

    return listaPracticas;
}

///10 Lee el archivo y carga la lista


nodoPracticas * cargaListaPracticas(nodoPracticas * listaPractica, int idIngreso)
{
    FILE * arch = fopen(ARCHIVOPRACTICASXINGRESO, "rb");

    stPracxIngreso practicaIngreso;

    if(arch)
    {
        while(fread(&practicaIngreso,sizeof(stPracxIngreso),1,arch) > 0) //borrar los datos?
        {
            if(idIngreso == practicaIngreso.nroIngreso)
            {
                listaPractica = agregoFinalListaPractica(listaPractica,practicaIngreso);
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
        stPracxIngreso practica = listaPracticas->practica;
        fwrite(&practica,sizeof(stPracxIngreso),1,arch);
        listaPracticas = listaPracticas->siguiente;
    }

    fclose(arch);
}



