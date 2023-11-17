#include "date.h"

#include <stdio.h>
#include <stdlib.h>

FECHAS date_create(int dia, int mes, int year){
    FECHAS fecha = malloc(sizeof(struct FECHAS_STR));
    
    if(fecha!=NULL)
	{
		if(year > 2023 || year < 0){
            fecha->year = 1970;
        }
        else{
            fecha->year = year;
        }


        if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && (mes == 2) && (dia <= 29 && dia > 0)){ //Bisisesto
            fecha->dia = dia;
        }
        else if((year % 4 != 0 && year % 100 == 0 || year % 400 != 0)  && (mes == 2) && (dia >= 29 || dia <= 0)){ //No bisiesto
            fecha->dia = 1;
        }
        else if((mes == 1 && (dia > 31 || dia <= 0)) || (mes == 3 && (dia > 31 || dia <= 0)) || (mes == 5 && (dia > 31 || dia <= 0)) || (mes == 7 && (dia > 31 || dia <= 0)) || (mes == 8 && (dia > 31 || dia <= 0)) || (mes == 10 && (dia > 31 || dia <= 0)) || (mes == 12 && (dia > 31 || dia <= 0))){
            fecha->dia = 1;
        }
        else if((mes == 4 && (dia > 30 || dia <= 0)) || (mes == 6 && (dia > 30 || dia <= 0)) || (mes == 9 && (dia > 30 || dia <= 0)) || (mes == 11 && (dia > 30 || dia <= 0))){
            fecha->dia = 1;
        }
        else{
            fecha->dia = dia;
        }

        if(mes > 12 || mes < 1){
            fecha->mes = 1;
        }
        else{
            fecha->mes = mes;
        }
	}
    return fecha;
}

void date_add(FECHAS fecha, int dias){
    while(dias > 0){
        if((fecha->mes == 1 || fecha->mes == 3 || fecha->mes == 5 || fecha->mes == 7 || fecha->mes == 8 || fecha->mes == 10 || fecha->mes == 12) && (fecha->dia + 1 == 32)){
            fecha->mes += 1;
            fecha->dia = 1;
            if(fecha->mes == 13){
                fecha->year += 1;
                fecha->mes = 1;
                fecha->dia = 1;
            }
        }
        else if((fecha->mes == 4 || fecha->mes == 6 || fecha->mes == 9 || fecha->mes == 11) && (fecha->dia + 1 == 31)){
            fecha->mes += 1;
            fecha->dia = 1;
            if(fecha->mes == 13){
                fecha->year += 1;
                fecha->mes = 1;
                fecha->dia = 1;
            }
        }
        else if((fecha->year % 4 == 0 && fecha->year % 100 != 0 || fecha->year % 400 == 0) && (fecha->mes == 2) && (fecha->dia + 1 == 30)){ //Bisiseto
            fecha->mes += 1;
            fecha->dia = 1;
        }
        else if((fecha->year % 4 != 0 && fecha->year % 100 == 0 || fecha->year % 400 != 0) && (fecha->mes == 2) && (fecha->dia + 1 == 39)){ // NO Bisiseto
            fecha->mes += 1;
            fecha->dia = 1;
        }
        else{
            fecha->dia += 1; 
        }
        dias--;
    }
}

void date_sub(FECHAS fecha, int dias){
    while(dias > 0){
        if((fecha->mes == 5 || fecha->mes == 7 || fecha->mes == 10 || fecha->mes == 12) && (fecha->dia - 1 == 0)){ //El mes anterior a... es de 30 dias
            fecha->mes -= 1;
            fecha->dia = 30;
        }
        else if((fecha->mes == 1 || fecha->mes == 2 || fecha->mes == 4 || fecha->mes == 6 || fecha->mes == 8 || fecha->mes == 9 || fecha->mes == 11) && (fecha->dia - 1 == 0)){ //El mes anterior a... es de 31 dias
            fecha->mes -= 1;
            fecha->dia = 31;
            if(fecha->mes == 0){
                fecha->year -= 1;
                fecha->mes = 12;
                fecha->dia = 31;
            } 
        }
        else if((fecha->year % 4 == 0 && fecha->year % 100 != 0 || fecha->year % 400 == 0) && (fecha->mes == 3) && (fecha->dia - 1 == 0)){ //El mes anterior a... es de 29 dias po ser bisiesto
            fecha->mes -= 1;
            fecha->dia = 29;
        }
        else if((fecha->year % 4 != 0 && fecha->year % 100 == 0 || fecha->year % 400 != 0) && (fecha->mes == 3) && (fecha->dia - 1 == 0)){ //El mes anterior a... es de 28 dias por NO ser bisiesto
            fecha->mes -= 1;
            fecha->dia = 28;
        }
    }
}

void date_print(FECHAS fecha){
    printf("\n{La fecha es: %d/%d/%d}\n\n", fecha->dia, fecha->mes, fecha->year);
}

void date_destroy(FECHAS fecha){
    free(fecha);
}