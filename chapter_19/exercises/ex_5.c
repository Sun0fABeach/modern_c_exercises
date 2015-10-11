#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

#define QUEUE_SIZE 100

typedef int Item;
typedef struct queue {
    Item contents[QUEUE_SIZE];
} Queue;

void append(Queue *q, Item i);
Item shift(Queue *q);
Item first(Queue *q);
Item last(Queue *q);
bool is_empty(Queue *q);

#endif
