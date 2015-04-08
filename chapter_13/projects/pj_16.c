#include <stdio.h>
#include <stdlib.h>

void reverse(char *message)
{
    char tmp, *end = message;

    while(*end)
        end++;
    end--;

    while(message < end) {
        tmp = *message;
        *message = *end;
        *end = tmp;
        message++, end--;
    }
}

int main()
{
    char buff[20];
    int i;

    printf("Enter a message: ");
    for(i = 0; i < 19; i++)
        if((buff[i] = getchar()) == '\n')
            break;
    buff[i] = '\0';
    reverse(buff);
    printf("Reversed: %s\n", buff);

    exit(EXIT_SUCCESS);
}
