#include <stdio.h>

int main() {
  unsigned char i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, check,
                first_sum, second_sum, total, calced_check;

  printf("Enter an EAN (13 digits): ");
  scanf("%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu%1hhu",
      &i0, &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11, &check);

  first_sum = i1 + i3 + i5 + i7 + i9 + i11;
  second_sum = i0 + i2 + i4 + i6 + i8 + i10;
  total = 3 * first_sum + second_sum;
  calced_check = 9 - (total - 1) % 10;

  printf("Check digit: %hhu\n", calced_check);
  printf("%sVALID\n", calced_check == check ? "" : "IN");

  return 0;
}
