/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* stackclient.c (Chapter 19, page 494) */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
  Stack s1, s2;
  char *s;

  s1 = create();
  s2 = create();

  push(s1, "a");
  puts("Pushed a onto stack 1");
  push(s1, "b");
  puts("Pushed b onto stack 1");

  s = pop(s1);
  printf("Popped %s from s1\n", s);
  push(s2, s);
  printf("Pushed %s onto stack 2\n", s);
  s = pop(s1);
  printf("Popped %s from s1\n", s);
  push(s2, s);
  printf("Pushed %s onto stack 2\n", s);

  destroy(s1);
  puts("Destroyed stack 1");

  while (!is_empty(s2))
    printf("Popped %s from s2\n", (char *)pop(s2));

  push(s2, "c");
  puts("Pushed c onto stack 2");
  make_empty(s2);
  puts("Emptied stack 2");
  if (is_empty(s2))
    printf("s2 is empty\n");
  else
    printf("s2 is not empty\n");

  destroy(s2);

  exit(EXIT_SUCCESS);
}
