#include "menus.h"
#include "Pacientes.h"
#include "listaIngresos.h
#include "listaPracticas.h"

void menuPrincipal(){

    int opcion;

    arbolPacientes* arbolPacientes = inicArbol();
    arbolPacientes = cargarArchivosEstructuras(archivoPacientes, archivoPracticasxIngreso, archivoIngresos, arbolPacientes); ///funcion que llama a las 3 funciones de lectura archivo

    do
    {

        printf("1. Login");
        printf("2. Registrarse");
        printf("0. Salir"); //opc final para cargar datos nuevamente en archivos

        scanf("%i",opcion);

        switch(opcion)
        {
        case 1:

            login();

            break;

        case 2:

            registro();

            break;

        case 0:


            break;
        }

    }
    while(opcion != 0);

}


void login(){

    menuPerfiles(perfil);

}

void ingreso()
{
    menuPerfiles(perfil);
}

void menuPerfiles(perfil)
{
     switch(perfil)
    {
    case 1:
        menuAdmi();
        break;

    case 2:

        menuDoc();
        break;

    case 3:

        menuSec();
        break;
    }

}

void menuAdmi() //TODO
{

    printf("MENU ADMINISTRADOR");

    printf("1- PACIENTES"); // MODIFICACION, BAJA, ALTA, MUESTRA
    printf("2- PRACTICAS"); // MOFICICACION, BAJA, ALTA, MUESTRA
    printf("3- INGRESOS"); //MODIFICACION, BAJA, ALTA, MUESTRA
    printf("4- EMPLEADOS"); // MODIFICACION, BAJA, ALTA, MUESTRA



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


