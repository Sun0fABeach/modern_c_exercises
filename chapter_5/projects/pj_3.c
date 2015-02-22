#include <stdio.h>

int main() {
  float commission1, commission2, share_value, value;
  unsigned int num_shares;

  printf("Enter the value of the share: ");
  scanf("%f", &share_value);
  printf("Enter the number of the shares: ");
  scanf("%u", &num_shares);

  value = share_value * num_shares;

  if(value < 2500.00f)
    commission1 = 30.00f + .017f * value;
  else if(value < 6250.00f)
    commission1 = 56.00f + .0066f * value;
  else if(value < 20000.00f)
    commission1 = 76.00f + .0034f * value;
  else if(value < 50000.00f)
    commission1 = 100.00f + .0022f * value;
  else if(value < 500000.00f)
    commission1 = 155.00f + .0011f * value;
  else
    commission1 = 255.00f + .0009f * value;

  if(commission1 < 39.00f)
    commission1 = 39.00f;

  printf("First commission: $%.2f\n", commission1);


  if(num_shares < 2000)
    commission2 = 33.00f + 0.03 * num_shares;
  else
    commission2 = 33.00f + 0.02 * num_shares;

  printf("Second commission: $%.2f\n", commission2);

  return 0;
}
