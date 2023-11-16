#ifndef ARBOLPACIENTES_H_INCLUDED
#define ARBOLPACIENTES_H_INCLUDED


typedef struct  stPaciente
{
    char ApeliidoyNombre[40];
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

} nodoPaciente;

///FUNCIONES BASICAS

nodoPaciente * inicArbol();
nodoPaciente * creaNodoPaciente();
nodoPaciente * agregaPaciente();
nodoPaciente * buscaPaciente();
nodoPaciente * modificacionPaciente();
nodoPaciente * borrarPaciente(); //para cuando se cambia el dni
void muestraArbol();
void muestraPaciente();

///FUNCIONES DE ARCHIVO

void cargarArchivoPacientes();
nodoPaciente * cargaArbolPacientes();





#endif // ARBOLPACIENTES_H_INCLUDED
