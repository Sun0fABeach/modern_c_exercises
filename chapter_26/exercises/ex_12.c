#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


time_t first_day_12am(unsigned short year)
{
    struct tm t = {0};

    t.tm_year = year - 1900;
    t.tm_mday = 1;
    t.tm_hour = 12;

    time_t ret = mktime(&t);

    printf("tm_sec: %d\n", t.tm_sec);
    printf("tm_min: %d\n", t.tm_min);
    printf("tm_hour: %d\n", t.tm_hour);
    printf("tm_mday: %d\n", t.tm_mday);
    printf("tm_mon: %d\n", t.tm_mon);
    printf("tm_year: %d\n", t.tm_year);
    printf("tm_wday: %d\n", t.tm_wday);
    printf("tm_yday: %d\n", t.tm_yday);
    printf("tm_isdst: %d\n", t.tm_isdst);

    return ret;
}


int main()
{
    printf("time_t for year 2016: %ld\n", first_day_12am(2016));

	exit(EXIT_SUCCESS);
}
