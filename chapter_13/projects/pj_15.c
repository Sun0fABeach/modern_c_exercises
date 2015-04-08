#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

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

int evaluate_RPN_expression(const char *expression)
{
    int result;

    while(true) {
        while(isspace(*expression))
            expression++;
        if(isdigit(*expression))
            push(*expression - '0');
        else
            switch(*expression) {
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
                    result = pop();
                    make_empty();
                    return result;
                default:
                    printf("Unknown symbol: %c\n", *expression);
                    make_empty();
                    return 0;
            }
        expression++;
    }
}

int main()
{
    char buf[100];

    while(true) {
        printf("Enter an RPN expression: ");
        fgets(buf, 100, stdin);
        if(*buf == '\n')
            break;
        printf("Value of the expression: %d\n", evaluate_RPN_expression(buf));
    }

    exit(EXIT_SUCCESS);
}
