#ifndef PRACTICAS_H_INCLUDED
#define PRACTICAS_H_INCLUDED


ESTRUCTURA PRACTICA

- carga de estructura
- modificacion datos
- muestra estructura
- muestra del archivo completo

FUNCIONES EXTRA PEDIDAS

Listado general de practicas de laboratorio ordenadas por nombre.

    o Listado de practicas que “comiencen con”. En este caso debe poder filtrar todas las
practicas cuyo nombre comiencen con lo seleccionado por el usuario. Ejemplo: si se
elige la combinación “he”, deberían mostrarse practicas como: “hemograma o
hepatograma” etc.


void mostrarPracticas(char archivo []);
void modificacionPractica(char archivo[]);
int buscarporNombrePracticas(char archivo []);
void mostrarPractica(Practicas practica);
void baja_alta_practica(char archivo[]);

#endif // PRACTICAS_H_INCLUDED
