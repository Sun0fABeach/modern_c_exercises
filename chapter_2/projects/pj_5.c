#include <stdio.h>
#include <math.h>

int main() {
  double x;

  printf("Plz enter x: ");
  scanf("%lf", &x);

  double result = 3*pow(x, 5) + 2*pow(x, 4) - 5*pow(x, 3) - pow(x, 2) + 7*x - 6;
  printf("Result: %f\n", result);

  return 0;
}
