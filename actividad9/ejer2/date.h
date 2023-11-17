#ifndef FECHAS_H_
#define FECHAS_H_

#include <stdio.h>
#include <stdlib.h>

// Definición del TDA para FECHAS
struct FECHAS_STR{
    int dia, mes, year;
};

// Exponer, ¿cómo lo pueden ver desde el programa?
// Ocultar los datos que están adentro
typedef struct FECHAS_STR * FECHAS;

// Encabezados de las funciones para las operaciones del VEC3
// Solo la definición y no la implementación
FECHAS date_create(int dia, int mes, int year);
void date_add(FECHAS fecha, int dias);
void date_sub(FECHAS fecha, int dias);
void date_print(FECHAS fecha);
void date_destroy(FECHAS fecha);

#endif