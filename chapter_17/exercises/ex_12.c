#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int value;
    struct node *next;
} Node;


Node *find_last(Node *list, int value)
{
    Node *last = NULL;
    while(list) {
        if(list->value == value)
            last = list;
        list = list->next;
    }
    return last;
}

int main()
{
    Node *list = malloc(sizeof(Node));
    Node *p = list;
    *p = (Node){1, NULL};
    p->next = malloc(sizeof(Node));
    p = p->next;
    *p = (Node){2, NULL};
    p->next = malloc(sizeof(Node));
    printf("First node containing value 2: %p\n", p);
    p = p->next;
    *p = (Node){3, NULL};
    p->next = malloc(sizeof(Node));
    p = p->next;
    *p = (Node){4, NULL};
    p->next = malloc(sizeof(Node));
    p = p->next;
    *p = (Node){2, NULL};

    printf("Last node containing value 2: %p\n", find_last(list, 2));

    exit(EXIT_SUCCESS);
}
