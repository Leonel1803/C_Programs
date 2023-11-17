/*
 * queue.c
 *
 *  Created on: 17 mar 2023
 *      Author: jluis
 */
#include "queue.h"

QUEUE queue_create()
{
	QUEUE new = malloc(sizeof(struct STR_QUEUE));

	new->front = NULL;
	new->rear = NULL;
	new->size = 0;

	return(new);
}

void queue_offer(QUEUE q,TYPE e)
{
	struct STR_QUEUE_NODE *new = malloc(sizeof(struct STR_QUEUE_NODE));
    new->elem = e;
    new->next = NULL; // asegura que el nuevo nodo tenga el puntero "next" inicializado en nulo

    if (q->front == NULL) { // cola vacía
        q->front = new;
        q->rear = new;
    } else { // cola no vacía
        q->rear->next = new;
        q->rear = new;
    }

    q->size = q->size + 1;
}

BOOL queue_empty(QUEUE q)
{
	return(q->front == NULL);
}

TYPE queue_poll(QUEUE q)
{
	TYPE elem = NULL;
	struct STR_QUEUE_NODE *toremove;

	if(q->front!=NULL)
	{
		toremove = q->front;
		elem = q->front->elem;
		q->front = q->front->next;
		q->size = q->size - 1;
		free(toremove);
	}

	return elem;
}

TYPE queue_peek(QUEUE q)
{
	return(q->front);
}

void queue_destroy(QUEUE q)
{
	while(!queue_empty(q))
		queue_poll(q);
	free(q);
}
