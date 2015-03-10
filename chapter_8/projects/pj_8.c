#include <stdio.h>
#include <stdbool.h>

int main() {
    unsigned int a[5][5], sum, low, high, score;

    for(int student = 0; student < 5; student++) {
        printf("Quiz grades student %d: ", student + 1);
        for(int quiz = 0; quiz < 5; quiz++)
            scanf("%u", *(a + student) + quiz);
    }

    for(int student = 0; student < 5; student++) {
        sum = 0u;
        printf("Results student %d:\n", student + 1);
        for(int quiz = 0; quiz < 5; quiz++)
            sum += a[student][quiz];
        printf("Total score: %u, ", sum);
        printf("Average score: %.2lf\n", sum / 5.0);
    }

    putchar('\n');
    for(int quiz = 0; quiz < 5; quiz++) {
        sum = 0u;
        low = a[0][quiz];
        high = a[0][quiz];

        printf("Results quiz %d:\n", quiz + 1);
        for(int student = 0; student < 5; student++) {
            score = a[student][quiz];
            sum += score;
            if(score < low) low = score;
            if(score > high) high = score;
        }
        printf("Average score: %.2lf, ", sum / 5.0);
        printf("High score: %u, ", high);
        printf("Low score: %u\n", low);
    }

    return 0;
}
