#include <stdlib.h>
#include "stack.h"

typedef struct stack {
    unsigned int max_size;
    unsigned int content_size;
    int content[];
} Stack;


Stack *new_stack(unsigned int size)
{
    Stack *new_stack = malloc(sizeof(Stack) + size*sizeof(int));
    new_stack->max_size = size;
    new_stack->content_size = 0;
    return new_stack;
}

bool push(Stack *stack, int item)
{
    if(is_full(stack))
        return false;
    stack->content[stack->content_size++] = item;
    return true;
}

int pop(Stack *stack)
{
    if(is_empty(stack))
        return 0;
    return stack->content[--stack->content_size];
}

bool is_empty(Stack *stack)
{
    return stack->content_size == 0;
}

bool is_full(Stack *stack)
{
    return stack->content_size == stack->max_size;
}

void make_empty(Stack *stack)
{
    stack->content_size = 0;
}

void destroy(Stack *stack)
{
    free(stack);
}

