#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build_index_url(const char *domain, char *index_url)
{
    strcat(strcat(strcpy(index_url, "http://www."), domain), "/index.html");
}

int main()
{
    char index_url[100];
    const char *domain = "mofugga.org";

    build_index_url(domain, index_url);

    printf("url: %s\n", index_url);

    exit(EXIT_SUCCESS);
}
