#include "rgb_color.h"

int main()
{
	RGB_COLOR c1 = rgb_color_create(100,30,87);
	RGB_COLOR c2 = rgb_color_create(70,90,27);

	rgb_color_print(c1);
	rgb_color_print(c2);
}

