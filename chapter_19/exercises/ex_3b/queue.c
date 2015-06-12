#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node {
    Item item;
    struct node *next;
} Node;

static unsigned int num_items = 0;
static Node *first_node = NULL, *last_node = NULL;


void append(Item i)
{
    Node *new = malloc(sizeof(Node));
    new->item = i;
    new->next = NULL;
    if(last_node) {
        last_node->next = new;
        last_node = new;
    } else
        first_node = last_node = new;
    num_items++;
}

Item shift()
{
    if(is_empty()) {
        fputs("Queue is empty, can't shift\n", stderr);
        return 0;
    }
    Item to_return = first_node->item;
    Node *to_delete = first_node;
    first_node = first_node->next;
    free(to_delete);
    num_items--;
    return to_return;
}

Item first()
{
    if(is_empty()) {
        fputs("Queue is empty\n", stderr);
        return 0;
    }
    return first_node->item;
}

Item last()
{
    if(is_empty()) {
        fputs("Queue is empty\n", stderr);
        return 0;
    }
    return last_node->item;
}

bool is_empty()
{
    return first_node == NULL;
}
