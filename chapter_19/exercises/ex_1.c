#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef struct queue *Queue;
typedef int Item;

Queue create(int size);
void destroy(Queue q);
void append(Queue q, Item i);
Item shift(Queue q);
Item first(Queue q);
Item last(Queue q);
bool is_empty(Queue q);

#endif
