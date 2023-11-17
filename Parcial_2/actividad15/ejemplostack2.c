#include <stdio.h>
#include "stack.h"

int main()
{
	STACK s1 = stack_create();	// Crear un stack
	// int arr[] = {1,2,3,4,5,6,7};
	int i = 0;
	int *numptr;
	while(1){
		printf("Introduce un numero (0 para terminar): ");
		scanf("%d", &i);
		if(i != 0){
			stack_push(s1, int_create(i));
		}
		else{
			break;
		}
	}

	numptr = stack_seek(s1);
	printf("Retorno stack _seek: %d\n\n", *numptr);

	while(!stack_empty(s1))
	{
		numptr = stack_pop(s1);		// Saco el apuntador que está guardado como elemento
									// del stack, y en este caso es un apuntador a un
									// número
		printf("%d\n",*numptr);		// *numptr refiero al contenido
	}

	stack_destroy(s1);

	system("pause");
	return 0;
}

