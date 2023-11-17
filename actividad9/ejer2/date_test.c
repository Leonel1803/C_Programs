#include "date.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int year, dia, mes;
    int dias;
    int opcion;
    printf("Bienvenido al ejercicio 2\nDime el año de tu fecha: ");
    scanf(" %d", &year);
    printf("\nDime el mes de tu fecha: ");
    scanf(" %d", &mes);
    printf("\nDime el año de tu fecha: ");
    scanf(" %d", &year);

    FECHAS fecha = date_create(dia, mes, year);

    printf("1) Imprimir fecha\2) Sumar dias a la fecha\n3) Restar dias a la fecha\n4) Borrar fecha y poner una nueva\n5) Cerrar programa\nElige: ");
    scanf(" %d", &opcion);
    if(opcion == 1){
        date_print(fecha);
    }
    else if(opcion == 2){
        printf("Dias que quieres aumentar: ");
        scanf(" %d", &dias);
        date_add(fecha, dias);
    }
    else if(opcion == 3){
        printf("Dias que quieres restar: ");
        scanf(" %d", &dias);
        date_sub(fecha, dias);
    }
   else if(opcion == 4){
        date_destroy(fecha);
   }

   return 0;
    
}