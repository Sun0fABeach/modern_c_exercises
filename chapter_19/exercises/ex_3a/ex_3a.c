#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main()
{
    if(is_empty()) {
        puts("queue empty");
    }
    puts("Querying first...");
    first();
    puts("Querying last...");
    last();

    puts("Appending 1");
    append(1);

    puts("Querying first...");
    printf("%d\n", first());
    puts("Querying last...");
    printf("%d\n", last());

    puts("Appending 2");
    append(2);
    puts("Appending 3");
    append(3);
    puts("Appending 4");
    append(4);

    puts("Querying first...");
    printf("%d\n", first());
    puts("Querying last...");
    printf("%d\n", last());

    puts("Shifting...");
    printf("%d\n", shift());
    puts("Shifting...");
    printf("%d\n", shift());
    puts("Shifting...");
    printf("%d\n", shift());
    puts("Shifting...");
    printf("%d\n", shift());

    exit(EXIT_SUCCESS);
}
