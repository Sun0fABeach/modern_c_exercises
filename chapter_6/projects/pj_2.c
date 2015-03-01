#include <stdio.h>
#include <stdbool.h>

int main() {
  int m, n, rem;
  printf("Enter two integers: ");
  scanf("%d%d", &m, &n);

  while(n) {
    rem = m % n;
    m = n;
    n = rem;
  }

  printf("Greatest common divisor: %d\n", m);

  return 0;
}
