#include "queueADT.h"


typedef struct queue {
    size_t capacity;
    size_t size;
    Item *append_slot;
    Item *remove_slot;
    Item *contents;
} *Queue;


static inline void move_slot(Queue q, Item **slot);


Queue create(size_t capacity)
{
    Queue new = malloc(sizeof(*new));
    if(!new) return NULL;

    new->contents = malloc(capacity * sizeof(Item));
    if(!new->contents) {
        free(new);
        return NULL;
    }

    new->capacity = capacity;
    new->size = 0;
    new->append_slot = new->remove_slot = new->contents;

    return new;
}


void destroy(Queue q)
{
    free(q->contents);
    free(q);
}


void append(Queue q, Item i)
{
    *q->append_slot = i;
    move_slot(q, &q->append_slot);

    if(is_full(q))
        move_slot(q, &q->remove_slot);  // overwrite happened
    else
        q->size++;
}


Item shift(Queue q)
{
    if(is_empty(q))
        return 0;

    Item i = *q->remove_slot;
    move_slot(q, &q->remove_slot);
    q->size--;

    return i;
}


Item first(Queue q)
{
    if(is_empty(q))
        return 0;
    return *q->remove_slot;
}


Item last(Queue q)
{
    if(is_empty(q))
        return 0;
    if(q->append_slot == q->contents)
       return *(q->contents + q->capacity - 1);
    return *(q->append_slot - 1);
}


bool is_empty(Queue q)
{
    return q->size == 0;
}


bool is_full(Queue q)
{
    return q->size == q->capacity;
}


static inline void move_slot(Queue q, Item **slot)
{
    if(++*slot == q->contents + q->capacity)
        *slot = q->contents;
}
