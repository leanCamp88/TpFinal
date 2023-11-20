#include "menus.h"
#include "arbolPacientes.h"
#include "listaIngresos.h"
#include "listaPracticas.h"
#include "login.h"
#include "practicas.h"
#include "empleados.h"

///altaIngresos(): cuando cargo ingreso no verifica la fecha

///probar altaIngresos

///probar escritura en archivo

///mostrarArbol() ??

///Menus






Empleado buscarCuenta(int dni)
{
    FILE* archi = fopen(archivoCuentas,"rb");
    Empleado lecturaArchivo;

    if(!archi)
    {
        printf("Error al abrir archivo para busqueda de Usuarios\n");
    }
    else
    {
        while(fread(&lecturaArchivo,sizeof(Empleado),1,archi) > 0)
        {
            if(lecturaArchivo.dni == dni)
            {
                fclose(archi);

                return lecturaArchivo;
            }
        }
    }


    fclose(archi);

    lecturaArchivo.dni = -1;

    return lecturaArchivo;

}


///FUNCIONES PARA MUESTRA DE EMPLEADOS://////////////////

void muestraUnEmpleado(Empleado muestraEmpleado)
{
    printf("Empleado %s : %s \n",muestraEmpleado.perfil,muestraEmpleado.apellidoYNombre);

    printf("DNI: %i \n",muestraEmpleado.dni);

    printf("Usuario: %s",muestraEmpleado.usuario);
    printf("Contrasenia: ******** \n");

}


void muestraUnEmpleadoAdmin(Empleado muestraEmpleado)
{
    printf("Empleado %s \n",muestraEmpleado.perfil);
    printf("Nombre y Apellido : %s \n",muestraEmpleado.apellidoYNombre);

    printf("DNI: %i \n",muestraEmpleado.dni);
    printf("Usuario: %s \n",muestraEmpleado.usuario);
    printf("Contrasenia: %s \n",muestraEmpleado.contrasenia);
}

void muestraEmpleadosAdmin(Empleado arregloEmpleados[],int validos)
{
    for (int i = 0; i < validos; i++)
    {
        muestraUnEmpleadoAdmin(arregloEmpleados[i]);
    }
}


void muestraEmpleados(Empleado arregloEmpleados[],int validos)
{
    for (int i = 0; i < validos; i++)
    {
        muestraUnEmpleado(arregloEmpleados[i]);
    }
}


/// FUNCION DE COMPARACION PARA QSORT()
int comparar_apellidos(const void *a, const void *b)
{
    return strcmp(((Empleado*)a)->apellidoYNombre, ((Empleado*)b)->apellidoYNombre);
}

/// REDIMENSIONA EL ARREGLO
Empleado* redimensionar(Empleado *arreglo,int *capacidad, size_t nuevo_tamano)
{
    *capacidad = nuevo_tamano;
    return realloc(arreglo, (*capacidad) * sizeof(Empleado));
}

///MUESTRA UN LISTADO DE EMPLEADOS
int listarEmpleados(int esAdmin)
{
    FILE *archivo = fopen(archivoCuentas,"rb");

    int capacidad = 10;

    Empleado *empleados = (Empleado*)malloc(sizeof(Empleado) * capacidad);

    int num_empleados = 0;

    if (!archivo)
    {
        printf("Error al abrir el archivo");
        return -1;
    }
    else
    {
        while (fread(&empleados[num_empleados], sizeof(Empleado), 1, archivo) == 1)
        {
            num_empleados++;

            if (num_empleados >= capacidad)
            {

                capacidad = capacidad * 2;

                empleados = redimensionar(empleados, &capacidad, capacidad);

                if (empleados == NULL)
                {
                    printf("Error al redimensionar el arreglo");

                    return -1;
                }
            }
        }

        /// Ordena el array de empleados alfabéticamente

        qsort(empleados, num_empleados, sizeof(Empleado),comparar_apellidos);

    }

    if(esAdmin)
    {
        muestraEmpleadosAdmin(empleados,num_empleados);
    }
    else
    {
        muestraEmpleados(empleados,num_empleados);
    }


    fclose(archivo);
    free(empleados);

    return 0;
}


///FIN MUESTRA EMPLEADOS//////////////////////////



///ALTA Y BAJA EMPLEADOS///////////////
void altaEmpleado()
{
    Empleado nuevoEmpleado;

    printf("Ingrese el DNI del nuevo Empleado: \n");
    fflush(stdin);
    scanf("%i",&nuevoEmpleado.dni);

    printf("Ingrese el Nombre y Apellido: \n");
    fflush(stdin);
    gets(nuevoEmpleado.apellidoYNombre);

    printf("Ingrese el Usuario: \n");
    fflush(stdin);
    gets(nuevoEmpleado.usuario);

    printf("Ingrese la contrasenia: \n");
    fflush(stdin);
    gets(nuevoEmpleado.contrasenia);

    printf("Ingrese el Perfil: \n");
    fflush(stdin);
    gets(nuevoEmpleado.perfil);

    nuevoEmpleado.eliminado = 0;

    FILE* archi = fopen(archivoCuentas,"ab");

    if(!archi)
    {
        printf("Error al arbrir archivo\n");
    }
    else
    {
        fwrite(&nuevoEmpleado,sizeof(Empleado),1,archi);
    }

    fclose(archi);
}


void bajaEmpleado(Empleado darBaja)
{
    darBaja.eliminado = 1;

    FILE* archi = fopen(archivoCuentas,"r+b");
    if(!archi)
    {
        printf("Error al abrir archivo, dar de baja\n");
    }
    else
    {
        Empleado buscado = buscarCuenta(darBaja.dni);

        if(buscado.dni > -1)
        {
            Empleado nuevo;

            while(fread(&nuevo,sizeof(Empleado),1,archi) > 0 )
            {
                if(darBaja.dni == nuevo.dni)
                {
                    fseek(archi,(-1) * sizeof(Empleado),SEEK_CUR);

                    fwrite(&darBaja,sizeof(Empleado),1,archi);
                }
            }
        }
        else
        {
            printf("El empleado no se encontro en el Sistema. /n");
        }
    }

    fclose(archi);
}


/// MODIFICACION DE EMPLEADOS/////////////////


int modificarEmpleado(int esAdmin)
{


    FILE* archi = fopen(archivoCuentas,"r+b");
    Empleado modificacion;

    if(!archi)
    {
        printf("Error al abrir el archivo\n");
        return -1;
    }
    else
    {
        printf("Ingrese el DNI del Empleado a modificar: /n");
        int dni = 0;

        scanf("%i",&dni);

        modificacion = buscarCuenta(dni);

        if(modificacion.dni == -1)
        {
            return -1;
        }

        printf("Empleado a Modificar:\n");
        muestraUnEmpleado(modificacion);

        getchar();

        printf("Elija opcion a modificar\n");
        printf("1)- Apellido y Nombre\n");
        printf("2)- DNI\n");
        printf("3)- Usuario\n");
        printf("4)- Contrasenia\n");
        printf("5)- Perfil\n");
        printf("6)- Estado\n");

        int opc = 0;

        fflush(stdin);

        opc = getchar();

        switch(opc)
        {
        case '1':
            system("cls");
            gets(modificacion.apellidoYNombre);
            break;
        case '2':
            system("cls");
            scanf("%i",&modificacion.dni);
            break;
        case '3':
            system("cls");
            gets(modificacion.usuario);
            break;
        case '4':
            system("cls");
            gets(modificacion.contrasenia);
            break;
        case '5':
            system("cls");
            gets(modificacion.perfil);
            break;
        case '6':
            system("cls");
            if(modificacion.eliminado)
            {
                modificacion.eliminado = 0;
            }
            else
            {
                modificacion.eliminado = 1;
            }
            break;
        default:
            printf("Error, porfavor seleccione opcion valida\n");
        }

        Empleado busqueda;
        while(fread(&busqueda,sizeof(Empleado),1,archi) == 1 )
        {
            if(modificacion.dni == busqueda.dni)
            {
                fseek(archi,(-1) * sizeof(Empleado),SEEK_CUR);

                fwrite(&modificacion,sizeof(Empleado),1,archi);
            }
        }

    }

    muestraUnEmpleadoAdmin(modificacion);

    return 1;
}


// Función para ocultar la contraseña
void ocultarPassword(char password[DIM])
{
    printf("Contrasenia: \n");
    fflush(stdin);

    int i = 0;
    char c;
    int j = 76;
    do
    {
        c = getchar();
        j++;
        if (c == 8 && i > 0)  // Verificar si se presionó la tecla de retroceso
        {
            j--;
            j--;

            printf(" ");
            if (i > 0)
            {
                i--;
            }
        }
        else
        {
            if (c != 13 && c != 10)  // Ignorar las teclas Enter
            {
                password[i++] = c;
                printf("*");
            }
        }
    }
    while (c != 13 && c != 10 && i < 30);

    password[i] = '\0'; // Agregar el carácter nulo de terminación al final de la cadena

}


/// Función principal de login
int login()
{
    FILE* archi = fopen(archivoCuentas,"r+b");

    Empleado logeando;
    Empleado lecturaArchivo;

    if(archi)
    {
        char control = 0;

        while (control != ESC)
        {



            printf("Usuario: \n");
            fflush(stdin);
            gets(logeando.usuario);

            char password[20];
            fflush(stdin);
            ocultarPassword(password);

            strcpy(logeando.contrasenia,password);

            int flag = 0;

            while( fread(&lecturaArchivo,sizeof(Empleado),1,archi) > 0 && flag == 0)
            {

                if( (strcmpi(lecturaArchivo.usuario,logeando.usuario) == 0) && (strcmpi(lecturaArchivo.contrasenia,password) == 0) )
                {
                    flag = 1;

                    printf("\nBienvenido, %s!\n",logeando.usuario);

                    if(strcmpi(logeando.perfil,"Administrador") == 0)
                    {
                        printf("Perfil: Administrador.\n");
                        fclose(archi);

                        return 1;
                    }
                    else if(strcmpi(logeando.perfil,"Administrativo") == 0)
                    {
                        printf("Eres un Administrativo.\n");
                        fclose(archi);

                        return 2;
                    }
                    else if (strcmpi(logeando.perfil,"Bioquimico") == 0)
                    {
                        printf("Eres un Bioquimico.\n");
                        fclose(archi);

                        return 3;
                    }
                    else
                    {
                        printf("Eres un Tecnico.\n");
                        fclose(archi);

                        return 4;
                    }
                }
            }

            system("cls");

            printf("\nNombre de usuario o contraseña incorrectos.\n");
            printf("\nDesea volver a ingresar ? ESC para salir, cualquier tecla para continuar. \n");

            control = getchar();
        }
    }
    else
    {
        printf("ERROR AL ABRIR ARCHIVO DE EMPLEADOS \n");
    }

    fclose(archi);

    return -1; // Falla en el login
}


