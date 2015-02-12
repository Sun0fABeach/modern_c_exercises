#include <stdio.h>

int main() {
  double balance, rate, payment;

  printf("Enter amount of loan: ");
  scanf("%lf", &balance);
  printf("Enter interest rate: ");
  scanf("%lf", &rate);
  printf("Enter monthly payment: ");
  scanf("%lf", &payment);

  rate = rate / 100 / 12;

  for(int i = 0; i < 3; i++) {
    balance = balance - payment + balance * rate;
    printf("Balance remaining after %d. payment: $%.2f\n", i+1, balance);
  }

  return 0;
}
