#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char num1, num2;
    const char *ones[10] = {
        "zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
    };
    const char *teens[10] = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };
    const char *decades[10] = {
        NULL,
        NULL,
		"twenty",
		"thirty",
		"fourty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
    };

    printf("Enter a two-digit number: ");
    scanf("%1hhu%1hhu", &num1, &num2);

    printf("You entered the number: ");

    if(num1 == 1) {
        puts(teens[num2]);
    } else {
        if(num1 == 0) {
            if(num2 == 0)
                puts("zero");
            else
                puts(ones[num2]);
        } else {
            printf(decades[num1]);
            if(num2 == 0)
                putchar('\n');
            else
                printf("-%s\n", ones[num2]);
        }
    }

    exit(EXIT_SUCCESS);
}
