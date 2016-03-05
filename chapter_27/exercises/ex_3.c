#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>


int main()
{
    printf("%"PRId8"\n", INT8_C(255));
    printf("%12.4"PRId32"\n", INT32_C(123));
    printf("%-6"PRIo16"\n", UINT16_C(123));
    printf("%#"PRIx64"\n", UINT64_C(123));

	exit(EXIT_SUCCESS);
}
