#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    while(--argc)
        sum += atoi(argv[argc]);
    printf("Sum: %d\n", sum);

    exit(EXIT_SUCCESS);
}
