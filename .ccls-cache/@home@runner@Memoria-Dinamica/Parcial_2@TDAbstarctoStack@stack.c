#include "stack.h"
#include <stdlib.h>

STACK stack_create(){
    STACK new = malloc(sizeof(struct STR_STACK));

    new->top = NULL;
    new->size = 0;

    return new;
}

void stack_push(STACK s, TYPE e){
    struct STR_STACK_NODE *new = malloc(sizeof(struct STR_STACK_NODE));

    new->elem = e;
    new->prev = s->top;
    s->top = new;
    s->size = s->size++;
}

BOOL stack_empty(STACK s){
    return(s->top==NULL);
}

TYPE stack_pop(STACK s){
    TYPE elem = s->top->elem;
	struct STR_STACK_NODE *toremove = s->top;

	s->top = s->top->prev;
	s->size = s->size - 1;

	free(toremove);

	return elem;
}

void stack_destroy(STACK s){
    while(!stack_empty(s)){
        stack_pop(s);
    }
    free(s);
}