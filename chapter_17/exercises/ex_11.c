#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int value;
    struct node *next;
} Node;


int count_occurences(Node *list, int value)
{
    int sum = 0;
    while(list) {
        if(list->value == value)
            sum++;
        list = list->next;
    }
    return sum;
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
    p = p->next;
    *p = (Node){3, NULL};
    p->next = malloc(sizeof(Node));
    p = p->next;
    *p = (Node){4, NULL};
    p->next = malloc(sizeof(Node));
    p = p->next;
    *p = (Node){2, NULL};

    printf("Number of 2s: %d\n", count_occurences(list, 2));

    exit(EXIT_SUCCESS);
}
