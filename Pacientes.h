#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED


#include "Pacientes.h"
#include "libreriaMPacient.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct sT_Paciente
{
    char AyN[40];
    int Edad;
    int DNI;
    char Domicilio[30];
    char Telefono[15];
    int Eliminado;
}sT_Paciente;

typedef struct _arbolPaciente
{
    sT_Paciente pers;
    ///struct nodo*ingreso;
    struct _arbolPaciente*Izq;
    struct _arbolPaciente*Der;
}arbolPaciente;

//1)
arbolPaciente*inicarbol();

//2)
arbolPaciente * createPatient(sT_Paciente pers);

//3)
arbolPaciente* getIntoTree (arbolPaciente*tree,sT_Paciente neew);

//4)
arbolPaciente*serch(arbolPaciente*treepatient, int dato);

//5)
int onOffPatient();

//6)
sT_Paciente newPatient();

//7)
arbolPaciente* alta_de_Paciente(arbolPaciente*tree, char nombrearchivo[]);

//8)
arbolPaciente * modifyPacient (arbolPaciente*tree);

//9)
void mostrarPaciente(arbolPaciente* tree);

//10)
void mostrarArbol(arbolPaciente*tree);



#endif // PACIENTES_H_INCLUDED
