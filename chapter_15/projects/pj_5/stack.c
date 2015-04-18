#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 10

int contents[STACK_SIZE];
int top = 0;

void stack_overflow()
{
    fputs("Expression is too complex\n", stderr);
    exit(EXIT_FAILURE);
}

void stack_underflow()
{
    fputs("Not enough operands in expression\n", stderr);
    exit(EXIT_FAILURE);
}

void make_empty()
{
    top = 0;
}

bool is_empty()
{
    return !top;
}

bool is_full()
{
    return top == STACK_SIZE;
}

void push(int c)
{
    if(is_full())
        stack_overflow();
    else
        contents[top++] = c;
}

int pop()
{
    if(is_empty())
        stack_underflow();
    else
        return contents[--top];
}
