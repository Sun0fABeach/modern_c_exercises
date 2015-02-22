#include <stdio.h>

int main() {
  int a, b, c, d;

  printf("Enter four integers: ");
  scanf("%d%d%d%d", &a, &b, &c, &d);

  if(b > a) {
    a ^= b;
    b ^= a;
    a ^= b;
  }

  if(d > c) {
    c ^= d;
    d ^= c;
    c ^= d;
  }

  printf("Largest: %d\n", a > c ? a : c);
  printf("Smallest: %d\n", b < d ? b : d);

  return 0;
}
