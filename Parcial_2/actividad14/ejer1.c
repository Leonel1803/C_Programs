#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 20

struct STRNODE {
  int num;
  struct STRNODE *next;
};

typedef struct {
  struct STRNODE *first;
  struct STRNODE *last;
} LIST;

#define LISTINIT                                                               \
  { NULL, NULL }

void insert(LIST *list, int num);
int found(LIST list, int num);
void display(LIST list);
void destroy(LIST list);

int main() {
  LIST l = LISTINIT;
  int i, n;

  srand(time(NULL));

  for (i = 0; i < LIMIT; i++) {
    n = rand() % LIMIT;
    if (!found(l, n))
      insert(&l, n);
  }

  display(l);
  destroy(l);
}

int found(LIST list,int num)
{
  struct STRNODE *aptr =NULL;
  if(num>=0)
		{
			aptr = list.first; 

			while(aptr->num!=num  && aptr!=NULL){ //mientras el numero no sea igual y el apuntador no llegue al final
				aptr = aptr->next; 
        }

			if(aptr==NULL)
				return 0; 
      else 
        return 1;
	}
}

void insert(LIST *list,int num) // Se crea la lista encadenada
{
	struct STRNODE *new = malloc(sizeof(struct STRNODE));

	new->num = num;
	new->next = NULL;

	if(list->first==NULL)
		list->first = new;
	else
		list->last->next = new; //list contiene a last, y last apunta a la estructura que contiene next

	list->last = new;
}

void display(LIST list)//se imprime la lista
{
	struct STRNODE *aptr = list.first;

	while(aptr!=NULL)
	{
		printf("%d\n",aptr->num);
		aptr = aptr->next;
	} 
}

void destroy(LIST list)
{
  struct STRNODE *aptr =NULL;
  struct STRNUM *ad = NULL;
  
	aptr= list.first;
	while(aptr!=NULL)
	{
		ad = aptr;
		aptr = aptr->next;
		free(ad);
	}
}