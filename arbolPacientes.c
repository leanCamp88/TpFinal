#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
<<<<<<< HEAD
<<<<<<< HEAD
=======
///leandro
>>>>>>> LeanBranch
=======
#include <string.h>
>>>>>>> LeanBranch

///FUNCIONES BASICAS
nodoPaciente * inicArbol()
{
    return NULL;
}
/// carga estructura paciente
stPaciente cargaPaciente(int dni)
{
    stPaciente paciente;

    paciente.DNI = dni;

    char nombre[20];
    char apellido[20];
    printf("Ingrese el nombre\n");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese el apellido\n");
    fflush(stdin);
    gets(apellido);

    strcat(nombre,apellido);
    strcpy(paciente.ApellidoyNombre,nombre);

    printf("Ingrese la edad\n");
    scanf("%i", &paciente.Edad);

    printf("Ingrese el telefono\n");
    fflush(stdin);
    gets(paciente.Telefono);

    paciente.Eliminado = 0; //por defecto activo

    printf("Ingrese el domicilio\n");
    fflush(stdin);
    gets(paciente.Domicilio);


    return paciente;
}

///recibe dato crea nodo
nodoPaciente * creaNodoPaciente(stPaciente dato)
{
    nodoPaciente * aux = (nodoPaciente*) malloc(sizeof(nodoPaciente));

    aux->paciente = dato;

    aux->listaIngresos = NULL;

    aux->Izq = NULL;
    aux->Der = NULL;

    return aux;
}
///solo agrega el paciente al arbol ordenado, crea nodo adentro
nodoPaciente * agregaPaciente(nodoPaciente* arbol, stPaciente dato)
{
    if(arbol == NULL)
    {
        nodoPaciente * nuevoNodo = creaNodoPaciente(dato);
        arbol = nuevoNodo;
    }
    else
    {
        if(dato.DNI < arbol->paciente.DNI)
        {
            arbol->Izq = agregaPaciente(arbol->Izq,dato);
        }
        else
        {
            arbol->Der = agregaPaciente(arbol->Der,dato);
        }
    }
<<<<<<< HEAD
    retur arbol;
=======
    return arbol;
>>>>>>> LeanBranch
}
///recibe dni y devulve nodo NULL si no lo encuentra

nodoPaciente * buscaPaciente(nodoPaciente * arbol, int dni)
{
    if (arbol == NULL) {

        return NULL;
    }

    if (arbol->paciente.DNI == dni) {

        return arbol;

    } else if (arbol->paciente.DNI > dni) {

        return buscaPaciente(arbol->Izq, dni);

    } else {

        return buscaPaciente(arbol->Der, dni);
    }
}
///dos maneras o swich adentro con todas las opciones de que se quiere modificar
/// (pisando datos del arbol osea nodo) o mejor funciones
///por separado para solo darle al admi la opcion de modificar dni
///(hay que mirar bien el tp de quien puede modificar que)

/// <<<<<<<<<<  MODIFICACIONES  <<<<<<<<<< ///

stPaciente modificarAYP(stPaciente dato)
{
    printf("Ingrese nuevo Apellido y nombre:\n");
    fflush(stdin);
    gets(dato.ApellidoyNombre);

    return dato;
}
stPaciente modificarEdad(stPaciente dato)
{
    printf("Ingrese nueva Edad:\n");
<<<<<<< HEAD
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
=======
    scanf("%i", &dato.Edad);
>>>>>>> LeanBranch
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
    if(dato.Eliminado == 0)
    {
        printf("Paciente de Alta\n Desea darlo de baja? S\n");
        char opc;
        fflush(stdin);
        opc = getchar();
        if(opc=='S'||opc=='s')
        {
            dato.Eliminado=1;
        }
    }
    else
    {
        printf("Paciente de Baja\n Desea darlo de alta? S\n");
        char opc;
        fflush(stdin);
        opc = getchar();
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
//6 Invocacion funciones modificacion

nodoPaciente * modificacionPaciente(nodoPaciente* arbol, int dni)
{
    nodoPaciente* buscado = buscaPaciente(arbol,dni);

    if(buscado == NULL)
    {
        printf("Error, No se encontro datos con el dni\n");
    }
    else
    {
        printf("Paciente a Modificar:\n");

        muestraPaciente(buscado->paciente);

        getchar();

        printf("Elija opcion a modificar\n");
        printf("1)- Apellido y Nombre\n");
        printf("2)- Edad\n");
        printf("3)- Domicilio\n");
        printf("4)- Telefono\n");
        printf("5)- Estado\n");
        int opc;

        fflush(stdin);

        opc = getchar();

        switch(opc)
        {
        case '1':
            system("cls");
            buscado->paciente = modificarAYP(buscado->paciente);
            break;
        case '2':
            system("cls");
            buscado->paciente = modificarEdad(buscado->paciente);
            break;
        case '3':
            system("cls");
            buscado->paciente = modificarDomicilio(buscado->paciente);
            break;
        case '4':
            system("cls");
            buscado->paciente = modificarTelefono(buscado->paciente);
            break;
        case '5':
            system("cls");
            buscado->paciente = modificarAltaBaja(buscado->paciente);
            break;
        default:
            printf("Error, porfavor seleccione opcion valida\n");
        }

    }
    ///Retorno la cabecera o el nodo modificado?
        return arbol;
}

void muestraArbol(nodoPaciente * arbol)
{
    if(arbol)
    {
        muestraArbol(arbol->Izq);
        muestraPaciente(arbol->paciente);
        muestraArbol(arbol->Der);
    }
}

void muestraPaciente(stPaciente dato)
{
<<<<<<< HEAD
    printf("-----------------------------------------------------------\n");
<<<<<<< HEAD
    printf("Apellido y nombre: %s\n", dato.ApellidoyNombre);
=======
    printf("Apellido y nombre: %s\n", dato.ApeliidoyNombre);
>>>>>>> LeanBranch
=======
    printf("---------------------------------------\n");
    printf("Apellido y nombre: %s\n", dato.ApellidoyNombre);
>>>>>>> LeanBranch
    printf("Edad: %d\n", dato.Edad);
    printf("DNI: %d\n", dato.DNI);
    printf("Domicilio: %s\n", dato.Domicilio);
    printf("Telefono: %s\n", dato.Telefono);

    if(dato.Eliminado == 1)
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
    printf("---------------------------------------\n");
}
void cargarArchivoPacientes(nodoPaciente * arbol)
{

    FILE * arch = fopen("archivodePacientes.bin","wb");

    if(arch)
    {
        recorreArbolEscritura(arbol,arch);
    }
    else{
            printf("No se abrio el archivo");
            printf("1");
    }
    fclose(arch);

}

void recorreArbolEscritura(nodoPaciente *arbol, FILE *arch)
{
    if (arbol)
    {
        stPaciente nuevoPaciente = arbol->paciente;
        fwrite(&nuevoPaciente, sizeof(stPaciente), 1, arch);
        recorreArbolEscritura(arbol->Izq, arch);
        recorreArbolEscritura(arbol->Der, arch);
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
=======
    return strcmp(((stPaciente*)a)->ApellidoyNombre, ((stPaciente*)b)->ApellidoyNombre);
>>>>>>> LeanBranch
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
    if(raiz == NULL)
    {
        printf("NO hay pacientes cargados \n");
    }

    int tamanioarreglo=contarNodos(raiz);
<<<<<<< HEAD
<<<<<<< HEAD
    paciente*arreglo=(paciente*)malloc(tamanioarreglo*sizeof(paciente));
    int indice=0;
    recorridoInorden(raiz,arreglo,&indice);
    qsort(arreglo,tamanioarreglo,sizeof(paciente),compararPacientes);
=======
=======

>>>>>>> LeanBranch
    stPaciente*arreglo=(stPaciente*)malloc(tamanioarreglo*sizeof(stPaciente));
    int indice=0;
    recorridoInorden(raiz,arreglo,&indice);

    qsort(arreglo,tamanioarreglo,sizeof(stPaciente),compararPacientes);
>>>>>>> LeanBranch
    int i;
    for(i=0; i<tamanioarreglo; i++)
    {
        muestraPaciente(arreglo[i]);
    }
    free(arreglo);
    system("pause");
}
<<<<<<< HEAD
*/
=======

<<<<<<< HEAD
>>>>>>> LeanBranch

=======
>>>>>>> LeanBranch
///FUNCIONES DE ARCHIVO


<<<<<<< HEAD
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
=======
//nodoPaciente * cargaArbolPacientes()
//{
//    FILE * archi = fopen("archivodePacientes.bin", "rb");
//
//    if (archi == NULL)
//    {
//        printf("\nError al abrir el archivo\n");
//        return NULL;
//    }
//
//    stPaciente paciente;
//    nodoPaciente *arbol = NULL;
//
//    while (fread(&paciente, sizeof(stPaciente), 1, archi) > 0)
//    {
//        arbol = agregaPaciente(arbol, paciente);
//    }
//
//    fclose(archi);
//
//    return arbol;
//}


///Levanta El arbol completo desde los 3 archivos.

nodoPaciente * cargaArbolPacientes(nodoPaciente*  arbol)
>>>>>>> LeanBranch
{
    FILE * archi = fopen(ARCHIVOPACIENTES,"rb");

    if(archi == NULL)
    {
        perror("\n Error al abrir el archivo \n");
    }
    else
    {
        stPaciente paciente;

        while(fread(&paciente,sizeof(stPaciente),1,archi) > 0)
        {
            arbol = agregaPaciente(arbol,paciente);

            nodoPaciente * buscado = buscaPaciente(arbol,paciente.DNI);

            buscado->listaIngresos = cargarListaIngresosArchivo(paciente.DNI);
        }
    }

    fclose(archi);

    return arbol;
}

nodoPaciente * altaPaciente (nodoPaciente * arbol)
{
    int dni = obtenerDNI();

    nodoPaciente * buscado = buscaPaciente(arbol,dni);

    if(buscado != NULL)
    {
        printf("Ya existe un paciente cargado con ese DNI");
    }else{

        arbol = agregaPaciente(arbol,cargaPaciente(dni));
    }

    return arbol;

}

int obtenerDNI()
{
    char input[10];
    int dni;

<<<<<<< HEAD
>>>>>>> LeanBranch
=======
    do {
        printf("Ingrese el DNI: ");
        scanf("%s", input);

        int i, todosDigitos = 1;

        for(i = 0; input[i] != '\0'; i++)
        {
            if (!isdigit(input[i]))
            {
                todosDigitos = 0;
                break;
            }
        }

        if (todosDigitos)
        {
            dni = atoi(input);

            if (dni <= 0)
            {
                printf("Por favor, ingrese un DNI válido.\n");
            }
        } else
        {
            printf("Por favor, ingrese un DNI numérico válido.\n");
        }

    } while (dni <= 0);

    return dni;
}
>>>>>>> LeanBranch
