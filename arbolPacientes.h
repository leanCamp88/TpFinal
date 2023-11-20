#ifndef ARBOLPACIENTES_H_INCLUDED
#define ARBOLPACIENTES_H_INCLUDED
#include "menus.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"
#include "fecha.h"
#include "time.h"
#include <ctype.h>

extern int CANT_PRACTICAS;


#include <stdio.h>
#include <stdlib.h>

typedef struct  stPaciente
{
    char ApellidoyNombre[40];
    int Edad;
    int DNI;
    char Domicilio[30];
    char Telefono[15];
    int Eliminado;

}stPaciente;

typedef struct  nodoPaciente
{
    stPaciente paciente;
    struct nodoIngresos* listaIngresos;
    struct nodoPaciente *Izq;
    struct nodoPaciente*Der;

}nodoPaciente;

///FUNCIONES BASICAS
void mostrarIngresoPaciente(nodoPaciente* arbolGeneral);

nodoPaciente * altaIngresos(nodoPaciente * arbol,stPractica *practicas,int validos);
//1 Inicializa arbol
nodoPaciente * inicArbol();
//2 Carga estructura de paciente
stPaciente cargaPaciente(int dni);
//2 Recibe dato crea nodo
nodoPaciente * creaNodoPaciente(stPaciente dato);
//3 Solo agrega el paciente al arbol ordenado, crea nodo adentro
nodoPaciente * agregaPaciente(nodoPaciente*arbol,stPaciente dato);
//4 Recibe dni y devulve nodo NULL si no lo encuentra
nodoPaciente * buscaPaciente(nodoPaciente * arbol, int dni);
//5 Modificacion
stPaciente modificarAYP(stPaciente dato);
stPaciente modificarEdad(stPaciente dato);
stPaciente modificarDomicilio(stPaciente dato);
stPaciente modificarTelefono(stPaciente dato);
stPaciente modificarAltaBaja(stPaciente dato);
//6 Invocacion funciones modificacion
nodoPaciente * modificacionPaciente(nodoPaciente*arbol, int dato);
//7 Borra nodo paciente (para cuando se modifica el dni
nodoPaciente * borrarPaciente();
//8 Muestra el arbol
void muestraArbol(nodoPaciente * arbol); //hacer ordenado por nombre y apellido
nodoPaciente * altaPaciente (nodoPaciente * arbol);
void muestraPaciente();


int contarNodos(nodoPaciente* raiz);
int compararPacientes(const void* a, const void* b);
void recorridoInorden(nodoPaciente* raiz, stPaciente* arreglo, int* indice);
void mostrarPacientesOrdenadosAlfabeticamente(nodoPaciente* raiz);

///FUNCIONES DE ARCHIVO

void cargarArchivoPacientes(nodoPaciente * arbol);
void recorreArbolEscritura (nodoPaciente * arbol, FILE * arch);
nodoPaciente * cargaArbolPacientes();

///PROTOTIPADO DE MENUS, porque no me deja prototipar en las librerias h, no me reconoce la estructura de nodoPaciente
nodoPaciente * menuPacientes (nodoPaciente * arbolGeneral);
nodoPaciente * menuAdmin(nodoPaciente * arbolGeneral,stPractica* practicas,int validos);/*, archivoEmpleados, archivoPracticas*/
nodoPaciente * menuPracticas(nodoPaciente*arbolGeneral,stPractica* practicas,int validos);

nodoPaciente* menuIngresos(nodoPaciente*arbolGeneral,stPractica* practicas,int validos);

void verListadoIngreso(nodoPaciente * arbolGeneral);
void buscandoIngreso(nodoPaciente * arbolGeneral);


void menuPrincipal(stPaciente* arbolPacientes,stPractica* practicas,int validos);

//FUNCIONES DE VERIFICACION
int obtenerDNI();
#endif // ARBOLPACIENTES_H_INCLUDED
