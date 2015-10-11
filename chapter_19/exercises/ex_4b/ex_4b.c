#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


int main()
{
    Stack *s = new_stack(3);
    printf("Push of %d\n", 1);
    push(s, 1);
    printf("Push of %d\n", 2);
    push(s, 2);
    printf("Push of %d\n", 3);
    push(s, 3);
    printf("Push of %d\n", 4);
    push(s, 4);

    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));

    if(is_empty(s))
        puts("Stack empty");

    printf("Push of %d\n", 1);
    push(s, 1);
    printf("Push of %d\n", 2);
    push(s, 2);

    puts("Emptying...");
    make_empty(s);
    if(is_empty(s))
        puts("Successful");

    destroy(s);

    exit(EXIT_SUCCESS);
}
