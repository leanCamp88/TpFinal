#include "login.h"

#include <stdio.h>
#include <string.h>


// Función para ocultar la contraseña
void ocultarPassword(char password[DIM])
{
    int i = 0;
    char c;

    printf("Ingrese la contraseña: ");

    // Lee el carácter de la consola sin mostrarlo
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i < (DIM - 1))
        {
            password[i++] = c;
            putchar('*'); // Muestra un '*' en lugar del carácter
        }
    }

    password[i] = '\0'; // Agrega el carácter nulo al final de la cadena
}

int buscarCuenta(char archivo[],Empleado busqueda)
{
    FILE* archi = fopen(archivo,"rb");
    if(!archi)
    {
        printf("Error al abrir archivo para busqueda de Usuarios\n");
    }
    else
    {
        Empleado lecturaARchivo;

        while(fread(&lecturaARchivo,sizeof(Empleado),1,archi) > 0)
        {
            if(strcmpi(lecturaARchivo.usuario,busqueda.usuario) == 0)
            {
                fclose(archi);
                return 1;
            }
        }
    }


fclose(archi);

return 0;
}


Empleado crearCuentaEmpleado()
{
    Empleado nuevoEmpleado;

    printf("Ingrese el DNI del nuevo Empleado: \n");
    scanf("%i",&nuevoEmpleado.dni);
    fflush(stdin);
    printf("Ingrese el Usuario: \n");
    gets(nuevoEmpleado.usuario);
    fflush(stdin);
    printf("Ingrese la contrasenia: \n");
    gets(nuevoEmpleado.contrasenia);
    fflush(stdin);
    printf("Ingrese el Perfil: \n");
    gets(nuevoEmpleado.perfil);
    fflush(stdin);

    FILE* archi = fopen(archivoCuentas,"ab");
    if(!archi)
    {
        printf("Error al arbrir archivo\n");
    }
    else
    {
        fwrite(&nuevoEmpleado,sizeof(Empleado),1,archi);
    }

return nuevoEmpleado;
}



/// Función principal de login
int login()
{
    FILE* archi = fopen(archivoCuentas,"rb");
    if(archi)
    {
        Empleado logeando;
        Empleado lecturaArchivo;
        char control = 0;

        printf("Ingrese el nombre de Usuario: \n");
        gets(logeando.usuario);

        ocultarPassword(&logeando.contrasenia);

        while (control != ESC)
        {

            while( fread(&lecturaArchivo,sizeof(Empleado),1,archi) > 0 )
            {

                if (strcmpi(lecturaArchivo.usuario, logeando.usuario) == 0 && strcmpi(lecturaArchivo.contrasenia, logeando.contrasenia) == 0)
                {
                    printf("¡Bienvenido, %s!\n", logeando.usuario);

                    if (strcmpi(logeando.perfil,"Administrador") == 0)
                    {
                        printf("Perfil: Administrador.\n");
                        fclose(archi);
                        return 1;
                    }
                    else if (strcmpi(logeando.perfil,"Administrativo") == 0)
                    {
                        printf("Eres un Administrativo.\n");
                        fclose(archi);
                        return 2;
                    }
                    else if (strcmpi(logeando.perfil,"Bioquimico") == 0)
                    {
                        printf("Eres un Bioquímico.\n");
                        fclose(archi);
                        return 3;
                    }
                    else
                    {
                        printf("Eres un Técnico.\n");
                        fclose(archi);
                        return 4;
                    }
                }
            }

            printf("Nombre de usuario o contraseña incorrectos.\n");
            printf("Desea volver a ingresar ? ESC para salir, cualquier tecla para continuar. \n");

            control = getch();
        }
    }
    else
    {
        printf("ERROR AL ABRIR ARCHIVO DE EMPLEADOS\n");
    }
    fclose(archi);

    return 0; // Falla en el login
}
