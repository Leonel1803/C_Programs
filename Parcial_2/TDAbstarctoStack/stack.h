#ifndef STACK_H_
#define STACK_H_

typedef void * TYPE;
typedef int BOOL;

struct STR_STACK_NODE{ //Stack
    //void *elem;
    TYPE *elem;
    struct STR_STACK_NODE *prev;
};

struct STR_STACK{ //Descripción del stack
    struct STR_STACK_NODE *top; //Tope del stack
    int size; //Tamaño del stack
};

typedef struct STR_STACK * STACK;

STACK stack_create();
void stack_push(STACK s, TYPE e);
BOOL stack_empty(STACK s);
TYPE stack_pop(STACK s);
void stack_destroy(STACK s);

#endif
