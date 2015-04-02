#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_filename(char *url)
{
    *strrchr(url, '/') = '\0';
}

int main()
{
    char s[100] = "http://www.shit.de/index.html";
    remove_filename(s);
    puts(s);

    exit(EXIT_SUCCESS);
}
