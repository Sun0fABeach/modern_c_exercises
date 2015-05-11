#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node *next;
};


struct node *delete_from_list(struct node *list, int n)
{
    if(!list) return NULL;

    struct node *p = list;

    if(list->value == n) {
        list = list->next;
        free(p);
        return list;
    }

    while(p->next) {
        if(p->next->value == n) {
            struct node *to_delete = p->next;
            p->next = p->next->next;
            free(to_delete);
        }
        p = p->next;
    }

    return list;
}


void print_list(struct node *list)
{
    puts("Printing list...");
    while(list) {
        printf("Node value: %d\n", list->value);
        list = list->next;
    }
}


int main()
{
    struct node *list = calloc(1, sizeof(struct node)); //value: 0, next: NULL
    struct node *p = list;

    p->next = malloc(sizeof(struct node));
    p->next->value = 1;
    p = p->next;

    p->next = calloc(1, sizeof(struct node));
    p->next->value = 2;

    print_list(list);

    list = delete_from_list(list, 1);
    print_list(list);

    list = delete_from_list(list, 0);
    print_list(list);

    list = delete_from_list(list, 2);
    print_list(list);

    exit(EXIT_SUCCESS);
}
