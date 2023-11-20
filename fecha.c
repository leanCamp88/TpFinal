#include "fecha.h"
#include "time.h"

stFecha cargarFecha()
{
    stFecha fecha;

    printf("Ingrese el dia");
    scanf("%i",&fecha.dia);
    printf("Ingrese el mes");
    scanf("%i",&fecha.mes);
    printf("Ingrese el anio");
    scanf("%i",&fecha.anio);

    return fecha;
}

stFecha obtenerFechaActual() {

    stFecha fechaActual;

    time_t tiempoActual;
    struct tm *infoTiempo;

    time(&tiempoActual);
    infoTiempo = localtime(&tiempoActual);

    fechaActual.dia = infoTiempo->tm_mday;
    fechaActual.mes = infoTiempo->tm_mon + 1;
    fechaActual.anio = infoTiempo->tm_year + 1900;

    return fechaActual;
}

int verificarFechaFutura(stFecha fechaIngresada) {

    stFecha fechaActual = obtenerFechaActual();

    if (fechaIngresada.anio < fechaActual.anio)
    {
        return 0;  // Año pasado, no es futura

    } else if (fechaIngresada.anio == fechaActual.anio)
        {
            if (fechaIngresada.mes < fechaActual.mes)
            {
                return 0;  // Mismo año, pero mes pasado, no es futura

            } else if (fechaIngresada.mes == fechaActual.mes)
                {
                    if (fechaIngresada.dia <= fechaActual.dia)
                    {
                            return 0;  // Mismo mes, pero día pasado o igual, no es futura
                    }
                }
        }

    return 1;  // La fecha es futura
}

int esBisiesto(int anio) {

    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);

}
int verificarFecha(stFecha fecha, stFecha fechaActual) {

    if (fecha.anio < 0 || fecha.mes < 1 || fecha.mes > 12 || fecha.dia < 1) {
        return 0;  // Fecha inválida
    }

    int diasEnMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajustar días en febrero para años bisiestos

    if (fecha.mes == 2 && esBisiesto(fecha.anio)) {

        diasEnMes[2] = 29;

    }

    if (fecha.dia > diasEnMes[fecha.mes]) {

        return 0;  // Día inválido para el mes dado

    }

    // Verificar que la fecha sea futura
    if (fecha.anio < fechaActual.anio) {

        return 0;  // Año pasado, no es futura

    } else if (fecha.anio == fechaActual.anio) {

        if (fecha.mes < fechaActual.mes) {

            return 0;  // Mismo año, pero mes pasado, no es futura

        } else if (fecha.mes == fechaActual.mes) {

            if (fecha.dia <= fechaActual.dia) {

                return 0;  // Mismo mes, pero día pasado o igual, no es futura
            }
        }
    }

    return 1;  // Fecha válida y futura
}
stFecha ingresarFecha() {

    stFecha fecha;
    stFecha fechaActual = obtenerFechaActual();

    while (1) {

        fecha = cargarFecha();
        printf("aca");

        // Validar que se ingresen números y el formato correcto

        if (verificarFecha(fecha, fechaActual) == 1) {

            break;  // La fecha es válida y futura, salir del bucle

        } else {
                printf("Fecha ingresada: %02d/%02d/%04d\n", fecha.dia, fecha.mes, fecha.anio);
                printf("Fecha actual: %02d/%02d/%04d\n", fechaActual.dia, fechaActual.mes, fechaActual.anio);

            if (verificarFecha(fecha, fechaActual) != 1)
            {
                printf("La fecha no es válida.\n");
            }

            if (verificarFechaFutura(fecha) != 1)
            {
                printf("La fecha no es futura.\n");
            }

            printf("La fecha ingresada no es válida o no es futura. Intenta nuevamente.\n");

            }
        }

    return fecha;
}
