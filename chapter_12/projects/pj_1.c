#include <stdio.h>
#include <stdlib.h>

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
    while(--p >= buff)
        putchar(*p);
    putchar('\n');

    exit(EXIT_SUCCESS);
}
