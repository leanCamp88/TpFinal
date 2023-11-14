#ifndef LISTAINGRESOS_H_INCLUDED
#define LISTAINGRESOS_H_INCLUDED


typedef struct stIngresos
{
    int nroIngreso;
    int fechaIngreso[10]; //por defecto la actual
    int fechaRetiro[10];
    int dni;
    int matriculaProfesional;
    int eliminado;

}stIngresos;

typedef struct nodoIngresos
{
    stIngresos dato;
    struct nodoIngresos * siguiente;
    //struct nodoIngresosPracticas * practicas;

}nodoIngresos;

///FUNCIONES BASICAS
nodoIngresos * inicLista(); //1
nodoIngresos * crearNodo(stIngresos dato); //2
nodoIngresos* agregarPrincipioLista(nodoIngresos* listaIngresos ,nodoIngresos * nodoNuevo);//3
void muestraUnNodo(nodoIngresos* nodo); //4
nodoIngresos* agregoFinalListaIngresos(nodoIngresos* listaIngresos, stIngresos nuevo);//5
void muestraListaIngresos(nodoIngresos* listaIngresos); //6
nodoIngresos* buscaUltimoNodoIngresos(nodoIngresos* listaIngresos); //7
nodoIngresos * borrarLista(nodoIngresos * listaIngresos); //8

///FUNCIONES DE ARCHIVOS
nodoIngresos * cargaLista (char nombreArchivo[], int dni);//9
void cargarArchivo (nodoIngresos * listaPaciente, char nombreArchivo); //10

stIngresos cargaIngreso();
void muestraIngreso(stIngresos ingreso);

///Alta_de_ingreso: debe verificarse la existencia del paciente antes de dar el alta (funcion de stPacientes) y debe incluir al menos 1 practica de laboratorio
///Modificación_de_ingreso: solo pueden modificarse las fechas y matricula del solicitante
///Baja_de_ingreso: deben actualizarse en cascada (dar de baja), las practicas asociadas al ingreso

#endif // LISTAINGRESOS_H_INCLUDED
