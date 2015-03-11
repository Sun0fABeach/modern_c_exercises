#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char hour, minutes;
    unsigned short full_minutes, prev_diff, new_diff;
    unsigned short departures[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    unsigned short arrivals[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    printf("Enter a 24-hour time: ");
    scanf("%2hhu :%2hhu", &hour, &minutes);
    full_minutes = hour * 60u + minutes;

    prev_diff = abs(full_minutes - departures[0]);

    for(int i = 1; i < 8; i++) {
        new_diff = abs(full_minutes - departures[i]);

        if(prev_diff < new_diff) {
            printf(
                "Closest departure time is %2d:%.2d,"
                " arriving at %2d:%.2d\n",
                departures[i - 1] / 60u, departures[i - 1] % 60u,
                arrivals[i - 1] / 60u, arrivals[i - 1] % 60u
            );
            return 0;
        }
        prev_diff = new_diff;
    }

    printf(
        "Closest departure time is %2d:%.2d,"
        " arriving at %2d:%.2d\n",
        departures[7] / 60u, departures[7] % 60u,
        arrivals[7] / 60u, arrivals[7] % 60u
    );

    return 0;
}
