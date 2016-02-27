#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main()
{
    unsigned char month1, month2, day1, day2;
    unsigned short year1, year2;

    printf("Enter first date (month/day/year): ");
    if(scanf("%hhu /%hhu /%hu", &month1, &day1, &year1) != 3) {
        puts("Read error!");
        exit(EXIT_FAILURE);
    }
    printf("Enter second date (month/day/year): ");
    if(scanf("%hhu /%hhu /%hu", &month2, &day2, &year2) != 3) {
        puts("Read error!");
        exit(EXIT_FAILURE);
    }

    struct tm t1 = {0};

    t1.tm_mon = month1-1;
    t1.tm_mday = day1;
    t1.tm_year = year1 - 1900;

    struct tm t2 = {0};

    t2.tm_mon = month2-1;
    t2.tm_mday = day2;
    t2.tm_year = year2 - 1900;

    printf(
        "That's a difference of %u days\n",
        (unsigned int)abs(difftime(mktime(&t1), mktime(&t2))) / (3600 * 24)
    );

	exit(EXIT_SUCCESS);
}
