#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_reverse(char *offset, char *array_start)
{
    while(--offset >= array_start)
        putchar(*offset);
    putchar('\n');
}

int main()
{
    char buff[20], *p = buff;

    printf("Enter a message: ");
    while(p < buff + 20) {
        if((*p = getchar()) == '\n')
            break;
        p++;
    }

    printf("Reversal is: ");
    print_reverse(p, buff);

    exit(EXIT_SUCCESS);
}
