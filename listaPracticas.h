#ifndef LISTAPRACTICAS_H_INCLUDED
#define LISTAPRACTICAS_H_INCLUDED


typedef struct stPracxIngreso
{
    int NroIngreso;
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
nodoPracticas* agregoFinalListaPractica(nodoPracticas* lista, nodoPracticas* nuevoNodo);//3
void muestraUnaPractica(nodoPracticas * practica); //4
stPracxIngreso cargaUnaPractica(); // 5
void muestraListaPracticas(nodoPracticas* listaPractica); //6
nodoPracticas* buscaUltimoNodoPractica(nodoPracticas* listaPracticas); //7
nodoPracticas * borrarListaPracticas(nodoIngresos * listaIngresos); //8
nodoPracticas* buscarNodoPractica(nodoPracticas* listaPracticas, int id); // 9
///FUNCIONES DE ARCHIVOS
nodoIngresos * cargaListaIngresos (char nombreArchivo[],  nodoPracticas * listaPracticas, int idIngreso);// 10
void cargaArchivoPractica(nodoPracticas * listaPracticas, char nombreArchivoPracticas[]); //11



#endif // LISTAPRACTICAS_H_INCLUDED
