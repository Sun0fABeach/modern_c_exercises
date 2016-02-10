#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>


int myprintf(const char *format, ...)
{
    int count = 0;
    bool percent_encountered = false;
    va_list ap;

    va_start(ap, format);

    while(*format != '\0') {
        if(percent_encountered) {
            if(*format == 'd') {
                count += printf("%d", va_arg(ap, int));
            } else if(*format == 's') {
                count += printf("%s", va_arg(ap, char *));
            }
            percent_encountered = false;
        } else if(*format == '%') {
            percent_encountered = true;
        } else {
            putchar(*format);
            ++count;
        }
        ++format;
    }

    va_end(ap);
    return count;

}


int main()
{
    int count;

    count = myprintf("myprintf1: %d\n", 1);
    printf("count: %d\n", count);
    count = myprintf("myprintf1: %d\n", 100);
    printf("count: %d\n", count);
    count = myprintf("myprintf2: %dasd\n", 1);
    printf("count: %d\n", count);
    count = myprintf("myprintf3: %d%dasd\n", 1, 2);
    printf("count: %d\n", count);
    count = myprintf("myprintf4: %dx%dasd\n", 1, 2);
    printf("count: %d\n", count);
    count = myprintf("myprintf5\n");
    printf("count: %d\n", count);
    count = myprintf("myprintf6\n", 1);
    printf("count: %d\n", count);
    count = myprintf("%d\n", 1);
    printf("count: %d\n", count);

    count = myprintf("%s\n", "asdf");
    printf("count: %d\n", count);
    count = myprintf("%s\n", "");
    printf("count: %d\n", count);
    count = myprintf("%s%d\n", "asdf", 123);
    printf("count: %d\n", count);

    count = myprintf("%x%d\n", 123);
    printf("count: %d\n", count);
    count = myprintf("%s%y\n", "asdf");
    printf("count: %d\n", count);
    count = myprintf("%x");
    printf("count: %d\n", count);
    count = myprintf("");
    printf("count: %d\n", count);

	exit(EXIT_SUCCESS);
}
