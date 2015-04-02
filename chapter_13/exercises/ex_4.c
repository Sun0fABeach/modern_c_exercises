#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int read_line(char str[], int n)
{
    int i = 0;

    scanf(" ");
    while(i < n-1)
        if((str[i++] = getchar()) == '\n')
            break;
    str[i] = '\0';

    return i;
}

int main()
{
    char buff[20];

    printf("Type a line: ");
    read_line(buff, 20);

    printf("You typed: |%s|\n", buff);

    exit(EXIT_SUCCESS);
}
