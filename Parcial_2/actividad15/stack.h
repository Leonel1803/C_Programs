
#ifndef STACK_H_
#define STACK_H_

#include "datatypes.h"

struct STR_STACK_NODE {
	TYPE elem;
	struct STR_STACK_NODE *prev;
};

struct STR_STACK {
	struct STR_STACK_NODE *top;
	int size;
};

typedef struct STR_STACK * STACK;

STACK stack_create();
void stack_push(STACK s,TYPE e);
BOOL stack_empty(STACK s);
TYPE stack_pop(STACK s);
void stack_destroy(STACK s);
TYPE stack_seek(STACK s);


#endif /* STACK_H_ */
