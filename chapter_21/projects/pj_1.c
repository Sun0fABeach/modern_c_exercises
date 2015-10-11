#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

int main()
{
    struct s {
        char a;
        int b[2];
        float c;
    } x;

    printf("Size of struct: %zd\n", sizeof(x));
    printf("Size of member a: %zd\n", sizeof(x.a));
    printf("Size of member b: %zd\n", sizeof(x.b));
    printf("Size of member c: %zd\n", sizeof(x.c));
    printf("Offset of member a: %zd\n", offsetof(struct s, a));
    printf("Offset of member b: %zd\n", offsetof(struct s, b));
    printf("Offset of member c: %zd\n", offsetof(struct s, c));

    exit(EXIT_SUCCESS);
}
