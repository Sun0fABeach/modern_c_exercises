#include <stdlib.h>
#include <assert.h>
#include "queueADT.h"

int main()
{
    Queue *q = create();

    assert(is_empty(q));
    assert(shift(q) == 0);
    assert(first(q) == 0);
    assert(last(q) == 0);

    append(q, 1);
    assert(!is_empty(q));

    append(q, 2);
    append(q, 3);
    assert(first(q) == 1);
    assert(last(q) == 3);

    assert(shift(q) == 1);
    assert(first(q) == 2);
    assert(last(q) == 3);

    assert(shift(q) == 2);
    assert(first(q) == 3);
    assert(last(q) == 3);
    assert(shift(q) == 3);
    assert(is_empty(q));
    assert(shift(q) == 0);
    assert(first(q) == 0);
    assert(last(q) == 0);

    append(q, 1);
    assert(!is_empty(q));

    destroy(q);

    exit(EXIT_SUCCESS);
}
