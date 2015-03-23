#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
char *top = contents;

void stack_overflow()
{
    fputs("Stack overflow!", stderr);
    exit(EXIT_FAILURE);
}

void stack_underflow()
{
    puts("Parantheses/braces are NOT nested properly");
    exit(EXIT_SUCCESS);
}

void make_empty()
{
    top = contents;
}

bool is_empty()
{
    return top == contents;
}

bool is_full()
{
    return top == contents + STACK_SIZE;
}

void push(char c)
{
    if(is_full())
        stack_overflow();
    else
        *top++ = c;
}

char pop()
{
    if(is_empty())
        stack_underflow();
    else
        return *--top;
}

int main()
{
    char c;
    printf("Enter parantheses and/or braces: ");

    while((c = getchar()) != '\n') {
        switch(c) {
            case '(': case '[': case '{':
                push(c); break;
            case ')':
                if(pop() != '(') {
                    puts("Parantheses/braces are NOT nested properly");
                    exit(EXIT_SUCCESS);
                }
                break;
            case ']':
                if(pop() != '[') {
                    puts("Parantheses/braces are NOT nested properly");
                    exit(EXIT_SUCCESS);
                }
                break;
            case '}':
                if(pop() != '{') {
                    puts("Parantheses/braces are NOT nested properly");
                    exit(EXIT_SUCCESS);
                }
        }
    }

    printf("Parantheses/braces are %snested properly\n",
            is_empty() ? "" : "NOT ");

    exit(EXIT_SUCCESS);
}
