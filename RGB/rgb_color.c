#include "rgb_color.h"

RGB_COLOR rgb_color_create(unsigned char red,unsigned char green,unsigned char blue)
{
	RGB_COLOR color = malloc(sizeof(struct RGB_COLOR_STR));
	if(color!=NULL)
	{
		color->red = red;
		color->green = green;
		color->blue = blue;
	}
	return color;

}
void rgb_color_set_red(RGB_COLOR c,unsigned char red)
{
	c->red = red;
}
void rgb_color_set_green(RGB_COLOR c,unsigned char green)
{
	c->green = green;
}

void rgb_color_set_blue(RGB_COLOR c,unsigned char blue)
{
	c->blue = blue;
}

unsigned char rgb_color_get_red(RGB_COLOR c)
{
	return c->red;
}

unsigned char rgb_color_get_green(RGB_COLOR c)
{
	return c->green;
}

unsigned char rgb_color_get_blue(RGB_COLOR c)
{
	return c->blue;
}

void rgb_color_print(RGB_COLOR c)
{
	printf("{\n");
	printf("\t\"red\":%d,\n",c->red);
	printf("\t\"green\":%d,\n",c->green);
	printf("\t\"blue\":%d\n",c->blue);
	printf("}\n");
}
void rgb_color_destroy(RGB_COLOR c)
{
	free(c);
}

