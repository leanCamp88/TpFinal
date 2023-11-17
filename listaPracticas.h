#ifndef LISTAPRACTICAS_H_INCLUDED
#define LISTAPRACTICAS_H_INCLUDED


typedef struct stPracticas
{
    int NroPractica;
    char nombreDePractica[30];
    int Eliminado;

}stPracticas;

typedef struct stPracticaxIngreso
{
    int nroPractica;
    char nombreDePractica[30];
    int nroIngreso;
    char resultado[100];

}stPracticaxIngreso;

typedef struct nodoPracticas
{
    stPracticaxIngreso practicasxIngreso;
    struct  nodoPracticas *siguiente;

}nodoPracticas;

///GUIARSE CON FUNCIONES DE LISTA PRACTICAS

///FUNCIONES BASICAS
nodoPracticas* inicListaPractica(); //1
nodoPracticas* creaNodoPractica(stPracticas dato); //2
nodoPracticas * agregoFinalListaPractica(nodoPracticas* listaPracticas, stPracticas  nuevo);//3
void muestraUnaPractica(nodoPracticas * practica); //4
stPracticas cargaUnaPractica(); // 5
void muestraListaPracticas(nodoPracticas* listaPractica); //6
nodoPracticas* buscaUltimoNodoPractica(nodoPracticas* listaPracticas); //7
nodoPracticas * borrarListaPracticas(nodoIngresos * listaIngresos); //8
nodoPracticas* buscarNodoPractica(nodoPracticas* listaPracticas, int id); // 9
///FUNCIONES DE ARCHIVOS
nodoIngresos * cargaListaIngresos (char nombreArchivo[],  nodoPracticas * listaPracticas, int idIngreso);// 10
void cargaArchivoPractica(nodoPracticas * listaPracticas, char nombreArchivoPracticas[]); //11



#endif // LISTAPRACTICAS_H_INCLUDED
