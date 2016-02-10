#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


char *max_pair(int num_pairs, ...)
{
    if(num_pairs <= 0)
        return NULL;

    va_list ap;
    va_start(ap, num_pairs);
    int max_num = va_arg(ap, int);
    const char *max_name = va_arg(ap, char *);

    while(--num_pairs) {
        int num = va_arg(ap, int);
        const char *name = va_arg(ap, char *);
        if(num > max_num) {
            max_num = num;
            max_name = name;
        }
    }

    va_end(ap);
    return (char *) max_name;
}


int main()
{
    printf("%s\n", max_pair(1, 3, "three"));
    printf("%s\n", max_pair(2, 3, "three", 4, "four"));
    printf("%s\n", max_pair(2, 3, "three", 2, "two"));
    printf("%s\n", max_pair(2, 3, "three", 4, "four", 5, "five"));
    if(max_pair(0, 1, "one") == NULL)
        puts("error check passed");

	exit(EXIT_SUCCESS);
}
