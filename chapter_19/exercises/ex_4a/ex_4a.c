#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


int main()
{
    Stack *s = new_stack(3);
    printf("Push of %d: %s\n", 1, push(s, 1) ? "successful" : "failed");
    printf("Push of %d: %s\n", 2, push(s, 2) ? "successful" : "failed");
    printf("Push of %d: %s\n", 3, push(s, 3) ? "successful" : "failed");
    printf("Push of %d: %s\n", 4, push(s, 4) ? "successful" : "failed");

    if(is_full(s))
        puts("Stack full");

    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));
    printf("Popped %d\n", pop(s));

    if(is_empty(s))
        puts("Stack empty");

    printf("Push of %d: %s\n", 1, push(s, 1) ? "successful" : "failed");
    printf("Push of %d: %s\n", 2, push(s, 2) ? "successful" : "failed");

    puts("Emptying...");
    make_empty(s);
    if(is_empty(s))
        puts("Successful");

    destroy(s);

    exit(EXIT_SUCCESS);
}
