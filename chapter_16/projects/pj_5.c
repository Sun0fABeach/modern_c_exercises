#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned short departure;
    unsigned short arrival;
} Times;


void find_closest_flight(unsigned short desired_time,
                        unsigned short *dep_time,
                        unsigned short *arr_time)
{
    Times times[8] = {
        {480, 616}, {583, 712}, {679, 811}, {767, 900},
        {840, 968}, {945, 1075}, {1140, 1280}, {1305, 1438}
    };
    unsigned short prev_diff, new_diff;

    prev_diff = abs(desired_time - times[0].departure);

    int i = 0;
    while(++i < 8) {
        new_diff = abs(desired_time - times[i].departure);

        if(prev_diff < new_diff) {
            *dep_time = times[i - 1].departure;
            *arr_time = times[i - 1].arrival;
            return;
        }
        prev_diff = new_diff;
    }
    *dep_time = times[i - 1].departure;
    *arr_time = times[i - 1].arrival;
}

int main()
{
    unsigned char hour, minutes;
    unsigned short dep_time, arr_time;

    printf("Enter a 24-hour time: ");
    scanf("%2hhu :%2hhu", &hour, &minutes);
    find_closest_flight(hour * 60 + minutes, &dep_time, &arr_time);

    printf(
        "Closest departure time is %2hu:%.2hu, arriving at %2hu:%.2hu\n",
        dep_time / 60, dep_time % 60, arr_time / 60, arr_time % 60
    );

    exit(EXIT_SUCCESS);
}
