#include <stdlib.h>

struct t {
    int i;
};

void insert(){};
void search(){};
void update(){};
void print(){};

//a
char *(*p)(char *);
//b
void (*f(struct t, long))();
//c
void (*a[4])() = {insert, search, update, print};
//d
struct t (*b[10])(int, int);


int main()
{
    exit(EXIT_SUCCESS);
}
