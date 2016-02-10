#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


int max_int(int first, ...)
{
    va_list ap;
    int largest = first;

    va_start(ap, first);
    for(int current = va_arg(ap, int); current != 0; current = va_arg(ap, int))
        if(current > largest)
            largest = current;

    va_end(ap);
    return largest;

}


int main()
{
    printf("largest1: %d\n", max_int(1, 2, 3, 4, 0));
    printf("largest2: %d\n", max_int(-1, -2, -3, -4, 0));
    printf("largest3: %d\n", max_int(1, 2, 0, 4, 0));
    printf("largest4: %d\n", max_int(1, 0));
    printf("largest5: %d\n", max_int(0));

	exit(EXIT_SUCCESS);
}
