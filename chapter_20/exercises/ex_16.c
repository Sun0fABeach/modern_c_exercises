#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t   byte;
typedef uint16_t  word;
typedef uint32_t dword;


int main()
{
    union {
        struct {
            dword eax, ebx, ecx, edx;
        } dwrd;
        struct {
            word ax, _a, bx, _b, cx, _c, dx, _d;
        } wrd;
        struct {
            byte al, ah, _a1, _a2, bl, bh, _b1, _b2,
                 cl, ch, _c1, _c2, dl, dh, _d1, _d2;
        } bte;
    } regs;

    regs.dwrd.ebx = 0x12AB34CD;
    printf("Lower half of %X: %X\n", regs.dwrd.ebx, regs.wrd.bx);
    printf("Lower half of lower half of %X: %X\n",
            regs.dwrd.ebx, regs.bte.bh);

    exit(EXIT_SUCCESS);
}
