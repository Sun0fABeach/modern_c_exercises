#include <stdlib.h>
#include "stack.h"

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;


Stack *new_stack()
{
    return calloc(1, sizeof(Stack));
}

void push(Stack *stack, int item)
{
    Node *new = malloc(sizeof(Node));
    *new = (Node){item, NULL};
    if(stack->top)
        new->next = stack->top;
    stack->top = new;
}

int pop(Stack *stack)
{
    if(is_empty(stack))
        return 0;
    int to_return = stack->top->item;
    Node *to_destroy = stack->top;
    stack->top = stack->top->next;
    free(to_destroy);
    return to_return;
}

bool is_empty(Stack *stack)
{
    return stack->top == NULL;
}

void make_empty(Stack *stack)
{
    Node *to_destroy;
    while(stack->top) {
        to_destroy = stack->top;
        stack->top = stack->top->next;
        free(to_destroy);
    }
}

void destroy(Stack *stack)
{
    make_empty(stack);
    free(stack);
}

