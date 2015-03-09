#include <stdio.h>

int main() {
    const short temp_readings[30][24] = {{13, 24, 24}};

    short sum = 0;
    for(int day = 0; day < 30; day++)
        for(int hour = 0; hour < 24; hour++)
            sum += temp_readings[day][hour];

    printf("Average temperature: %.2f celsius.\n", (float) sum / (30*24));

    return 0;
}
