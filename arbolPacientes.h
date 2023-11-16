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

typedef struct  _nodoPaciente
{
    stPaciente paciente;
    struct nodoIngresos* listaIngresos;
    struct _nodoPaciente *Izq;
    struct _nodoPaciente*Der;

}nodoPaciente;

///FUNCIONES BASICAS

nodoPaciente * inicArbol();
nodoPaciente * creaNodoPaciente(stPaciente dato);
nodoPaciente * agregaPaciente(nodoPaciente*arbol,stPaciente dato);
nodoPaciente * buscaPaciente(nodoPaciente*arbol,int dato);
stPaciente modificarAYP(stPaciente dato);
stPaciente modificarEdad(stPaciente dato);
stPaciente modificarDNI(stPaciente dato);
stPaciente modificarDomicilio(stPaciente dato);
stPaciente modificarTelefono(stPaciente dato);
stPaciente modificarAltaBaja(stPaciente dato);
nodoPaciente * modificacionPaciente(nodoPaciente*arbol, int dato);

nodoPaciente * borrarPaciente(); //para cuando se cambia el dni
void muestraArbol();
void muestraPaciente();

///FUNCIONES DE ARCHIVO

void cargarArchivoPacientes();
nodoPaciente * cargaArbolPacientes();





#endif // ARBOLPACIENTES_H_INCLUDED
