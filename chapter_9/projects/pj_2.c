#include <stdio.h>
#include <stdlib.h>

float calc_tax(float income)
{
    if(income <= 750.00f)
        return income * 0.01f;
    else if(income <= 2250.00f)
        return 7.50f + 0.02f * (income - 750.00f);
    else if(income <= 3750.00f)
        return 37.50f + 0.03f * (income - 2250.00f);
    else if(income <= 5250.00f)
        return 82.50f + 0.04f * (income - 3750.00f);
    else if(income <= 7000.00f)
        return 142.50f + 0.05f * (income - 5250.00f);
    else
        return 230.00f + 0.06f * (income - 7000.00f);
}

int main() {
    float income;

    printf("Enter your income: ");
    scanf("%f", &income);

    printf("Your tax due: %.2f\n", calc_tax(income));

    exit(EXIT_SUCCESS);
}
