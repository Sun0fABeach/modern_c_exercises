#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main()
{
    int a[4] = {7, 11, 15, 19};
    srand(time(NULL));
    int n = a[rand() % 4];
    printf("%d\n", n);

	exit(EXIT_SUCCESS);
}
