#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main()
{
    unsigned int years;
    float deposit, interest_rate;

    printf("Enter original amount deposited: ");
    scanf("%f", &deposit);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter years: ");
    scanf("%u", &years);

    printf("Final account value: %.2lf\n",
            deposit * exp(years * interest_rate));

    exit(EXIT_SUCCESS);
}
