#include <stdio.h>

int main() {
    double balance, rate, payment, num;

    printf("Enter amount of loan: ");
    scanf("%lf", &balance);
    printf("Enter interest rate: ");
    scanf("%lf", &rate);
    printf("Enter monthly payment: ");
    scanf("%lf", &payment);
    printf("Enter number of payments: ");
    scanf("%lf", &num);

    rate = rate / 100 / 12;

    for(int i = 0; i < num; i++) {
        balance = balance - payment + balance * rate;
        if(balance < 0.0) balance = 0.0;
        printf("Balance remaining after %d. payment: $%.2f\n", i+1, balance);
    }

    return 0;
}
