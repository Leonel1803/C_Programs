// I N T E G R A N T E S
// LEON CARLO RIVER CARDENAS
// DAVID HERNANDEZ CAMACHO

#include "rectangle.h"

RECT new_rectangle(float x,float y)
{
    RECT r1 = malloc(sizeof(struct RECTANGLE));

    if(r1 == NULL){
        fprintf(stderr,"No se pudo alocar la memoria");
    }
    else
    {
        r1->b = x;
        r1->h = y;
    }

    return(r1);
}

float rectangle_base(RECT r1)
{
    return r1->b;
}


float rectangle_height(RECT r1)
{
    return r1->h;
}


float rectangle_area(RECT r1)
{
    return ((r1->b)*(r1->h));
}

float rectangle_perimeter(RECT r1)
{
    return ((2*r1->b)+(2*r1->h));
}


//Set:

void rectangle_set_base(RECT r1,float x)
{
    r1->b = x;
}

void rectangle_set_height(RECT r1,float y)
{
    r1->h = y;
}
