#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"

#define DIM 10
#define ESC 27

void mostrarPracticas(char archivo [])
{
    FILE *archivoPracticas = fopen(archivo, "rb");
    if (archivoPracticas == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    Practicas registro;
    while (fread(&registro, sizeof(Practicas), 1, archivoPracticas) > 0) {
        mostrarPractica(registro);
    }
    fclose(archivoPracticas);

}

//Modificacion_de_practica: solo su nombre
void modificacionPractica(char archivo[])
{
    Practicas modPractica;
    int flag = 0;
    char control = 0;
    FILE* archivoPracticas = fopen(archivo, "r+b");

    if (archivoPracticas) {
        while (control != ESC) {
            system("cls");
            flag = buscarporNombrePracticas(archivo);

            if (flag) {
                fseek(archivoPracticas, 0, SEEK_SET);
                while (fread(&modPractica, sizeof(Practicas), 1, archivoPracticas) > 0) {
                    if (modPractica.nroPractica == flag) {
                        printf("Registro encontrado:\n");
                        mostrarPractica(modPractica);
                        break;
                    }
                }
                //fseek(archivoPracticas, (-1) * sizeof(modPractica), SEEK_CUR);
                printf("1. Modificar nombre");
                int modificacion = 0;
                fflush(stdin);
                modificacion = getch();
                system("cls");
                switch (modificacion) {
                    case '1':
                        system("cls");
                        printf("Ingrese el nuevo Nombre: ");
                        fflush(stdin);
                        gets(modPractica.nPractica);
                        fseek(archivoPracticas, (-1) * sizeof(Practicas), SEEK_CUR);
                        fwrite(&modPractica, sizeof(Practicas), 1, archivoPracticas);
                        printf("Práctica modificada!\n");
                        mostrarPractica(modPractica);
                        sleep(3);
                        control = ESC;
                        break;

                    default:
                        system("cls");
                        printf("Error: ingresó una opción inexistente.\n");
                        printf("Presione ESC para salir, cualquier tecla para continuar...");
                        control = getch();
                        break;
                }
            }
        }
        fclose(archivoPracticas);
    }
}

int buscarporNombrePracticas(char archivo [])
{
    system("cls");
    FILE* archivoPracticas = fopen(archivo, "rb");
    Practicas practicaBuscada;
    Practicas arreglo[DIM];
    int i = 0;
    int flag = 0;

    if (archivoPracticas == NULL) {
        perror("ERROR");
        return 0;
    } else {
        mostrarPracticas(archivo);
        int opc = 0;
        while (!flag) {
            printf("Ingrese el ID de la práctica: ");
            fflush(stdin);
            scanf("%i", &opc);
            if (opc >= 1 && opc <= 10) {
                flag = opc;
            } else {
                perror("");
            }
        }
        fclose(archivoPracticas);
    }
    return flag;
}

void mostrarPractica(Practicas practica)
{
    printf("Práctica: %s\n", practica.nPractica);
    printf("ID: %i\n", practica.nroPractica);
    if (practica.eliminado == 0) {
        printf("Estado: Activa\n");
    } else {
        printf("Estado: Inactiva\n");
    }
}
    /**Alta_de_practica - Baja_de_practica: solo si no fue incluida
    en ningún ingreso*/

void baja_alta_practica(char archivo[])
{
    Practicas modPractica;
    int flag = 0;
    char control = 0;
    FILE* archivoPracticas = fopen(archivo, "r+b");
    if (archivoPracticas) {
        while (control != ESC) {
            system("cls");
            flag = buscarporNombrePracticas(archivo);

            if (flag) {
                fseek(archivoPracticas, 0, SEEK_SET);
                while (fread(&modPractica, sizeof(Practicas), 1, archivoPracticas) > 0) {
                    if (modPractica.nroPractica == flag) {
                        printf("Registro encontrado:\n");
                        mostrarPractica(modPractica);
                        break;
                    }
                }
                printf("1. Dar alta");
                printf("2. Dar baja");
                int modificacion = 0;
                fflush(stdin);
                modificacion = getch();
                system("cls");
                switch (modificacion) {
                    case '1':
                        system("cls");
                        modPractica.eliminado = 1;
                        fseek(archivoPracticas, (-1) * sizeof(Practicas), SEEK_CUR);
                        fwrite(&modPractica, sizeof(Practicas), 1, archivoPracticas);
                        printf("Práctica modificada!\n");
                        mostrarPractica(modPractica);
                        sleep(3);
                        control = ESC;
                        break;
                    case '2':
                        system("cls");
                        //verificarExistencia(modPractica);
                        //VEREFICAR SI LA PRACTICA EXISTE EN ALGUN INGRESO, DE SER ASI, LA MISMA NO PODRA SER DADA DE BAJA
                        modPractica.eliminado = 0;
                        fseek(archivoPracticas, (-1) * sizeof(Practicas), SEEK_CUR);
                        fwrite(&modPractica, sizeof(Practicas), 1, archivoPracticas);
                        printf("Práctica modificada!\n");
                        mostrarPractica(modPractica);
                        sleep(3);
                        control = ESC;
                        break;

                    default:
                        system("cls");
                        printf("Error: ingresó una opción inexistente.\n");
                        printf("Presione ESC para salir, cualquier tecla para continuar...");
                        control = getch();
                        break;
                }
            }
        }
    }
    fclose(archivoPracticas);
}

/**Listado de practicas que “comiencen con”. En este caso debe poder filtrar todas las
practicas cuyo nombre comiencen con lo seleccionado por el usuario. Ejemplo: si se
elige la combinación “he”, deberían mostrarse practicas como: “hemograma o
hepatograma” etc.*/
