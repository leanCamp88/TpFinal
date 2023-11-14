#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED


#include "Pacientes.h"
#include "listaIngresos.h"
#include "libreriaMPacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct  patients
{
    char AyN[40];
    int Edad;
    int DNI;
    char Domicilio[30];
    char Telefono[15];
    int Eliminado;
}patients;

typedef struct  _nodoArbol
{
    patients pers;
    struct nodoIngresos* ingreso;
    struct _nodoArbol*Izq;
    struct _nodoArbol*Der;
} nodoArbol;

//1)
nodoArbol*inicarbol();

//2)
nodoArbol * createPatient(patients pers);

//3)
nodoArbol* getIntoTree (nodoArbol*tree,patients neew);

//4)
nodoArbol*serch(nodoArbol*treepatient, int dato);

//5)
int onOffPatient();

//6)
patients newPatient();

//7)
nodoArbol* alta_de_Paciente(nodoArbol*tree);

//8)
nodoArbol * modifyPacient (nodoArbol*tree);

//9)
void mostrarPaciente(nodoArbol* tree);

//10)
void mostrarArbol(nodoArbol*tree);



#endif // PACIENTES_H_INCLUDED
