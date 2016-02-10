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
    myprintf("myprintf1: %d\n", 1);
    myprintf("myprintf1: %d\n", 100);
    myprintf("myprintf2: %dasd\n", 1);
    myprintf("myprintf3: %d%dasd\n", 1, 2);
    myprintf("myprintf4: %dx%dasd\n", 1, 2);
    myprintf("myprintf5\n");
    myprintf("myprintf6\n", 1);
    myprintf("%d\n", 1);
    myprintf("");

	exit(EXIT_SUCCESS);
}
