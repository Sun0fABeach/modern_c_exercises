#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    printf("%.1f\n", rand() % 10 / 10.0);

	exit(EXIT_SUCCESS);
}
