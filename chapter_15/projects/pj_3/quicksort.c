#include <stdbool.h>
#include "quicksort.h"

static int split(int a[], int low, int high);

void quicksort(int a[], int low, int high)
{
    int middle;

    if(low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle-1);
    quicksort(a, middle + 1, high);
}

static int split(int a[], int low, int high)
{
    int part_element = a[low];

    while(true) {
        while(low < high && part_element <= a[high])
            high--;
        if(low >= high) break;
        a[low++] = a[high];

        while(low < high && a[low] <= part_element)
            low++;
        if(low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}
