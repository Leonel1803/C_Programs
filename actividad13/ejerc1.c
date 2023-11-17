#include <stdio.h>
#include <stdlib.h>

struct STRNUM {
	int num;
	struct STRNUM *next;
};

typedef struct {
	struct STRNUM *first;
} LIST;

void insert(LIST *l,int n);

int main(){
    LIST lista = {NULL};
	struct STRNUM *ptr = NULL,*todestroy = NULL;

    int n;

    printf("Hasta que numero quieres que se verifique que numeros son primos: ");
    scanf("%d", &n);
    printf("\n");

    ptr = lista.first;
    int cont = 0; //Contara cuantos primos hay ya en la lista
    int pnp = 0;

    for(int i = 0; i <= n ; i++){
        struct STRNUM *ptr2 = lista.first;
        for(int j = 0; j <= cont ; i++){
            if((cont == 0) || (i%(ptr2->num) == 0) || (pnp != 1)){
                cont++;
                insert(&lista,i);
                pnp = 1;
            }
            else{
                ptr2->next;
            }
        }
        pnp = 0;
    }

    // Recorrer la lista y mostrar los números
	ptr = lista.first;

	// Mientras no llegue al final de la lista
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->num);
		ptr = ptr->next;
	}

    return 0;
}

void insert(LIST *l,int n)
{
	// Crear el nodo
	struct STRNUM *new = malloc(sizeof(struct STRNUM));

	// Poner los valores en la estructura
	new->num = n;
	new->next = NULL;
}