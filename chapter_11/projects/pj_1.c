#include <stdio.h>
#include <stdlib.h>

void pay_amount(int amount, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = amount / 20;
    amount %= 20;
    *tens = amount / 10;
    amount %= 10;
    *fives = amount / 5;
    *ones= amount % 5;
}

int main()
{
    int amount, twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    pay_amount(amount, &twenties, &tens, &fives, &ones);

    printf("$%d  bills: %d\n", 20, twenties);
    printf("$%d  bills: %d\n", 10, tens);
    printf(" $%d  bills: %d\n", 5, fives);
    printf(" $%d  bills: %d\n", 1, ones);

    exit(EXIT_SUCCESS);
}
