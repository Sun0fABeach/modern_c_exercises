#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>
#include <stdlib.h>

typedef struct queue Queue;
typedef int Item;

Queue *create();
void destroy(Queue *q);
bool append(Queue *q, Item i);
Item shift(Queue *q);
Item first(Queue *q);
Item last(Queue *q);
bool is_empty(Queue *q);
bool is_full(Queue *q);

#endif
