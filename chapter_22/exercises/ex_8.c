#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    char str[2];
    int n;
    const char *s = " a";
    n = sscanf(s, " %c", str);
    printf("n:%d str:%1s\n", n, str);
    n = sscanf(s, "%1s", str);
    printf("n:%d str:%1s\n", n, str);

    exit(EXIT_SUCCESS);
}
