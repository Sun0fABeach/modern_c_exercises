#include <stdio.h>

int main() {
  unsigned char score;
  char letter_grade;

  printf("Enter numerical grade: ");
  scanf("%1hhu%*1hhu", &score);

  switch(score) {
    case 9: letter_grade = 'A'; break;
    case 8: letter_grade = 'B'; break;
    case 7: letter_grade = 'C'; break;
    case 6: letter_grade = 'D'; break;
    default: letter_grade = 'F'; break;
  }

  printf("Letter grade: %c\n", letter_grade);

  return 0;
}
