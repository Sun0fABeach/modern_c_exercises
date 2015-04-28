#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int month;
    int day;
    int year;
} Date;

int day_of_year(Date d)
{
    return (d.month-1) * 31 + d.day;
}

int compare_dates(Date d1, Date d2)
{
    int x = day_of_year(d1);
    int y = day_of_year(d2);
    return x < y ? -1 : x > y ? 1 : 0;
}

int main()
{
    Date d1 = {10, 2, 1999};
    Date d2 = {6, 29, 1978};

    printf("%d\n", day_of_year(d1));
    printf("%d\n", compare_dates(d1, d2));

    exit(EXIT_SUCCESS);
}
