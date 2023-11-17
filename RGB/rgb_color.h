#ifndef RGB_COLOR_H_
#define RGB_COLOR_H_

#include <stdio.h>
#include <stdlib.h>


struct RGB_COLOR_STR {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

typedef struct RGB_COLOR_STR * RGB_COLOR;

// Encabezados de las funciones
RGB_COLOR rgb_color_create(unsigned char red,unsigned char green,unsigned char blue);

void rgb_color_set_red(RGB_COLOR c,unsigned char red);
void rgb_color_set_green(RGB_COLOR c,unsigned char green);
void rgb_color_set_blue(RGB_COLOR c,unsigned char blue);

unsigned char rgb_color_get_red(RGB_COLOR c);
unsigned char rgb_color_get_green(RGB_COLOR c);
unsigned char rgb_color_get_blue(RGB_COLOR c);

void rgb_color_print(RGB_COLOR c);
void rgb_color_destroy(RGB_COLOR c);

#endif /* RGB_COLOR_H_ */
