#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.h"


int main()
{
    char c;
    Stack *s = create_stack(100);

    printf("Enter an RPN expression: ");

    while(true) {
        scanf(" %c", &c);
        if(isdigit(c))
            push(s, c - '0');
        else
            switch(c) {
            case '+':
                push(s, pop(s) + pop(s));
                break;
            case '-':
                push(s, pop(s) - pop(s));
                break;
            case '*':
                push(s, pop(s) * pop(s));
                break;
            case '/':
                push(s, pop(s) / pop(s));
                break;
            case '=':
                printf("Value of the expression: %d\n", pop(s));
                make_empty(s);
                printf("Enter an RPN expression: ");
                break;
            default:
                destroy_stack(s);
                exit(EXIT_SUCCESS);
            }
    }
}
