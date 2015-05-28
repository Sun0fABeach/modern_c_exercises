#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int value;
    struct node *next;
} Node;


Node *insert_into_ordered_list(Node *list, Node *new_node)
{
    if(!list) {
        list = new_node;
        list->next = NULL;
        return list;
    }

    Node *cur = list, *prev = NULL;

    while(cur && new_node->value >= cur->value) {
        prev = cur;
        cur = cur->next;
    }

    if(prev)
        prev->next = new_node;
    else
        list = new_node;

    new_node->next = cur;

    return list;
}


void delete_from_list(Node **list, int value)
{
    Node *cur, *prev;

    for(cur = *list, prev = NULL;
        cur && cur->value != value;
        prev = cur, cur = cur->next)
        ;

    if(cur == NULL) return;
    if(prev == NULL) *list = (*list)->next;
    else prev->next = cur->next;

    free(cur);
}


void print_list(Node *list)
{
    puts("list:");
    while(list) {
        printf("%d\n", list->value);
        list = list->next;
    }
}


int main()
{
    Node *list = NULL;
    Node *p = malloc(sizeof(Node));
    *p = (Node){3, NULL};
    list = insert_into_ordered_list(list, p);

    p = malloc(sizeof(Node));
    *p = (Node){2, NULL};
    list = insert_into_ordered_list(list, p);

    p = malloc(sizeof(Node));
    *p = (Node){5, NULL};
    list = insert_into_ordered_list(list, p);

    p = malloc(sizeof(Node));
    *p = (Node){4, NULL};
    list = insert_into_ordered_list(list, p);

    print_list(list);
    delete_from_list(&list, 4);
    delete_from_list(&list, 2);
    print_list(list);

    while(list) {
        p = list;
        list = list->next;
        free(p);
    }

    exit(EXIT_SUCCESS);
}
