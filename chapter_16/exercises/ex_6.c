#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

Time split_time(long total_seconds)
{
    return (Time){
        .hours = total_seconds / (60 * 60),
        .minutes = total_seconds % (60 * 60) / 60,
        .seconds = total_seconds % 60
    };
}

int main()
{
    Time d = split_time(3666l);

    printf("%d %d %d\n", d.hours, d.minutes, d.seconds);

    exit(EXIT_SUCCESS);
}
