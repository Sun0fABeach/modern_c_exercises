#include <stdio.h>
#include <stdlib.h>


typedef struct {
    unsigned char month;
    unsigned char day;
    unsigned short year;
} Date;

unsigned short sum_days(Date d)
{
    return d.year*365u + (d.month-1u)*31u + d.day;
}

signed char compare_dates(Date d1, Date d2)
{
    unsigned short x = sum_days(d1);
    unsigned short y = sum_days(d2);
    return x < y ? -1 : x > y ? 1 : 0;
}

int main()
{
    Date d1, d2;

    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%2hhu /%2hhu /%4hu", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%2hhu /%2hhu /%4hu", &d2.month, &d2.day, &d2.year);

    switch(compare_dates(d1, d2)) {
        case -1:
            puts("First date comes earlier!");
            break;
        case 1:
            puts("Second date comes earlier!");
            break;
        default:
            puts("Both dates are the same!");
    }

    exit(EXIT_SUCCESS);
}
