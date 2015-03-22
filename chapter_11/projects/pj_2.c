#include <stdio.h>
#include <stdlib.h>

void find_closest_flight(unsigned short desired_time,
                        unsigned short *dep_time,
                        unsigned short *arr_time)
{
    unsigned short departures[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    unsigned short arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    unsigned short prev_diff, new_diff;

    prev_diff = abs(desired_time - departures[0]);

    int i = 0;
    while(++i < 8) {
        new_diff = abs(desired_time - departures[i]);

        if(prev_diff < new_diff) {
            *dep_time = departures[i - 1];
            *arr_time = arrivals[i - 1];
            return;
        }
        prev_diff = new_diff;
    }
    *dep_time = departures[i - 1];
    *arr_time = arrivals[i - 1];
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
