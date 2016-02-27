#include <stdlib.h>
#include <stdio.h>


void thats_all()
{
    printf("That's all, ");
}

void folks()
{
    puts("folks!");
}

int main()
{
    atexit(folks);
    atexit(thats_all);

	exit(EXIT_SUCCESS);
}
