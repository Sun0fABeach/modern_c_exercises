#include <stdlib.h>
#include <stdio.h>

#define INT32_C(n) n
#define UINT32_C(n) n##u
#define INT64_C(n) n##l


int main()
{
    printf("INT32_C: %zd\n", sizeof(INT32_C(1)));
    printf("UINT32_C: %zd\n", sizeof(UINT32_C(1)));
    printf("INT64_C: %zd\n", sizeof(INT64_C(1)));

	exit(EXIT_SUCCESS);
}
