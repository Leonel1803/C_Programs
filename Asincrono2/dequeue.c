#include "dequeue.h"
#include <stdio.h>

DEQUEUE dequeue_create() {
  /*
          Función que crea el nodo en memoria dinámica que contiene la
     información de la cola doblemente terminada.
  */

  DEQUEUE new = malloc(sizeof(struct STR_DEQUEUE));

  new->first = NULL;
  new->last = NULL;
  new->size = 0;

  return new;
}

void dequeue_insr(DEQUEUE d, TYPE e) {
  /*
          Función para insertar un nodo en la parte trasera (al final) de la
     cola doblemente terminada
  */

  struct STR_DEQUEUE_NODE *new;
  new = malloc(sizeof(struct STR_DEQUEUE_NODE));
  new->elem = e;
  new->next = NULL; // Se iguala a NULL para que no acumule basura
  new->prev = NULL; // Se iguala a NULL para que no acumule basura

  if (d->first == NULL) {
    d->first = new;
    d->last = new;
  } else {
    struct STR_DEQUEUE_NODE *ptr;
    ptr = d->last;
    d->last->next = new;
    d->last = new;
    d->last->prev = ptr;
  }
  d->size = d->size + 1;
}

void dequeue_insf(DEQUEUE d, TYPE e) {
  /*
          Función para insertar un nodo al frente (al principio) de la cola
     doblemente terminada
  */

  struct STR_DEQUEUE_NODE *new;
  new = malloc(sizeof(struct STR_DEQUEUE_NODE));
  new->elem = e;
  new->prev = NULL; // Se iguala a NULL para que no acumule basura
  new->next = NULL; // Se iguala a NULL para que no acumule basura

  if (d->first == NULL) {
    d->last = new;
    d->first = new;
  } else {
    struct STR_DEQUEUE_NODE *ptr;
    ptr = d->first;
    d->first->prev = new;
    d->first = new;
    d->first->next = ptr;
  }

  d->size = d->size + 1;
}

BOOL dequeue_empty(DEQUEUE d) {
  /*
          Función que regresa verdadero si la cola doblemente terminada está
     vacía
  */

  return (d->first == NULL && d->last == NULL);
}

int dequeue_size(DEQUEUE d) {
  /*
          Función que regresa la cantidad de elementos que contiene la cola
     doblemente terminada
  */

  return d->size;
}

TYPE dequeue_rmf(DEQUEUE d) {
  /*
          Función que devuelve el elemento y remueve de la parte frontal de la
     cola doblemente terminada
  */

  TYPE elem = NULL;
  struct STR_DEQUEUE_NODE *toremove;
  if (d->last != NULL) {
    elem = d->first->elem;
    toremove = d->first;
    if (d->first->next != NULL) { // Hasta que ya no haya más nodos por borrar,
                                  // entonces se les dará null a first y last
      d->first = d->first->next;
    } else { // Se iguala a NULL para poder vaciar los nodos
      d->first = NULL;
      d->last = NULL;
    }
    free(toremove);
    d->size = d->size - 1;
  }
  return elem;
}

TYPE dequeue_rmr(DEQUEUE d) {
  /*
          Función que devuelve el elemento y remueve de la parte trasera de la
     cola doblemente terminada
  */

  TYPE elem = NULL;
  struct STR_DEQUEUE_NODE *toremove;
  if (d->first != NULL) {
    elem = d->last->elem;
    toremove = d->last;
    if (d->last->prev != NULL) { // Hasra que ya no haya más nodos por borrar,
                                 // entonces se les dará null a first y last
      d->last = d->last->prev;
    } else { // Se iguala a NULL para poder vaciar los nodos
      d->last = NULL;
      d->first = NULL;
    }
    free(toremove);
    d->size = d->size - 1;
  }
  return elem;
}

TYPE dequeue_peekf(DEQUEUE d) {
  /*
          Función que devuelve el elemento de la parte frontal de la cola
     doblemente terminada, más no lo remueve
  */

  TYPE elem = NULL;

  if (d->first != NULL) {
    elem = d->first->elem;
  }

  return elem;
}

TYPE dequeue_peekr(DEQUEUE d) {
  /*
          Función que devuelve el elemento de la parte trasera de la cola
     doblemente terminada, más no lo remueve
  */

  TYPE elem = NULL;

  if (d->last != NULL) {
    elem = d->last->elem;
  }

  return elem;
}

void dequeue_destroy(DEQUEUE d) {
  /*
          Función que elimina todos los nodos de la cola doblemente terminada,
     liberando la memoria
  */

  while (!dequeue_empty(d)) {
    dequeue_rmf(d);
    dequeue_rmr(d);
  }
  free(d);
}
