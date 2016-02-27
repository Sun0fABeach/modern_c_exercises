#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main()
{
    time_t tt = time(NULL);
    struct tm *t = localtime(&tt);

    char s[100];

    strftime(s, 100, "%A, %B, %Y  %I:%M%p", t);
    puts(s);
    strftime(s, 100, "%a, %d %b %y  %H:%M", t);
    puts(s);
    strftime(s, 100, "%x  %r", t);
    puts(s);

	exit(EXIT_SUCCESS);
}
