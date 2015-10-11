#include <stdlib.h>

char (*a[10])(int);
int (*b(int))[5];
float *(*c(void))(int);
void (*d(int, void (*y)(int)))(int);


int main()
{
    //a
    typedef char (*fnc_ptr_a)(int);
    typedef fnc_ptr_a fnc_ptr_arr_a[10];

    //b
    typedef int (*arr_ptr_b)[5];
    typedef arr_ptr_b fnc_ret_arr_ptr_b(int);

    //c
    typedef float *(*fnc_ptr_c)(int);
    typedef fnc_ptr_c fnc_ret_fnc_ptr_c(void);

    //d
    typedef void (*fnc_ptr_d)(int);
    typedef void (*inner_fnc_ptr_d)(int);
    typedef fnc_ptr_d fnc_ret_fnc_ptr_d(int, inner_fnc_ptr_d);

    fnc_ptr_a *pa = a;
    fnc_ret_arr_ptr_b *bp = b;
    fnc_ret_fnc_ptr_c *cp = c;
    fnc_ret_fnc_ptr_d *dp = d;

    exit(EXIT_SUCCESS);
}

int arr[2][5];
int (*b(int i))[5] {
    return arr + 1;
}


float f = 1.0;
float *x(int i) {
    return &f;
}
float *(*c(void))(int) {
    return x;
}


void y(int i) {}
void (*d(int i, void (*f)(int)))(int)
{
    return y;
}
