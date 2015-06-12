#include <stdio.h>
#include "queue.h"

#define QUEUE_SIZE 3

static int next_slot = 0, next_remove = 0;
static unsigned int num_items = 0;
static Item queue[QUEUE_SIZE];

static inline void move_forwards(int *index);


void append(Item i)
{
    if(is_full()) {
        fputs("Queue is full, can't append\n", stderr);
        return;
    }
    queue[next_slot] = i;
    num_items++;
    move_forwards(&next_slot);
}

Item shift()
{
    if(is_empty()) {
        fputs("Queue is empty, can't shift\n", stderr);
        return 0;
    }
    Item to_return = queue[next_remove];
    num_items--;
    move_forwards(&next_remove);
    return to_return;
}

Item first()
{
    if(is_empty()) {
        fputs("Queue is empty\n", stderr);
        return 0;
    }
    return queue[next_remove];
}

Item last()
{
    if(is_empty()) {
        fputs("Queue is empty\n", stderr);
        return 0;
    }
    return queue[next_slot-1 < 0 ? QUEUE_SIZE-1 : next_slot-1];
}

bool is_empty()
{
    return num_items == 0;
}

bool is_full()
{
    return num_items == QUEUE_SIZE;
}

static inline void move_forwards(int *index)
{
    if(++*index == QUEUE_SIZE)
        *index = 0;
}
