#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main()
{
    srand(time(NULL));

    for(int i = 0; i < 1000; ++i) {
        int lob = rand() & 1;
        printf("%s%d", (i % 80 == 0 && i != 0) ? "\n" : "", lob % 2);
    }
    putchar('\n');

	exit(EXIT_SUCCESS);
}
