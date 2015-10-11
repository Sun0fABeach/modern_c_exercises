#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main()
{
    Stack *s = create_stack(100);

    char c;
    printf("Enter parantheses and/or braces: ");

    while((c = getchar()) != '\n') {
        switch(c) {
            case '(': case '[': case '{':
                push(s, c); break;
            case ')':
                if(pop(s) != '(') {
                    puts("Parantheses/braces are NOT nested properly");
                    destroy_stack(s);
                    exit(EXIT_SUCCESS);
                }
                break;
            case ']':
                if(pop(s) != '[') {
                    puts("Parantheses/braces are NOT nested properly");
                    destroy_stack(s);
                    exit(EXIT_SUCCESS);
                }
                break;
            case '}':
                if(pop(s) != '{') {
                    puts("Parantheses/braces are NOT nested properly");
                    destroy_stack(s);
                    exit(EXIT_SUCCESS);
                }
        }
    }

    printf("Parantheses/braces are %snested properly\n",
            is_empty(s) ? "" : "NOT ");

    destroy_stack(s);

    exit(EXIT_SUCCESS);
}
