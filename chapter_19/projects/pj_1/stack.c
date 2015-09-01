#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct stack {
    size_t top, size;
    char content[];
} Stack;


static void stack_overflow(Stack *s)
{
    fputs("Stack overflow!", stderr);
    free(s);
    exit(EXIT_FAILURE);
}

static void stack_underflow(Stack *s)
{
    puts("Parantheses/braces are NOT nested properly");
    free(s);
    exit(EXIT_SUCCESS);
}

Stack *create_stack(size_t size)
{
    Stack *new = malloc(sizeof(Stack) + size);
    if(!new) {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }
    new->top = 0;
    new->size = size;
    return new;
}

void destroy_stack(Stack *s)
{
    free(s);
}

void make_empty(Stack *s)
{
    s->top = 0;
}

bool is_empty(Stack *s)
{
    return !s->top;
}

bool is_full(Stack *s)
{
    return s->top == s->size;
}

void push(Stack *s, char c)
{
    if(is_full(s))
        stack_overflow(s);
    else
        s->content[s->top++] = c;
}

char pop(Stack *s)
{
    if(is_empty(s))
        stack_underflow(s);
    else
        return s->content[--s->top];
}
