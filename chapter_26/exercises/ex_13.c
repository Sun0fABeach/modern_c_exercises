#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TMSIZE 50


int main()
{
    struct tm t = {0};

    t.tm_year = 116;
    t.tm_mday = 1;
    t.tm_hour = 12;

    mktime(&t);

    char s[TMSIZE];

    strftime(s, TMSIZE, "%Y-%j", &t);
    puts(s);
    strftime(s, TMSIZE, "%Y-%U-%u", &t);
    puts(s);
    strftime(s, TMSIZE, "%F %T", &t);
    puts(s);

	exit(EXIT_SUCCESS);
}
