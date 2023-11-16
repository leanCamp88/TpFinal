#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"

void menuPrincipal(){

    int opcion;

    arbolPacientes* arbolPacientes = inicArbol();
    arbolPacientes = cargarArchivosEstructuras(archivoPacientes, archivoPracticasxIngreso, archivoIngresos, arbolPacientes);
    ///funcion que llama a las 3 funciones de lectura archivo

    do
    {

        printf("1. Login");
        printf("0. Salir"); //opc final para cargar datos nuevamente en archivos

        scanf("%i",opcion);

        switch(opcion)
        {
        case 1:

            empleado = login(char archivoEmpleados);
            arbolPacientes = menuPerfiles(empleado);

            break;

        case 0:

            guardadoEstructurasArchivos;

            break;
        }

    }
    while(opcion != 0);

}




nodoPaciente * menuPerfiles(stEmpleado perfil, nodoPaciente * arbolGeneral)
{
     switch(perfil.Usuario)¿?
    {
    case 1:
        arbolGeneral = menuAdministrador();
        break;

    case 2:

        arbolGeneral = menuProfesionales();
        break;

    case 3:

        arbolGeneral = menuAdministrativo();
        break;
    }

    return arbolGeneral;

}

nodoPaciente * menuAdmi(nodoPaciente * arbolGeneral, archivoEmpleados, archivoPracticas) //TODO
{
    int opc;
    printf("--------------------------------");
    printf("BIENVENIDO AL MENU ADMINISTRADOR");

    printf("1- PACIENTES"); // MODIFICACION, BAJA, ALTA, MUESTRA
    printf("2- PRACTICAS"); // MOFICICACION, BAJA, ALTA, MUESTRA
    printf("3- INGRESOS"); //MODIFICACION, BAJA, ALTA, MUESTRA
    printf("4- EMPLEADOS"); // MODIFICACION, BAJA, ALTA, MUESTRA
    scanf("%i", opc);

    switch(opc)
    {
        case 1:

            arbolGeneral = menuPacientes(arbolGeneral);

        break;

        case 2:

            arbolGeneral = menuPracticas(arbolGeneral,archivoPracticas);

        break;

        case 3:

            arbolGeneral = menuIngresos(arbolGeneral, archivoIngresos);

        break;

        case 4:

            menuEmpleados(archivoEmpleados);

    }



}

nodoPaciente * menuPacientes (nodoPaciente * arbolGeneral)
{
    int opc;

    printf("1 - Ver listado de pacientes");
    printf("2 - Buscar paciente");
    scanf("%i", opc);

    switch(opc)
    {
    case 1:

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


