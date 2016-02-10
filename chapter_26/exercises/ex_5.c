#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


char *vstrcat(const char *first, ...)
{
    if(first == NULL)
        return NULL;

    va_list ap1, ap2;
    const char *s;
    unsigned int len = strlen(first);

    va_start(ap1, first);
    va_copy(ap2, ap1);

    while((s = va_arg(ap1, const char *)) != NULL)
        len += strlen(s);

    char *buf = calloc(len + 1, sizeof(char));
    if(!buf)
        return NULL;

    strcat(buf, first);
    while((s = va_arg(ap2, const char *)) != NULL)
        strcat(buf, s);

    va_end(ap1);
    va_end(ap2);

    return buf;
}


int main()
{
    char *s = vstrcat("one ", "two", NULL);
    if(s != NULL) {
        puts(s);
        free(s);
    }

    s = vstrcat("one ", NULL);
    if(s != NULL) {
        puts(s);
        free(s);
    }

    s = vstrcat(NULL);
    if(s != NULL) {
        puts(s);
        free(s);
    }

	exit(EXIT_SUCCESS);
}
