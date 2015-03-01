#include <stdio.h>

int main() {
    unsigned char month_days, pos;

    printf("Enter number of days in month: ");
    scanf("%hhu", &month_days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%hhu", &pos);

    if(--pos > 6)
        pos %= 7;

    for(unsigned char i = 0; i < pos; i++)
        printf("   ");

    for(unsigned char cur_day = 1; cur_day <= month_days; cur_day++, pos++) {
        if(pos % 7 == 0 && pos)
            putchar('\n');
        printf("%3hhu", cur_day);
    }
    putchar('\n');

    return 0;
}
