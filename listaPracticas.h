#ifndef LISTAPRACTICAS_H_INCLUDED
#define LISTAPRACTICAS_H_INCLUDED

#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"
#include "fecha.h"
#include "time.h"
#include <ctype.h>
extern int CANT_PRACTICAS;


typedef struct stPracxIngreso
{
    int nroIngreso;
    int NroPractica;
    char Resultado[40];

}stPracxIngreso;

typedef struct nodoPracticas
{
    stPracxIngreso practica;
    struct nodoPracticas *siguiente;

}nodoPracticas;

///GUIARSE CON FUNCIONES DE LISTA PRACTICAS

///FUNCIONES BASICAS
nodoPracticas* inicListaPractica(); //1
nodoPracticas* creaNodoPractica(stPracxIngreso dato); //2
nodoPracticas* agregoFinalListaPractica(nodoPracticas* lista, stPracxIngreso nuevo);//3
void muestraUnaPracticaIngreso(stPracxIngreso  practica); //4
nodoPracticas * cargaPracticas(int idIngreso,nodoPracticas * listaPracticas,stPractica* practicas,int validos);//5
void muestraListaPracticas(nodoPracticas* listaPractica); //6
nodoPracticas * buscaUltimoNodoPractica(nodoPracticas* listaPracticas); //7
nodoPracticas * borrarListaPracticas(nodoPracticas * listaIngresos); //8


///FUNCIONES DE ARCHIVOS
nodoPracticas * cargaListaPracticas (nodoPracticas * listaPracticas, int idIngreso);// 11
void cargaArchivoPractica(nodoPracticas * listaPracticas, char nombreArchivoPracticas[]); //12



#endif // LISTAPRACTICAS_H_INCLUDED
