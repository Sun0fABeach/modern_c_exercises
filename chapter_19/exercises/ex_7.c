/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackADT2.c (Chapter 19, page 498) */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int Item;

typedef struct stack_type {
  Item *contents;
  int top;
  int size;
} *Stack;

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(int size)
{
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL)
    terminate("Error in create: stack could not be created.");
  s->contents = malloc(size * sizeof(Item));
  if (s->contents == NULL) {
    free(s);
    terminate("Error in create: stack could not be created.");
  }
  s->top = 0;
  s->size = size;
  return s;
}

void destroy(Stack s)
{
  free(s->contents);
  free(s);
}

void make_empty(Stack s)
{
  s->top = 0;
}

bool is_empty(Stack s)
{
  return s->top == 0;
}

bool is_full(Stack s)
{
  return s->top == s->size;
}

Item pop(Stack s)
{
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
  return s->contents[--s->top];
}

void push(Stack s, Item i)
{
    if(is_full(s)) {
        Item *old_contents = s->contents;
        s->contents = malloc(2 * s->size * sizeof(Item));
        if(!s->contents)
            terminate("Error in push: failed to double size.");
        s->size = 2 * s->size;

        for(int i = 0; i < s->top; i++)
            s->contents[i] = old_contents[i];

        free(old_contents);
    }

    s->contents[s->top++] = i;
}


int main()
{
    Stack s = create(1);
    assert(s->size == 1);
    push(s, 0);
    assert(is_full(s));
    push(s, 1);
    assert(s->size == 2);
    assert(is_full(s));
    assert(pop(s) == 1);
    assert(pop(s) == 0);
    assert(is_empty(s));

    destroy(s);

    exit(EXIT_SUCCESS);
}
