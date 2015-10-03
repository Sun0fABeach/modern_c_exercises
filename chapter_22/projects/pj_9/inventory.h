#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#define NAME_LEN 25
#define MAX_PARTS 100

typedef struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} Part;

#endif
