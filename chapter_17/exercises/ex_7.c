#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node *next;
};


int main()
{
    struct node *list = calloc(1, sizeof(struct node)); //value: 0, next: NULL
    struct node *p = list;

    p->next = malloc(sizeof(struct node));
    p->next->value = 1;
    p = p->next;

    p->next = calloc(1, sizeof(struct node));
    p->next->value = 2;

    while(list) {
        p = list;
        list = list->next;
        free(p);
    }

    exit(EXIT_SUCCESS);
}
