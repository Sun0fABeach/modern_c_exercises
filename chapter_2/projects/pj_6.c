#include <stdio.h>

int main() {
  double x;

  printf("Plz enter x: ");
  scanf("%lf", &x);

  double result = ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6;
  printf("Result: %f\n", result);

  return 0;
}
