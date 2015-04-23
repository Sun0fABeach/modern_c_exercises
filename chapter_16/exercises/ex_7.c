#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numerator;
    int denominator;
} Fraction;


Fraction reduce(Fraction frac)
{
  int a = frac.numerator, b = frac.denominator, c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return (Fraction){
      .numerator = frac.numerator/b, .denominator = frac.denominator/b
  };
}


Fraction add(Fraction f1, Fraction f2)
{
    int num1 = f1.numerator * f2.denominator;
    int num2 = f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return reduce((Fraction){num1 + num2, denom});
}


Fraction subtract(Fraction f1, Fraction f2)
{
    int num1 = f1.numerator * f2.denominator;
    int num2 = f2.numerator * f1.denominator;
    int denom = f1.denominator * f2.denominator;
    return reduce((Fraction){num1 - num2, denom});
}


Fraction mult(Fraction f1, Fraction f2)
{
    return reduce((Fraction){
        f1.numerator * f2.numerator, f1.denominator * f2.denominator
    });
}


Fraction divide(Fraction f1, Fraction f2)
{
    return reduce((Fraction){
        f1.numerator * f2.denominator, f2.numerator * f1.denominator
    });
}


int main()
{
    Fraction f1 = {12, 4};
    Fraction f2 = {7, 3};
    f1 = reduce(f1);

    printf("Reduced: %d/%d\n", f1.numerator, f1.denominator);
    Fraction f3 = add(f1, f2);
    printf("Added: %d/%d\n", f3.numerator, f3.denominator);
    f3 = subtract(f1, f2);
    printf("Subtracted: %d/%d\n", f3.numerator, f3.denominator);
    f3 = mult(f1, f2);
    printf("Multiplied: %d/%d\n", f3.numerator, f3.denominator);
    f3 = divide(f1, f2);
    printf("Divided: %d/%d\n", f3.numerator, f3.denominator);

    exit(EXIT_SUCCESS);
}
