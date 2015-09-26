#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int main()
{
    char sales_rank[100];
    const char *format = "#%[0-9,]";

    sscanf("#1234", format, sales_rank);
    puts(sales_rank);
    sscanf("#12,34", format, sales_rank);
    puts(sales_rank);
    sscanf("#,1234", format, sales_rank);
    puts(sales_rank);
    sscanf("#1234,", format, sales_rank);
    puts(sales_rank);
    sscanf("#12,34.#+", format, sales_rank);
    puts(sales_rank);
    sscanf("#,.#+", format, sales_rank);
    puts(sales_rank);

    exit(EXIT_SUCCESS);
}
