#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NUM_INTS 10000

int intcmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(int argc, char *argv[])
{
    FILE *source_fp;

    if (argc != 2) {
        fprintf(stderr, "usage: pj_18 source\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int buf[MAX_NUM_INTS];
    size_t num_ints;

    for(num_ints = 0; num_ints < MAX_NUM_INTS; num_ints++) {
        if(fscanf(source_fp, "%d", buf + num_ints) != 1) {
            if(ferror(source_fp)) {
                fclose(source_fp);
                fprintf(stderr, "error while reading file %s\n", argv[1]);
                exit(EXIT_FAILURE);
            }
            fclose(source_fp);
            break;
        }
    }

    if(num_ints == 0) {
        puts("empty file");
    } else {
        qsort(buf, num_ints, sizeof(int), intcmp);

        printf("Smallest: %d\n", buf[0]);
        printf("Largest: %d\n", buf[num_ints-1]);
        int middle = (num_ints-1) / 2;
        printf("Median: %d\n",
            num_ints % 2 ? buf[middle] : (buf[middle]+buf[middle+1]) / 2
        );
    }

    exit(EXIT_SUCCESS);
}
