#include <stdio.h>

int main() {
  int amount;

  printf("Enter a dollar amount: ");
  scanf("%d", &amount);

  printf("$%d  bills: %d\n", 20, amount / 20);
  amount %= 20;
  printf("$%d  bills: %d\n", 10, amount / 10);
  amount %= 10;
  printf(" $%d  bills: %d\n", 5, amount / 5);
  amount %= 5;
  printf(" $%d  bills: %d\n", 1, amount);

  return 0;
}
