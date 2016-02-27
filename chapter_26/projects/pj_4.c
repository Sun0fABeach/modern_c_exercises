#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main()
{
    unsigned char month, day;
    unsigned short year, n;

    printf("Enter date (month/day/year): ");
    if(scanf("%hhu /%hhu /%hu", &month, &day, &year) != 3) {
        puts("Read error!");
        exit(EXIT_FAILURE);
    }
    printf("Enter number of days later: ");
    if(scanf("%hu", &n) != 1) {
        puts("Read error!");
        exit(EXIT_FAILURE);
    }

    struct tm t = {0};

    t.tm_mon = month-1;
    t.tm_mday = day + n;
    t.tm_year = year - 1900;

    mktime(&t);

    printf("%hu days later is the following date:\n", n);
    printf("%hhu/%hhu/%hu\n", t.tm_mon + 1, t.tm_mday, t.tm_year + 1900);

	exit(EXIT_SUCCESS);
}
