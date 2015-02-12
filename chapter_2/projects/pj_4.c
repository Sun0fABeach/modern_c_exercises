#include <stdio.h>

#define TAX_RATE 0.05f

int main() {
  float amount, with_tax;
  
  printf("Enter an amount: ");
  scanf("%f", &amount);

  with_tax = amount + amount * TAX_RATE;
  printf("With tax added: $%.2f\n", with_tax);

  return 0;
}
