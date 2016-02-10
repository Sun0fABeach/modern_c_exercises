#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


void display(unsigned int count, ...)
{
    va_list ap;

    va_start(ap, count);

    while(count--)
        printf("%s%s", va_arg(ap, char *), count == 0 ? "\n" : " ");

    va_end(ap);
}


int main()
{
    display(1, "one");
    display(2, "one", "two");
    display(1, "one", "two");
    display(0);
    display(0, "zero");

	exit(EXIT_SUCCESS);
}
