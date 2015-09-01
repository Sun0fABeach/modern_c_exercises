#include "queueADT.h"

typedef struct element {
    struct element *next;
    Item item;
} Element;

typedef struct queue {
    Element *first;
    Element *last;
} Queue;


Queue *create()
{
    Queue *new = malloc(sizeof(Queue));
    if(!new) return NULL;

    new->first = new->last = NULL;

    return new;
}


void destroy(Queue *q)
{
    while(q->first) {
        Element *to_delete = q->first;
        q->first = q->first->next;
        free(to_delete);
    }
    free(q);
}


bool append(Queue *q, Item i)
{
    Element *new = malloc(sizeof(Element));
    if(!new) return false;
    new->next = NULL;
    new->item = i;

    if(is_empty(q))
        q->first = new;
    else
        q->last->next = new;

    q->last = new;

    return true;
}


Item shift(Queue *q)
{
    if(is_empty(q))
        return 0;

    Element *to_destroy = q->first;
    q->first = to_destroy->next;
    Item to_get = to_destroy->item;
    free(to_destroy);

    return to_get;
}


Item first(Queue *q)
{
    if(is_empty(q))
        return 0;
    return q->first->item;
}


Item last(Queue *q)
{
    if(is_empty(q))
        return 0;
    return q->last->item;
}


bool is_empty(Queue *q)
{
    return q->first == NULL;
}


bool is_full(Queue *q)
{
    return false;
}
