// I N T E G R A N T E S
// LEON CARLO RIVER CARDENAS
// DAVID HERNANDEZ CAMACHO

#ifndef ACTIVIDAD_9_0_RECTANGLE_H
#define ACTIVIDAD_9_0_RECTANGLE_H
#include <stdio.h>
#include <stdlib.h>

struct RECTANGLE
{
    float b;
    float h;
};

typedef struct RECTANGLE * RECT;
RECT new_rectangle(float x,float y);

float rectangle_base(RECT r1);
float rectangle_height(RECT r1);
float rectangle_area(RECT r1);
float rectangle_perimeter(RECT r1);

void rectangle_set_base(RECT r1,float b);
void rectangle_set_height(RECT r1,float h);


#endif //ACTIVIDAD_9_0_RECTANGLE_H
