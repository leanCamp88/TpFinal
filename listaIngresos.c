#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"
#include "fecha.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>

extern int IDGLOBAL;


///FUNCIONES BASICAS

//1 Inicializa la lista

    nodoIngresos * inicLista()
    {
        return NULL;
    }

//2 Funcion que crea un nuevo nodo Ingreso

    nodoIngresos * crearNodo(stIngresos dato)
    {

        nodoIngresos* nodoNuevo = (nodoIngresos*) malloc(sizeof(nodoIngresos));

        nodoNuevo->dato = dato;
        nodoNuevo->siguiente = NULL;
        nodoNuevo->practicas = inicListaPractica(); //inicializo la cabecera de la lista enlazada de practicas

        return nodoNuevo;
    }

//3 Muestra un nodo

    void muestraUnNodo(nodoIngresos* nodo)
    {
        muestraIngreso(nodo->dato);
    }

//4 Agrego el final de la lista

nodoIngresos* agregoFinalListaIngresos(nodoIngresos* listaIngresos, stIngresos nuevo)
{
    nodoIngresos* ultimo;

    nodoIngresos* nuevoNodo;

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

//
//nodoIngresos* agregoFinalListaIngresos(nodoIngresos* listaIngresos, stIngresos nuevo)
//{
//    nodoIngresos* ultimo = buscaUltimoNodoIngresos(listaIngresos);
//
//    if(ultimo)
//    {
//        ultimo->siguiente = crearNodo(nuevo);
//    }
//    else
//    {
//        ultimo = crearNodo(nuevo);
//    }
//
//    return listaIngresos;
//}
//

//5 Muestra lista

void muestraListaIngresos(nodoIngresos* listaIngresos)
{
        nodoIngresos* aux = listaIngresos;

        while(aux != NULL)
        {
            muestraUnNodo(aux);
            aux = aux->siguiente;
        }

}

void mostrarIngresoPaciente(nodoPaciente* arbolGeneral)
{
    int dato=0;

    printf("\nIngrese DNI del paciente\n");
    scanf("%d", &dato);

    nodoPaciente * buscado = buscaPaciente(arbolGeneral,dato);

    muestraListaIngresos(buscado->listaIngresos);

}

//6 ç ultimo nodo

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


//7 Borrar lista

nodoIngresos * borraLista(nodoIngresos * listaIngresos)
{
    nodoIngresos * aux;

    while(listaIngresos != NULL)
    {
        aux = listaIngresos;
        listaIngresos = listaIngresos->siguiente;
        free(aux);
    }

    return listaIngresos;
}

//8 Busca un ingreso

///FALTA FILTRAR POR FECHA EN VEZ DE POR NUMERO DE INGRESO
void muestraIngresoPorFecha(nodoPaciente*arbolGeneral)
{
    stFecha desde;
    stFecha hasta;

    int dni=0;
      printf("\nIngrese DNI del paciente: \n");
    scanf("%d", &dni);
    nodoPaciente * buscado = buscaPaciente(arbolGeneral,dni);

    printf("\nIngrese Fecha porfavor\n");
    printf("\nDesde:");
    desde=cargarFecha();
    printf("\nHasta:");
    hasta=cargarFecha();

    while(arbolGeneral->listaIngresos->dato.fechaIngreso.anio>desde.anio&&arbolGeneral->listaIngresos->dato.fechaIngreso.anio<hasta.anio)
    {
        while(arbolGeneral->listaIngresos->dato.fechaIngreso.mes>desde.mes&&arbolGeneral->listaIngresos->dato.fechaIngreso.mes<hasta.mes)
        {
            while(arbolGeneral->listaIngresos->dato.fechaIngreso.dia>desde.dia&&arbolGeneral->listaIngresos->dato.fechaIngreso.dia<hasta.dia)
            {

                muestraIngreso(arbolGeneral->listaIngresos->dato);
            }
        }
    }

}
///Validacion de fecha, devuelve un ingreso de la fecha estimada
nodoIngresos*validacionFecha(stIngresos ingreso, nodoPaciente*buscado)
{
    nodoIngresos*aux=buscado->listaIngresos;

    while(aux!=NULL)
    {
        if(ingreso.fechaIngreso.anio=aux->dato.fechaIngreso.anio)
        {
            if(ingreso.fechaIngreso.mes=aux->dato.fechaIngreso.mes)
            {
                if(ingreso.fechaIngreso.dia=aux->dato.fechaIngreso.dia)
                {
                    return aux;
                }
            }
        }
        aux=aux->siguiente;
    }
    return aux;
}

void muestraIngresoPorDni(nodoPaciente* arbolGeneral)
{
    int dni = 0;
    int nro = 0;

    printf("\nIngrese DNI del paciente: \n");
    scanf("%d", &dni);

    nodoPaciente * buscado = buscaPaciente(arbolGeneral,dni);

    printf("\nIngrese Nro de Ingreso: \n");
    scanf("%d",&nro);

    nodoIngresos * buscando = buscaIngreso(buscado->listaIngresos,nro);

    muestraIngreso(buscado->listaIngresos->dato);

}



nodoIngresos * buscaIngreso(nodoIngresos * listaIngresos, int idIngreso)
{
    while(listaIngresos)
    {

        if(listaIngresos->dato.nroIngreso == idIngreso)
        {
            return listaIngresos;
        }

        listaIngresos = listaIngresos->siguiente;
    }

    return listaIngresos;
}


///FUNCIONES RELACIONADAS CON EL ARCHIVO INGRESOS

//9 Lee el archivo y carga la lista (filtra por el dni)

///Levanta la lista de ingresos y la lista de practicas desde sus archivos

nodoIngresos * cargarListaIngresosArchivo(int dni)
{
    FILE * arch = fopen(ARCHIVOINGRESOS, "rb");

    stIngresos ingreso;

    nodoIngresos * ingresosPaciente = inicLista();

    if(arch)
    {
        while( fread(&ingreso,sizeof(stIngresos),1,arch) > 0) //borrar los datos?
        {
            if(ingreso.dni == dni)
            {
                ingresosPaciente = agregoFinalListaIngresos(ingresosPaciente,ingreso);

                ingresosPaciente->practicas = cargaListaPracticas(ingresosPaciente->practicas,ingreso.nroIngreso);
            }
        }
    }

    fclose(arch);

    return ingresosPaciente;

}

//10 Carga el archivo con los datos de la lista recibida por paremetro

void cargarArchivo (nodoIngresos * listaPaciente, char nombreArchivo) //funcion que recorra el arbol y llame a esta funcion en cada raiz->punterolista
{
    FILE * arch = fopen(nombreArchivo, "wb"); //borra y reescribe

    while(listaPaciente != NULL)
    {
        stIngresos paciente = listaPaciente->dato;

        fwrite(&paciente,sizeof(stIngresos),1,arch);

        // cargarArchivo (listaPaciente->practicas); //carga la lista de practicas anexada a cada nodo

        listaPaciente = listaPaciente->siguiente;
    }

    fclose(arch);
}

/// FUNCIONES DE LA ESTRUCTURA INGRESOS

//11 Funcion que cargar la estructura de ingreso

stIngresos cargaIngreso(int dni)
{
    stIngresos ingreso;

    IDGLOBAL++;

    ingreso.nroIngreso = IDGLOBAL;

    ingreso.dni = dni;

    printf("Ingrese matricula del solicitante \n");

    scanf("%i",&ingreso.matriculaProfesional);
    printf("Ingrese Dia: /n");
//    int fecha;
//    fflush(stdin);
//    scanf("%i",&fecha);
//    ingreso.fechaIngreso.dia = fecha;
//    printf("Ingrese mes: /n");
//    fflush(stdin);
//    scanf("%i",&fecha);
//    ingreso.fechaIngreso.mes = fecha;
//    printf("Ingrese anio: /n");
//    fflush(stdin);
//    scanf("%i",&fecha);
//    ingreso.fechaIngreso.anio = fecha;

    ingreso.fechaIngreso = obtenerFechaActual(); //por defecto la actual

    ingreso.fechaRetiro = ingresarFecha();

    ingreso.eliminado = 0; //por defecto activa

    return ingreso;
}

//12 Funcion que muestra estructura ingreso completa

void muestraIngreso(stIngresos ingreso)
{
    printf("----------------------------------\n");
    printf("Numero de Ingreso.....: %i\n", ingreso.nroIngreso);
    printf("Fecha de Ingreso......:%s\n", ingreso.fechaIngreso);
    printf("Fecha de Retiro.......:%s \n", ingreso.fechaRetiro);
    printf("Matricula.............:%i \n", ingreso.matriculaProfesional);
    printf("----------------------------------\n");
}

// 13 Busqueda de idIngresos mayor

int buscaIdIngresoMayor()
{
    FILE * arch = fopen(ARCHIVOINGRESOS, "rb");

    int max = 0;

    if(arch)
    {
        stIngresos ingreso;

        while(fread(&ingreso,sizeof(stIngresos),1,arch) > 0)
        {
            if(ingreso.nroIngreso > max)
                {
                    max = ingreso.nroIngreso;
                }
        }
    }

    fclose(arch);

    return max;
}


// 14 Alta ingresos

nodoPaciente * altaIngresos(nodoPaciente * arbol,stPractica *practicas,int validos) //
{
    int dni = obtenerDNI();



    nodoPaciente * buscado = buscaPaciente(arbol, dni);

    if(!buscado)
    {
        printf("El paciente no se encuentra en Sistema \n");

        stPaciente nuevo = cargaPaciente(dni);

        arbol = agregaPaciente(arbol,nuevo);

        buscado = buscaPaciente(arbol,dni);
    }

    ///carga el nuevo stIngreso
    stIngresos nuevoIngreso = cargaIngreso(dni); //hasta aca llega joya
    ///Lo agrega al final de la lista de ingresos
    buscado->listaIngresos = agregoFinalListaIngresos(buscado->listaIngresos,nuevoIngreso);

    ///busca la cabecera al ingreso de practicas
    nodoIngresos * nodoIngresoBuscado = buscaIngreso(buscado->listaIngresos,nuevoIngreso.nroIngreso);

    nodoIngresoBuscado->practicas = cargaPracticas(nuevoIngreso.nroIngreso,nodoIngresoBuscado->practicas,practicas,validos);


    return arbol;
}
