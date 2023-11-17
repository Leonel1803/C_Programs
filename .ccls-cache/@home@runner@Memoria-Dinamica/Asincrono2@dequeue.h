/*
 * dequeue.h
 *
 *  Created on: 20 mar 2023
 *      Author: jluis
 */

#ifndef DEQUEUE_H_
#define DEQUEUE_H_

#include "datatypes.h"

struct STR_DEQUEUE_NODE {
  /*
          Define los elementos que debe tener esta estructura que serán los
     nodos de la cola doblemente terminada que deben ser
                  - El elemento que se almacena
                  - El o los apuntadores a los nodos que pueden ser previo y/o
     siguiente
  */

  TYPE elem;
  struct STR_DEQUEUE_NODE *next, *prev;
};

struct STR_DEQUEUE {
  /*
          Define los elementos que debe tener esta estructura que contiene la
     información de la cola doblemente terminada como:
                  - Apuntadores al nodo frontal y trasero de la cola doblemente
     terminada
                  - Tamaño de la cola doblemente terminada, es decir la cantidad
     de elementos
  */

  struct STR_DEQUEUE_NODE *first, *last;
  int size;
};

typedef struct STR_DEQUEUE *DEQUEUE;

DEQUEUE dequeue_create();
void dequeue_insf(DEQUEUE d, TYPE e);
void dequeue_insr(DEQUEUE d, TYPE e);
BOOL dequeue_empty(DEQUEUE d);
int dequeue_size(DEQUEUE d);
TYPE dequeue_rmf(DEQUEUE d);
TYPE dequeue_rmr(DEQUEUE d);
TYPE dequeue_peekf(DEQUEUE d);
TYPE dequeue_peekr(DEQUEUE d);
void dequeue_destroy(DEQUEUE d);

#endif /* DEQUEUE_H_ */
