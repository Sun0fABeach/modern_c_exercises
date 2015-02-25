#include <stdio.h>

int main() {
  int n, d;

  for(d = 2, n = 23; d*d < n; d++)
    if(n % d == 0)
      break;

  if(d*d < n)
    printf("%d is divisible by %d\n", n, d);
  else
    printf("%d is prime\n", n);

  return 0;
}
