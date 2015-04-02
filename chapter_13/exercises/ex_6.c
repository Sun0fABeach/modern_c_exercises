#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void censor(char *s)
{
    for(char *p = strstr(s, "foo"); p; p = strstr(s, "foo"))
        strncpy(p, "xxx", 3);
}

int main()
{
    char buff[20];

    printf("Type a line: ");
    fgets(buff, 20, stdin);

    censor(buff);
    printf("Censored: |%s|\n", buff);

    exit(EXIT_SUCCESS);
}
