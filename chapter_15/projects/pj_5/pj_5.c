#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int main()
{
    char c;
    printf("Enter an RPN expression: ");

    while(true) {
        scanf(" %c", &c);
        if(isdigit(c))
            push(c - '0');
        else
            switch(c) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                push(pop() - pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                push(pop() / pop());
                break;
            case '=':
                printf("Value of the expression: %d\n", pop());
                make_empty();
                printf("Enter an RPN expression: ");
                break;
            default:
                exit(EXIT_SUCCESS);
            }
    }
}
