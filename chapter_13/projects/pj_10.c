#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void reverse_name(char *name)
{
    char *c = name, initial;

    while(isspace(*c)) c++;
    initial = *c;
    while(!isspace(*c)) c++;
    while(isspace(*c)) c++;
    while(!isspace(*c))
        *name++ = *c++;
    sprintf(name, ", %c", initial);
}

int main()
{
    char s[100];

    printf("Enter a first and last name: ");
    fgets(s, 100, stdin);

    reverse_name(s);
    puts(s);

    exit(EXIT_SUCCESS);
}
