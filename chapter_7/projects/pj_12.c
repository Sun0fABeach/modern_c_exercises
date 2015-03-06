#include <stdio.h>
#include <ctype.h>

int main() {
    double num1, num2;
    char op;

    printf("Enter an expression: ");

    if(!scanf("%lf", &num1))
        return 1;

    while((op = getchar()) != '\n') {
        if(!scanf("%lf", &num2))
            return 1;
        switch(op) {
            case '+':
                num1 += num2;
                break;
            case '-':
                num1 -= num2;
                break;
            case '*':
                num1 *= num2;
                break;
            case '/':
                num1 /= num2;
                break;
            default:
                return 1;
        }
    }

    printf("Value of expression: %.1lf\n", num1);

    return 0;
}
