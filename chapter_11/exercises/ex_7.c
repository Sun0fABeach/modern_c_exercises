#include <stdio.h>
#include <stdlib.h>

void split_date(int day_of_year, int year, int *month, int *day)
{
    *month = 1;

    if(day_of_year - 31 > 0) {
        (*month)++;
        day_of_year -= 31;
    } else goto count_days;

    int days_of_feb = year % 4 ? 28 : 29;
    if(day_of_year - days_of_feb > 0) {
        (*month)++;
        day_of_year -= days_of_feb;
    } else goto count_days;

    if(day_of_year - 31 > 0) {
        (*month)++;
        day_of_year -= 31;
    } else goto count_days;

    if(day_of_year - 30 > 0) {
        (*month)++;
        day_of_year -= 30;
    } else goto count_days;

    if(day_of_year - 31 > 0) {
        (*month)++;
        day_of_year -= 31;
    } else goto count_days;

    if(day_of_year - 30 > 0) {
        (*month)++;
        day_of_year -= 30;
    } else goto count_days;

    if(day_of_year - 31 > 0) {
        (*month)++;
        day_of_year -= 31;
    } else goto count_days;

    if(day_of_year - 31 > 0) {
        (*month)++;
        day_of_year -= 31;
    } else goto count_days;

    if(day_of_year - 30 > 0) {
        (*month)++;
        day_of_year -= 30;
    } else goto count_days;

    if(day_of_year - 31 > 0) {
        (*month)++;
        day_of_year -= 31;
    } else goto count_days;

    if(day_of_year - 30 > 0) {
        (*month)++;
        day_of_year -= 30;
    }

    count_days:
    *day = day_of_year;
}

int main()
{
    int month, day;

    split_date(100, 2015, &month, &day);
    printf("Month: %d, day: %d\n", month, day);

    split_date(100, 2012, &month, &day);
    printf("Month: %d, day: %d\n", month, day);

    split_date(1, 2017, &month, &day);
    printf("Month: %d, day: %d\n", month, day);

    split_date(70, 2016, &month, &day);
    printf("Month: %d, day: %d\n", month, day);

    split_date(366, 2016, &month, &day);
    printf("Month: %d, day: %d\n", month, day);

    exit(EXIT_SUCCESS);
}
