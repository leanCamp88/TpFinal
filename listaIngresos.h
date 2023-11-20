#ifndef LISTAINGRESOS_H_INCLUDED
#define LISTAINGRESOS_H_INCLUDED
#include "fecha.h"
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


typedef struct stIngresos
{
    int nroIngreso;
    stFecha fechaIngreso; //por defecto la actual
    stFecha fechaRetiro;
    int dni;
    int matriculaProfesional;
    int eliminado;

}stIngresos;


typedef struct nodoIngresos
{
    stIngresos dato;
    struct nodoIngresos * siguiente;
    struct nodoPracticas * practicas;

}nodoIngresos;

///FUNCIONES BASICAS



//1 Inicializa la lista
nodoIngresos * inicLista();
//2 Funcion que crea un nuevo nodo Ingreso
nodoIngresos * crearNodo(stIngresos dato);
//3 Muestra un nodo
void muestraUnNodo(nodoIngresos* nodo);
//4 Agrego el final de la lista
nodoIngresos* agregoFinalListaIngresos(nodoIngresos* listaIngresos, stIngresos nuevo);
//5 Muestra lista
void muestraListaIngresos(nodoIngresos* listaIngresos);
//6 Busca ultimo nodo
nodoIngresos* buscaUltimoNodoIngresos(nodoIngresos* listaIngresos);
//7 Borrar lista
nodoIngresos* borraLista(nodoIngresos* listaIngresos);
//8 Busca un ingreso

nodoIngresos * buscaIngreso(nodoIngresos * listaIngresos,int idIngreso); ///FALTA

///FUNCIONES DE ARCHIVOS
//9 Lee el archivo y carga la lista (filtra por el dni)
nodoIngresos * cargaListaenArchivo (int dni);
//10 Carga el archivo con los datos de la lista recibida por paremetro
void cargarArchivo (nodoIngresos * listaPaciente, char nombreArchivo); ///falta modificacion enlace con funcion de practicas

nodoIngresos * cargarListaIngresosArchivo(int dni);


/// FUNCIONES DE LA ESTRUCTURA INGRESOS
//11 Funcion que cargar la estructura de ingreso
stIngresos cargaIngreso(int dni); //falta enlace con variable global
//12 Funcion que muestra estructura ingreso completa
void muestraIngreso(stIngresos ingreso);
//13 Busqueda de idIngresos mayor
int buscaIdIngresoMayor();


///FALTA!!
///funciones extra pedidas
 /*
    o Listado de ingresos por paciente (sin detalle de prácticas).
    o Consulta de 1 ingreso en particular, filtrado por nro o fecha de ingreso, con detalle de
prácticas y resultados obtenidos.
*/

///Alta_de_ingreso:
/*debe verificarse la existencia del paciente antes de dar el alta
    (funcion ALTA PACIENTE Y BUSQUEDA PACIENTE)
 y debe incluir al menos 1 practica de laboratorio
    (funcion de alta practica con while de cuantas practicas) solo las disponibles*/


///Modificación_de_ingreso:
/*solo pueden modificarse las fechas y matricula del solicitante*/

///Baja_de_ingreso:
/*deben actualizarse en cascada (dar de baja), las practicas asociadas al ingreso*/

///Funcion maximo id
/* funcion que recorra archivo y devuelva mayor id y lo almacene en variable global*/

///Filtro de ingresos x fecha (con archivo, mas facil)

//Funcion que reciba las fechas parametro y filtre (llama a muestra) con archivo
//Funcion que ademas filtre por paciente

///Funciones de fechas
/* carga estructura fecha, libreria time.h que devuelva fecha actual,
verificacion de fecha egreso (mayor a la actual)*/

#endif // LISTAINGRESOS_H_INCLUDED
