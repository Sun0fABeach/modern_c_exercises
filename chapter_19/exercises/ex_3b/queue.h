#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef int Item;

void append(Item i);
Item shift();
Item first();
Item last();
bool is_empty();
bool is_full();

#endif
