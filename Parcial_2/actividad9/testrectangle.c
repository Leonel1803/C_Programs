#include <stdio.h>
#include "rectangle.h"
// I N T E G R A N T E S
// LEON CARLO RIVER CARDENAS
// DAVID HERNANDEZ CAMACHO

int main() {
    RECT r1=new_rectangle(10.0,20.0);

    printf("Base del rectangulo %.1f\n",rectangle_base(r1));           // Deberá mostrar 10 en pantalla
    printf("Altura del rectangulo %.1f\n",rectangle_height(r1));       // Deberá mostrar 20 en pantalla
    printf("Area del rectangulo %.1f\n",rectangle_area(r1));           // Deberá mostrar 200 en pantalla
    printf("Perinetro del rectangulo %.1f\n",rectangle_perimeter(r1));  // Deberá mostrar 60 en pantalla

    rectangle_set_base(r1,12.0);
    rectangle_set_height(r1,15.0);

    printf("Base del rectangulo %.1f\n",rectangle_base(r1));           // Deberá mostrar 12 en pantalla
    printf("Altura del rectangulo %.1f\n",rectangle_height(r1));       // Deberá mostrar 15 en pantalla
    return 0;
}
