#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "unistd.h"

#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "practicas.h"
#include "time.h"

#define DIM 10
#define ESC 27

extern int CANT_PRACTICAS;


void levantarSistema()
{
    ///arreglo practicas
    //int capacidad = 650;
    int validos = 0;
    ///stPractica *practicas = (stPractica*)malloc(sizeof(stPractica) * capacidad);
    //levantarArchivoArreglosPracticas(practicas,&capacidad,&validos);

    ///Arbol
    //nodoPaciente* arbolGeneral;





    ///menuPrincipal();



    //guardarCambiosArregloPracticas(practicas,validos);


}



int comparar(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void levantarArchivoArreglosPracticas(stPractica* practicas,int* capacidad,int* validos)
{
    FILE *archivo = fopen("Practicas.dat","rb");

    if(!archivo)
    {
        perror("Error al abrir el archivo/n");
    }
    else
    {
        while(fread(&practicas[*validos], sizeof(stPractica), 1, archivo) == 1)
        {

            (*validos)++;

            if ((*validos) >= (*capacidad))
            {

                (*capacidad) *= 2;

                stPractica* nuevoArregloPracticas = (stPractica*) realloc(practicas,sizeof(stPractica)* (*capacidad));

                if (practicas == NULL)
                {
                    perror("Error al redimensionarPracticas el arreglo/n");

                }
                else
                {
                    practicas = nuevoArregloPracticas;
                }

            }
        }

        /// Ordena el array de practicas alfabéticamente
        qsort(practicas, (*validos), sizeof(stPractica), comparar);



    }
    fclose(archivo);

}

void guardarCambiosArregloPracticas(stPractica practicas[],int validos)
{
    FILE* archi = fopen(ARCHIVOSOLOPRACTICAS,"wb");

    if(archi)
    {
        for(int i = 0;i < validos; i++)
        {
            fwrite(&practicas[i],sizeof(stPractica),1,archi);
        }
    }

    fclose(archi);
}


void mostrarPracticas(stPractica practicas[],int validos)
{
    for(int i = 0; i < validos; i++)
    {
        muestraUnaPractica(practicas[i]);
    }
}


///Modificacion_de_practica: solo su nombre

int verificarID(stPractica practicas[],int validos)
{
    printf("Ingresa el ID de la practica: \n");

    int id = 0;
    scanf("%i",&id);

    char correcto = 0;

    while(correcto != ESC && correcto != 's' && correcto != 'S')
    {
        if(id < validos && id > 0)
        {
            muestraUnaPractica(practicas[id]);

            printf("Esta es la practica ? S para terminar, ESC para salir o cualquier tecla para continuar ingresando practicas.\n");
        }
        else
        {
            printf("ID Inexistente, cualquier tecla para ingresar nuevamente o ESC para salir \n");
        }


        correcto = getchar();
    }

    if(correcto == ESC)
    {
        return -1;
    }
    else
    {
        return id;
    }

}


void modificacionPractica(stPractica practicas[],int validos)
{
    mostrarPorNombrePracticas(practicas,validos);

    int id = verificarID(practicas,validos);

    if(id)
    {
        printf("Ingrese el nuevo nombre de la practica: \n");
        gets(practicas[id-1].nombrePractica);
    }

}


void muestraUnaPractica(stPractica practica)
{
//    if(practica.eliminado == 0)
//    {
        printf("\n*******************\n");
        printf("Nombre de la practica: %s \n", practica.nombrePractica);
        printf("NRO practica %i \n", practica.nroPractica);
//    }
//    else
//    {
//        printf("Practica no disponible actualmente/n");
//    }

}


void mostrarPorNombrePracticas(stPractica practicas[],int validos)
{

    printf("Ingrese el nombre de la practica a buscar: \n");

    char nombrePractica[30];

    fflush(stdin);
    gets(nombrePractica);


    for(int i = 1; i < validos; i++)
    {
        if( strcmpi(nombrePractica,practicas[i].nombrePractica) == 0)
        {
            muestraUnaPractica(practicas[i]);
        }
    }
}

void mostrarPractica(stPractica practica)
{
    printf("\n-------------------------------------------------------\n");
    printf("Practica: %s\n", practica.nombrePractica);
    printf("ID: %i\n", practica.nroPractica);
    if (practica.eliminado == 0)
    {
        printf("Estado: Activa\n");
    }
    else
    {
        printf("Estado: Inactiva\n");
    }
}
//Alta_de_practica - Baja_de_practica: solo si no fue incluida
// en ningún ingreso

void cambiarEstadoPractica(stPractica* practicas,int validos)
{
    mostrarPorNombrePracticas(practicas,validos);

    int id = verificarID(practicas,validos);

    if(practicas[id-1].eliminado == 0)
    {
        practicas[id-1].eliminado = 1;
    }
    else
    {
        practicas[id-1].eliminado = 0;
    }
}





/// SE USAN ????


void mostrarPracticaPorNumero(int nmroPractica)
{
    FILE* archivoPracticas = fopen(ARCHIVOSOLOPRACTICAS,"ab");

    stPractica aux;

    if(!archivoPracticas)
    {
        perror("");
    }
    else
    {
        while(fread(&aux, sizeof(stPractica),1,archivoPracticas)>0)
        {
            if(aux.nroPractica == nmroPractica)
            {
                mostrarPractica(aux);
            }
        }
    }
    fclose(archivoPracticas);
}


stPractica devuelvePractica(int nroPractica)
{
    system("cls");

    FILE* archivoPracticas = fopen(ARCHIVOSOLOPRACTICAS, "rb");

    stPractica aux;

    ///RETORNA EL NUMERO DE PRACTRICA EN -1 SI HAY UN ERROR
    if (archivoPracticas == NULL)
    {
        perror("ERROR");
        aux.nroPractica = -1;
        return aux;
    }
    else
    {
        while(fread(&aux,sizeof(stPractica),1,archivoPracticas) > 0)
        {
            if(aux.nroPractica == nroPractica)
            {
                return aux;
            }
        }
    }

    fclose(archivoPracticas);

    ///SI NO ENCUENTRA RETORNA NRO DE PRACTICA EN -1
    aux.nroPractica = -1;

    return aux;

}

