#include <stdio.h>

int main() {
  unsigned char nums[16];

  printf("Enter the numbers from 1 to 16 in any order:\n");

  for(int i = 0; i < 16; i++) {
    scanf("%hhu", nums+i);
    if(nums[i] > 16) nums[i] = 16;
    if(nums[i] < 1) nums[i] = 1;
  }

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++)
      printf("%3hhu", nums[i*4 + j]);
    putchar('\n');
  }


  unsigned char row_sum, col_sum, diag_sum;

  printf("Row sums:");
  for(int i = 0; i < 4; i++) {
    row_sum = 0;

    for(int j = 0; j < 4; j++)
      row_sum += nums[i*4 + j];

    printf(" %hhu", row_sum);
  }
  putchar('\n');

  printf("Column sums:");
  for(int i = 0; i < 4; i++) {
    col_sum = 0;

    for(int j = 0; j < 4; j++)
      col_sum += nums[i + j*4];

    printf(" %hhu", col_sum);
  }
  putchar('\n');

  printf("Diagonal sums:");
  for(int i = 0; i < 2; i++) {
    diag_sum = 0;

    for(int j = 0; j < 4; j++)
      diag_sum += nums[j*4 + j];

    printf(" %hhu", diag_sum);
  }
  putchar('\n');

  return 0;
}
