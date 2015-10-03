#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "inventory.h"


int comp_parts(const void *part1, const void *part2)
{
    return (*(Part*)part1).number < (*(Part*)part2).number ? -1 :
           (*(Part*)part1).number > (*(Part*)part2).number ? 1 : 0;
}


int main(int argc, char *argv[])
{
    if(argc < 4) {
        puts("usage: pj_9 dumpfile1 dumpfile2 mergefile");
        exit(EXIT_FAILURE);
    }

    FILE *dumpfile1, *dumpfile2, *mergefile;

    if((dumpfile1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((dumpfile2 = fopen(argv[2], "rb")) == NULL) {
        fclose(dumpfile1);
        fprintf(stderr, "Can't open file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    if((mergefile = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[3]);
        fclose(dumpfile1);
        fclose(dumpfile2);
        exit(EXIT_FAILURE);
    }

    size_t num_inv1, num_inv2;

    if(fread(&num_inv1, sizeof(num_inv1), 1, dumpfile1) == 0)
        goto end;
    if(fread(&num_inv2, sizeof(num_inv2), 1, dumpfile2) == 0)
        goto end;

    size_t num_merged_inv = num_inv1 + num_inv2;

    if(num_merged_inv > MAX_PARTS) {
        fputs("merged inventory would exceed max size\n", stderr);
        goto end;
    }

    Part inv[MAX_PARTS];

    if(fread(inv, sizeof(Part), num_inv1, dumpfile1) != num_inv1)
        goto end;
    if(fread(inv + num_inv1, sizeof(Part), num_inv2, dumpfile2) != num_inv2)
        goto end;

    qsort(inv, num_merged_inv, sizeof(Part), comp_parts);

    for(size_t i = 0; i < num_merged_inv-1; i++) {
        if(inv[i].number == inv[i+1].number) {
            if(strcmp(inv[i].name, inv[i+1].name) != 0) {
                fprintf(
                    stderr,
                    "inconsistency: parts %s and %s have different names"
                    " but the same number (%d). aborting merge\n",
                    inv[i].name, inv[i+1].name, inv[i].number
                );
                goto end;
            }
            inv[i].on_hand += inv[i+1].on_hand;
            memmove(inv+i+1, inv+i+2, sizeof(Part) * (num_merged_inv-(i+2)));
            num_merged_inv--;
        }
    }

    if(fwrite(&num_merged_inv, sizeof(num_merged_inv), 1, mergefile) == 0)
        goto end;
    fwrite(inv, sizeof(Part), num_merged_inv, mergefile);

    end:{}
    bool error_occurred = false;

    if(ferror(dumpfile1)) {
        fprintf(stderr, "error while reading from %s\n", argv[1]);
        error_occurred = true;
    } else if(ferror(dumpfile2)) {
        fprintf(stderr, "error while reading from %s\n", argv[2]);
        error_occurred = true;
    } else if(ferror(mergefile)) {
        fprintf(stderr, "error while writing to %s\n", argv[3]);
        error_occurred = true;
    }

    fclose(dumpfile1);
    fclose(dumpfile2);
    fclose(mergefile);

    exit(error_occurred ? EXIT_FAILURE : EXIT_SUCCESS);
}
