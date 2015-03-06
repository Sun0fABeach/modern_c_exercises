#include <stdio.h>

int main() {
    typedef signed char int8 ;
    typedef short int16;
    typedef int int32;

    printf("%zu %zu %zu\n", sizeof(int8), sizeof(int16), sizeof(int32));

    return 0;
}
