#include <stdio.h>

int main() {
    float f = 10.1234;

    printf("%d\n", (int) f);
    printf("%f\n", f - (int) f);

    f = 10.123446785623478658234756789345626378632348956e20;

    printf("%d\n", (int) f);
    printf("%f\n", f - (int) f);

    return 0;
}
