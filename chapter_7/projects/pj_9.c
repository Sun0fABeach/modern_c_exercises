#include <stdio.h>
#include <ctype.h>

int main() {
    unsigned char hour, minutes;
    char daytime;

    printf("Enter a 12-hour time: ");
    scanf("%2hhu :%2hhu %c", &hour, &minutes, &daytime);

    if(tolower(daytime) == 'p')
        hour += 12;

    printf("Equivalent 24-hour time: %2hhu:%.2hhu\n", hour, minutes);

    return 0;
}
