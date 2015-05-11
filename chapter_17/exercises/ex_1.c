#include <stdio.h>
#include <stdlib.h>

void *myAlloc(size_t size)
{
    void *p = malloc(size);
    if(!p) {
        fprintf(stderr, "Could not allocate a memory block size %zd\n", size);
        exit(EXIT_FAILURE);
    }
    return p;
}


int main()
{
    int *p = myAlloc(10 * sizeof(int));
    free(p);

    exit(EXIT_SUCCESS);
}
