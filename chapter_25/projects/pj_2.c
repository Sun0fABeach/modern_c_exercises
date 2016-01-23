#include <stdlib.h>
#include <stdio.h>
#include <locale.h>


int main(int argc, char *argv[])
{
    if(argc < 2) {
        puts("usage: pj_2 locale");
        exit(EXIT_SUCCESS);
    }

    if(!setlocale(LC_ALL, argv[1])) {
        printf("unknown locale: %s\n", argv[1]);
        exit(EXIT_SUCCESS);
    }

    struct lconv *lc = localeconv();

    printf("decimal_point = \"%s\"\n", lc->decimal_point);
    printf("thousands_sep = \"%s\"\n", lc->thousands_sep);
    printf("grouping = %d\n", *lc->grouping);
    printf("mon_decimal_point = \"%s\"\n", lc->mon_decimal_point);
    printf("mon_thousands_sep = \"%s\"\n", lc->mon_thousands_sep);
    printf("mon_grouping = %d\n", *lc->mon_grouping);
    printf("positive_sign = \"%s\"\n", lc->positive_sign);
    printf("negative_sign = \"%s\"\n", lc->negative_sign);
    printf("currency_symbol = \"%s\"\n", lc->currency_symbol);
    printf("int_curr_symbol = \"%s\"\n", lc->int_curr_symbol);

    printf("frac_digits = %hhd\n", lc->frac_digits);
    printf("p_cs_precedes = %hhd\n", lc->p_cs_precedes);
    printf("n_cs_precedes = %hhd\n", lc->n_cs_precedes);
    printf("p_sep_by_space = %hhd\n", lc->p_sep_by_space);
    printf("n_sep_by_space = %hhd\n", lc->n_sep_by_space);
    printf("p_sign_posn = %hhd\n", lc->p_sign_posn);
    printf("n_sign_posn = %hhd\n", lc->n_sign_posn);

    printf("int_frac_digits = %hhd\n", lc->int_frac_digits);
    printf("int_p_cs_precedes = %hhd\n", lc->int_p_cs_precedes);
    printf("int_n_cs_precedes = %hhd\n", lc->int_n_cs_precedes);
    printf("int_p_sep_by_space = %hhd\n", lc->int_p_sep_by_space);
    printf("int_n_sep_by_space = %hhd\n", lc->int_n_sep_by_space);
    printf("int_p_sign_posn = %hhd\n", lc->int_p_sign_posn);
    printf("int_n_sign_posn = %hhd\n", lc->int_n_sign_posn);

	exit(EXIT_SUCCESS);
}
