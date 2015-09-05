#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    struct {
        int flag: 1;
    } s1;

    struct {
        unsigned int flag: 1;
    } s2;

    s1.flag = s2.flag = 1;

    printf("s1: %d, s2: %d\n", s1.flag, s2.flag);

    exit(EXIT_SUCCESS);
}
