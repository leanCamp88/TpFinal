#include "listaIngresos.h"
#include <stdio.h>
#include <stdlib.h>
///1 Inicializa la lista

    nodoIngresos * inicLista()
    {
        return NULL;
    }

///2 Funcion que crea un nuevo nodo Ingreso

    nodoIngresos * crearNodo(stIngresos dato)
    {

        nodoIngresos* nodoNuevo = (nodoIngresos*) malloc(sizeof(nodoIngresos));

        nodoNuevo->dato = dato;
        nodoNuevo->siguiente = NULL;
        //nodoNuevo->practicas = inicLista();

        return nodoNuevo;
    }

///3 Funcion que agrega datos a la lista desde el principio

    nodoIngresos* agregarPrincipioLista(nodoIngresos* listaIngresos ,nodoIngresos * nodoNuevo)
    {

        if(listaIngresos == NULL)
        {
            listaIngresos = nodoNuevo;
        }
        else
        {
            nodoNuevo->siguiente = listaIngresos;
            listaIngresos = nodoNuevo;
        }

        return listaIngresos;
    }

///4 Muestra un nodo

    void muestraUnNodo(nodoIngresos* nodo)
    {
        muestraIngreso(nodo->dato);
    }

///5 Agrego el final de la lista

nodoIngresos* agregoFinalListaIngresos(nodoIngresos* listaIngresos, stIngresos nuevo)
{
    nodoIngresos* ultimo;
    nodoIngresos * nuevoNodo;
    nuevoNodo = crearNodo(nuevo);

    if(listaIngresos == NULL)
    {
        listaIngresos = nuevoNodo;
    }
    else
    {
        ultimo = buscaUltimoNodoIngresos(listaIngresos);
        ultimo->siguiente = nuevoNodo;
    }

    return listaIngresos;
}

///6 Muestra lista

    void muestraListaIngresos(nodoIngresos* listaIngresos)
    {
        nodoIngresos* aux = listaIngresos;

        while(aux != NULL)
        {
            muestraUnNodo(aux);
            aux = aux->siguiente;
        }

    }

///7 Busca ultimo nodo

    nodoIngresos* buscaUltimoNodoIngresos(nodoIngresos* listaIngresos)
    {
        nodoIngresos* aux = listaIngresos;

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

nodoIngresos* borraLista(nodoIngresos* listaIngresos)
{
    nodoIngresos* aux;

    while(listaIngresos != NULL)
    {
        aux = listaIngresos;
        listaIngresos = listaIngresos->siguiente;
        free(aux);
    }

    return listaIngresos;
}

///9 Lee el archivo y carga la lista

nodoIngresos * cargaLista (char nombreArchivo[], int dni)
{
    FILE * arch = fopen(nombreArchivo, "rb");
    stIngresos ingresoPaciente;
    nodoIngresos * listaPaciente = inicLista();

    if(arch != NULL)
    {
        while(fread(&ingresoPaciente,sizeof(stIngresos),1,arch)>0) //borrar los datos?
        {
            if(ingresoPaciente.dni == dni)
            {
                listaPaciente = agregoFinalListaIngresos(listaPaciente,ingresoPaciente);
            }
        }
    }

    fclose(arch);
    return listaPaciente;

}

///10 Carga el archivo con los datos de la lista recibida por paremetro

void cargarArchivo (nodoIngresos * listaPaciente, char nombreArchivo) //funcion que recorra el arbol y llame a esta funcion en cada raiz->punterolista
{
    FILE * arch = fopen(nombreArchivo, "wb"); //borra y reescribe

    while(listaPaciente != NULL)
    {
        stIngresos paciente = listaPaciente->dato;
        fwrite(&paciente,sizeof(stIngresos),1,arch);
        // cargarArchvo (listaPaciente->practicas); //carga la lista de practicas anexada a cada nodo
        listaPaciente = listaPaciente->siguiente;
    }

    fclose(arch);
}

stIngresos cargaIngreso(nodoIngresos * listaIngresos)
{
    stIngresos ingreso;
    nodoIngresos * ultimo = buscaUltimoNodoIngresos(listaIngresos);

    ingreso.nroIngreso = ultimo->dato.nroIngreso+1;
    printf("Ingrese la fecha de INGRESO dia/mes/anio \n");
    gets(ingreso.fechaIngreso);
    printf("Ingrese la fecha de RETIRO dia/mes/anio \n");
    gets(ingreso.fechaRetiro);
    printf("Ingrese el dni del paciente");
    scanf("%i", &ingreso.dni);
    printf("Ingrese su matricula \n");
    scanf("%i", &ingreso.matriculaProfesional);

    ingreso.eliminado = 0;


    return ingreso;
}

void muestraIngreso(stIngresos ingreso)
{
    printf("----------------------------------\n");
    printf("Numero de Ingreso.....: %i\n", ingreso.nroIngreso);
    printf("Fecha de Ingreso......:%s\n", ingreso.fechaIngreso);
    printf("Fecha de Retiro.......:%s \n", ingreso.fechaRetiro);
    printf("Matricula.............:%i \n", ingreso.matriculaProfesional);
    printf("----------------------------------\n");
}


