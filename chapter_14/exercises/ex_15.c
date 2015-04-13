#include <stdio.h>
#include <stdlib.h>

#define ENGLISH

int main()
{
#ifdef FRENCH
    puts("Inserez Le Disque 1");
#elif defined(ENGLISH)
    puts("Insert Disk 1");
#elif defined(SPANISH)
    puts("Inserte El Disco 1");
#endif

    exit(EXIT_SUCCESS);
}
