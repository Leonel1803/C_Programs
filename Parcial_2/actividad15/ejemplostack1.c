#include <stdio.h>
#include <string.h>
#include "stack.h"

int main()
{
	STACK s1 = stack_create();	// Crear un stack
	char s[20];
	char *str;
	char *str2;
	char *len = s;
	int cont = 0;

	printf("Dame un nombre: ");
	scanf("%s", s);

	while(*len != '\0'){
		cont += 1;
		len++;
	}

	for(int i = 0; i < cont; i++){
		stack_push(s1, char_create(s[i]));
	}

	str2 = stack_seek(s1);
	printf("Retorno stack _seek: %c\n\n", *str2);

	while(!stack_empty(s1))
	{
		str = stack_pop(s1);
		printf("%c", *str);
	}
	printf("\n");

	stack_destroy(s1);

	system("pause");
	return 0;
}

