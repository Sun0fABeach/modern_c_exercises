#include <stdio.h>
#include <math.h>

int main() {
  float r;

  printf("Plz enter the radius of the sphere: ");
  scanf("%f", &r);

  float v = 4.0 / 3 * M_PI * pow(r, 3);
  printf("Volume: %f\n", v);

  return 0;
}
