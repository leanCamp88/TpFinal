#include "arbolPacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
<<<<<<< HEAD
=======
///leandro
>>>>>>> LeanBranch

///FUNCIONES BASICAS

nodoPaciente * inicArbol()
{
    return NULL;
}
///recibe dato crea nodo
nodoPaciente * creaNodoPaciente(stPaciente dato)
{
    nodoPaciente * aux = (nodoPaciente*)malloc(sizeof(nodoPaciente));
    aux->paciente=dato;
    aux->listaIngresos=NULL;
    aux->Izq=NULL;
    aux->Der=NULL;

    return aux;
}
///solo agrega el paciente al arbol ordenado, crea nodo adentro
nodoPaciente * agregaPaciente(nodoPaciente*arbol,stPaciente dato)
{
    if(arbol==NULL)
    {
        nodoPaciente*nuevoNodo=creaNodoPaciente(dato);
    }
    else
    {
        if(dato.DNI<arbol->paciente.DNI)
        {
            arbol->Izq=agregaPaciente(arbol->Izq,dato);
        }
        else
        {
            arbol->Der=agregaPaciente(arbol->Der,dato);
        }
    }
<<<<<<< HEAD
    retur arbol;
=======
    return arbol;
>>>>>>> LeanBranch
}

///recibe dni y devulve nodo NULL si no lo encuentra
nodoPaciente * buscaPaciente(nodoPaciente*arbol,int dato)
{
    nodoPaciente*buscado=inicArbol();
    if(arbol)
    {
        if(arbol->paciente.DNI==dato)
        {
            buscado=arbol;
        }
        else
        {
            if(arbol->paciente.DNI>dato)
            {
                buscado=buscaPaciente(arbol->Izq,dato);
            }
            else
            {
                buscado=buscaPaciente(arbol->Der,dato);
            }
        }
    }
    return buscado;
}

///dos maneras o swich adentro con todas las opciones de que se quiere modificar
/// (pisando datos del arbol osea nodo) o mejor funciones
///por separado para solo darle al admi la opcion de modificar dni
///(hay que mirar bien el tp de quien puede modificar que)
stPaciente modificarAYP(stPaciente dato)
{
    printf("Ingrese nuevo Apellido y nombre:\n");
    fflush(stdin);
    gets(dato.ApeliidoyNombre);
    return dato;
}
stPaciente modificarEdad(stPaciente dato)
{
    printf("Ingrese nueva Edad:\n");
<<<<<<< HEAD
    scanf("%d", &dato.edad);
=======
    scanf("%d", &dato.Edad);
>>>>>>> LeanBranch
    return dato;
}
stPaciente modificarDNI(stPaciente dato)
{
    printf("Ingrese nuevo DNI:\n");
    scanf("%d", &dato.DNI);
    return dato;
}
stPaciente modificarDomicilio(stPaciente dato)
{
    printf("Ingrese nuevo Domicilio:\n");
    fflush(stdin);
    gets(dato.Domicilio);
    return dato;
}
stPaciente modificarTelefono(stPaciente dato)
{
    printf("Ingrese nuevo Telefono:\n");
    fflush(stdin);
    gets(dato.Telefono);
    return dato;
}
stPaciente modificarAltaBaja(stPaciente dato)
{
    if(dato.Eliminado==0)
    {
        printf("Paciente de Alta\n Desea darlo de baja? S/N\n");
        char opc;
        fflush(stdin);
        gets(opc);
        if(opc=='S'||opc=='s')
        {
            dato.Eliminado=1;
        }
    }
    else
    {
        printf("Paciente de Baja\n Desea darlo de alta? S/N\n");
        char opc;
        fflush(stdin);
        gets(opc);
        if(opc=='S'||opc=='s')
        {
            dato.Eliminado=0;
        }
    }
<<<<<<< HEAD
    return dato
=======
    return dato;
>>>>>>> LeanBranch
}

nodoPaciente * modificacionPaciente(nodoPaciente*arbol, int dato)
{
    nodoPaciente*buscado=buscaPaciente(arbol,dato);
    if(buscado==NULL)
    {
        printf("Error, No se encontro datos con el dni\n");
    }
    else
    {
        printf("Paciente a Modificar:\n");
        muestraPaciente(buscado->paciente);
        getch();
        printf("Elija opcion a modificar\n");
        printf("1)- Apellido y Nombre\n");
        printf("2)- Edad\n");
        printf("3)- DNI\n");
        printf("4)- Domicilio\n");
        printf("5)- Telefono\n");
        printf("6)- Estado\n");
        int opc;
        fflush(stdin);
        opc=getch();
        switch(opc)
        {
        case '1':
            system("cls");
            buscado->paciente=modificarAYP(buscado->paciente);
            break;
        case '2':
             system("cls");
            buscado->paciente=modificarEdad(buscado->paciente);
            break;
        case '3':
             system("cls");
            buscado->paciente=modificarDNI(buscado->paciente);
            break;
        case '4':
             system("cls");
            buscado->paciente=modificarDomicilio(buscado->paciente);
            break;
        case '5':
             system("cls");
            buscado->paciente=modificarTelefono(buscado->paciente);
            break;
        case '6':
             system("cls");
            buscado->paciente=modificarAltaBaja(buscado->paciente);
            break;
        default:
            printf("Error, porfavor seleccione opcion valida\n");
        }

    }
    ///Retorno la cabecera o el nodo modificado?
        return arbol;
}

///para cuando se cambia el dni
nodoPaciente * borrarPaciente()
{

}


void muestraArbol(nodoPaciente*arbol)
{
    if(arbol)
    {
        muestraPaciente(arbol->paciente);
        muestraArbol(arbol->Izq);
        muestraArbol(arbol->Der);
    }
}

void muestraPaciente(stPaciente dato)
{
    printf("-----------------------------------------------------------\n");
<<<<<<< HEAD
    printf("Apellido y nombre: %s\n", dato.ApellidoyNombre);
=======
    printf("Apellido y nombre: %s\n", dato.ApeliidoyNombre);
>>>>>>> LeanBranch
    printf("Edad: %d\n", dato.Edad);
    printf("DNI: %d\n", dato.DNI);
    printf("Domicilio: %s\n", dato.Domicilio);
    printf("Telefono: %s\n", dato.Telefono);
    if(dato.Eliminado==1)
    {
        printf("Estado: Baja\n");
    }
    else
    {
<<<<<<< HEAD
        printf("Estado: Alta\n")
    }
}
///Funcion de arbol a arreglo
/*
=======
        printf("Estado: Alta\n");
    }
}
///Funcion de arbol a arreglo

>>>>>>> LeanBranch
int contarNodos(nodoPaciente* raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
<<<<<<< HEAD
        return 1 + contarNodos(raiz->izq) + contarNodos(raiz->der);
=======
        return 1 + contarNodos(raiz->Izq) + contarNodos(raiz->Der);
>>>>>>> LeanBranch
    }
}

int compararPacientes(const void* a, const void* b)
{
<<<<<<< HEAD
    return strcmp(((paciente*)a)->nya, ((paciente*)b)->nya);
}

void recorridoInorden(nodoPaciente* raiz, paciente* arreglo, int* indice)
{
    if (raiz != NULL)
    {
        recorridoInorden(raiz->izq, arreglo, indice);
        arreglo[*indice] = raiz->p;
        (*indice)++;
        recorridoInorden(raiz->der, arreglo, indice);
=======
    return strcmp(((stPaciente*)a)->ApeliidoyNombre, ((stPaciente*)b)->ApeliidoyNombre);
}

void recorridoInorden(nodoPaciente* raiz, stPaciente* arreglo, int* indice)
{
    if (raiz != NULL)
    {
        recorridoInorden(raiz->Izq, arreglo, indice);
        arreglo[*indice] = raiz->paciente;
        (*indice)++;
        recorridoInorden(raiz->Der, arreglo, indice);
>>>>>>> LeanBranch
    }
}

void mostrarPacientesOrdenadosAlfabeticamente(nodoPaciente* raiz)
{
    int tamanioarreglo=contarNodos(raiz);
<<<<<<< HEAD
    paciente*arreglo=(paciente*)malloc(tamanioarreglo*sizeof(paciente));
    int indice=0;
    recorridoInorden(raiz,arreglo,&indice);
    qsort(arreglo,tamanioarreglo,sizeof(paciente),compararPacientes);
=======
    stPaciente*arreglo=(stPaciente*)malloc(tamanioarreglo*sizeof(stPaciente));
    int indice=0;
    recorridoInorden(raiz,arreglo,&indice);
    qsort(arreglo,tamanioarreglo,sizeof(stPaciente),compararPacientes);
>>>>>>> LeanBranch
    int i;
    for(i=0; i<tamanioarreglo; i++)
    {
        muestraUnPaciente(arreglo[i]);
    }
    free(arreglo);
}
<<<<<<< HEAD
*/
=======

>>>>>>> LeanBranch

///FUNCIONES DE ARCHIVO

void cargarArchivoPacientes();

<<<<<<< HEAD

nodoPaciente * cargaArbolPacientes(nodoPaciente*arbol, char archivoIngresos[], char archivoPracticas[])
{
    FILEarchi=fopen("ArchivoDePacientes.dat","rb");
    if(archi==NULL)
    {
        printf("\nError al abrir el archivo\n");
        return(1);
    }
    else
    {
        patients paciente;

        while(fread(&paciente,sizeof(patients),1,archi)>0)
        {
            arbol = agregaPaciente(arbol,paciente);
            nodoArbol * nodoPaciente = buscar(arbol,paciente.DNI);
            ///Falta saber que practicas le cargamos si no es aca, no lleva el prototipado
            nodoPaciente->ingreso = cargaListaIngresos(archivoIngresos, arbol->pers.DNI);
        }
    }

    fclose(archi);
    return arbol;
}
=======
nodoPaciente* cargarArchivosEstructuras(nodoPaciente* arbolPacientes)
{
    FILE*archiPaciente=fopen(ARCHIVOPACIENTES,"rb");
    if(archiPaciente!=NULL)
    {
        stPaciente paciente;
        while(fread(&paciente,sizeof(stPaciente),1,archiPaciente)>0)
        {
            arbolPacientes=agregaPaciente(arbolPacientes,paciente);
            nodoPaciente*buscado=buscaPaciente(arbolPacientes,paciente.DNI);
            buscado->listaIngresos=cargaLista(paciente.DNI);
            buscado->listaIngresos->practicas=cargaListaPracticas(arbolPacientes->listaIngresos->practicas)
        }
    }
    return arbolPacientes;
}


>>>>>>> LeanBranch
