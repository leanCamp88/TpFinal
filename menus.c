#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"

#define ESC 27

int IDGLOBAL;


void menuPrincipal(stPaciente* arbolPacientes,stPractica* practicas,int validos)
{
    int log = login();
    char opcion = 0;

    while(opcion != ESC)
    {
        printf("opcion: \n"); //opc final para cargar datos nuevamente en archivos
        int opc = 0;
        scanf("%i",&opc);
        opcion = getchar();

        switch(opc)
        {
        case 1:
            arbolPacientes = menuAdmin(arbolPacientes,practicas,validos);

            //empleado = login(char archivoEmpleados[]);
            // arbolPacientes = menuPerfiles(empleado);

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

        case ESC:
            printf("Gracias por visitarnos\n");

            //guardadoEstructurasArchivos;

            break;

        default:
            printf("Seleccione una opcion Valida\n");

            break;
        }
    }
    system("cls");


    /// CARGA DE ARCHIVOS
 //  cargarArchivoPacientes(arbolPacientes);
}



nodoPaciente * menuAdmin(nodoPaciente * arbolGeneral,stPractica* practicas,int validos)/*, archivoEmpleados, archivoPracticas*///TODO
{
    system("cls");

    int opc;

    while(opc != ESC)
    {
        printf("--------------------------------\n");

        printf("\tBIENVENIDO AL MENU ADMINISTRADOR\n");

        printf("1- PACIENTES\n"); // MODIFICACION, BAJA, ALTA, MUESTRA
        printf("2- PRACTICAS\n"); // MOFICICACION, BAJA, ALTA, MUESTRA
        printf("3- INGRESOS\n"); //MODIFICACION, BAJA, ALTA, MUESTRA
        printf("4- EMPLEADOS\n"); // MODIFICACION, BAJA, ALTA, MUESTRA
        printf("ESC para volver atras.\n");
        printf("--------------------------------\n");
        opc = getch();

        switch(opc)
        {
        case '1':
            system("cls");
            arbolGeneral = menuPacientes(arbolGeneral);

            break;

        case '2':
            system("cls");
            arbolGeneral = menuPracticas(arbolGeneral,practicas,validos);

            break;

        case '3':
            system("cls");
            arbolGeneral = menuIngresos(arbolGeneral,practicas,validos);

            break;

        case '4':

            //menuEmpleados(archivoEmpleados);
            break;
        case ESC:
            system("cls");

            break;
        default:
            break;
        }


    }

}

nodoPaciente * menuPacientes(nodoPaciente * arbolGeneral)
{
    system("cls");
    printf("\t\t\t MENU PACIENTES\n");
    int opc;
    int dni=0;
    while(opc!=ESC)
    {
        printf("----------------------------------- \n");
        printf("1 - Ver listado de pacientes\n");
        printf("2 - Buscar paciente\n");
        printf("3 - Alta del paciente\n");
        printf("4 - Modificacion de un paciente\n");
        printf("ESC para ir al menu anterior \n");
        printf("----------------------------------- \n");
        fflush(stdin);
        opc = getch();
        system("cls");

        switch(opc)
        {
        case '1': //LISTADO DE PACIENTES

            mostrarPacientesOrdenadosAlfabeticamente(arbolGeneral); //funcion que muestra en orden de nombre y apellido

            break;

        case '2': //BUSCAR PACIENTE

            dni = obtenerDNI();
            nodoPaciente * buscado = buscaPaciente(arbolGeneral,dni);

            if(buscado == NULL)
            {
                printf("El paciente no esta cargado \n");

            }
            else   //VER
            {
                muestraPaciente(buscado->paciente);

            }
                break;

            case '3': //DAR DE ALTA UN PACIENTE

                arbolGeneral = altaPaciente(arbolGeneral);

                break;
            case '4':

                dni = obtenerDNI();
                nodoPaciente * buscadoo = buscaPaciente(arbolGeneral,dni);

                if(buscadoo == NULL)
                {
                    printf("El paciente no esta cargado \n");

                }
                else{

                    arbolGeneral = modificacionPaciente(arbolGeneral,dni);
                }

                break;
            case '5':
                printf("Usted selecciono la opcion 5 \n");
                break;
           case ESC:
                system("cls");
                return arbolGeneral;

            }
        }

        system("cls");

    return arbolGeneral;

}

////////void menuDoc()
////////{
////////
////////    printf("MENU TECNICOS Y BIOQUIMICOS");
////////
////////    printf("1- Cargar resultados"); //BUSQUEDA PACIENTE, VER PRACTICAS REALIZADAS, CARGAR RESULTADOS,
////////    printf("2- Alta/Baja practicas"); //ALTA Y BAJA DE PRACTICAS (si no tienen ingresos asociados)
////////
////////}
///menuPracticas(arbolGeneral,archivoPracticas);

nodoPaciente * menuPracticas(nodoPaciente*arbolGeneral,stPractica* practicas,int validos)
{
    system("cls");
    printf("\t\tMenu de Practicas\n");
    int opc;
    int dni=0;

    while(opc!=ESC)
    {
        printf("-----------------------------------");
        printf("1 - Ver listado de Practicas\n");
        printf("2 - Buscar Practiicas\n");
        printf("3 - Alta del Practiicas\n");
        printf("4 - Modificacion de un Practiicas\n");
        printf("-----------------------------------");
        fflush(stdin);
        opc=getch();

        switch(opc)
        {
        case '1':
            system("cls");
            mostrarPracticas(practicas,validos);
            break;

        case '2':
            printf("\nEn construccion....");
            system("pause");
            break;

        case '3':
            system("cls");
            cambiarEstadoPractica(practicas,validos);
            break;

        case '4':
            system("cls");
            modificacionPractica(practicas,validos);
            break;
        default:
            break;
        }

    }
    system("cls");
    return arbolGeneral;
}

nodoPaciente* menuIngresos(nodoPaciente* arbolGeneral,stPractica* practicas,int validos)
{
    system("cls");
    printf("\t\tMenu de Ingresos\n");
    int opc;
    int dni=0;


    while(opc!=ESC)
    {
        printf("1 - Ver listado de Ingresos\n");
        printf("2 - Buscar Ingreso\n");
        printf("3 - Alta del Ingreso\n");
        printf("4 - Modificacion de un Ingreso\n");
        fflush(stdin);
        opc = getch();

        switch(opc)
        {
        case'1':
                system("cls");
            mostrarIngresoPaciente(arbolGeneral);
            break;
        case'2':
                system("cls");
            buscaIngreso(arbolGeneral,1);
            break;
        case'3':
                system("cls");
            arbolGeneral = altaIngresos(arbolGeneral,practicas,validos);
            break;
        case'4':
                break;
        default:
            break;
        }
    }
    system("cls");
}

/*
void menuSec()
{

    printf("MENU ADMINISTRATIVO");

    printf("1- PACIENTES"); //VER, CARGAR NUEVOS, MODIFICAR ALGUNOS DATOS,
    printf("3- INGRESOS"); //CARGAR INGRESOS (cargar practica si o si), MODIFICAR DATOS INGRESOS

}


        mostrarPacientesOrdenadoNYA(arbolGeneral); //funcion que muestra en orden de nombre y apellido

    break;

    case 2:

            int dni =0;
            printf("Ingrese el dni del paciente");
            scanf("%i", dni);
            nodoPaciente * nodoPaciente = buscaPaciente(arbolGeneral,dni);

            if(paciente == NULL)
            {
                printf("El paciente no esta cargado");

            }else{ //VER

                muestraPaciente(nodoPaciente.paciente);

                printf("1 - Modificar datos del paciente");
                printf("2 - Volver al menu anterior");
                scanf("%i", opc);

                switch(opc)
                {
                case 1:

                    arbolGeneral = modificacionPaciente(arbolGeneral,nodoPaciente.paciente);

                    break;

                case 2:

                    default;
                }


            }



    }

    return arbolGeneral;
}

void menuDoc(){

    printf("MENU TECNICOS Y BIOQUIMICOS");

    printf("1- Cargar resultados"); //BUSQUEDA PACIENTE, VER PRACTICAS REALIZADAS, CARGAR RESULTADOS,
    printf("2- Alta/Baja practicas"); //ALTA Y BAJA DE PRACTICAS (si no tienen ingresos asociados)

}

void menuSec(){

    printf("MENU ADMINISTRATIVO");

    printf("1- PACIENTES"); //VER, CARGAR NUEVOS, MODIFICAR ALGUNOS DATOS,
    printf("3- INGRESOS"); //CARGAR INGRESOS (cargar practica si o si), MODIFICAR DATOS INGRESOS

}

*/
