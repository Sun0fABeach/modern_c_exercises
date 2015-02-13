#include <stdio.h>

int main() {
  unsigned short gs1, group_id, publisher;
  unsigned int item_num;
  unsigned char check_digit;

  printf("Enter ISBN: ");
  scanf("%hu -%hu -%hu -%u -%hhu",
      &gs1, &group_id, &publisher, &item_num, &check_digit);

  printf("GS1 prefix: %hu\n", gs1);
  printf("Group identifier: %hu\n", group_id);
  printf("Publisher code: %hu\n", publisher);
  printf("Item number: %u\n", item_num);
  printf("Check digit: %hhu\n", check_digit);

  return 0;
}
