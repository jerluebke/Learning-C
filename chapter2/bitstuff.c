#include <stdio.h>
#include "../itoa.h"

/* get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* replace subsequence of x of length n starting at p with y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x | (~(~0 << n) << p)) & ~((~y & ~(~0 << n)) << p);
}

/* starting from p, invert n bits */
unsigned invert(unsigned x, int p, int n)
{
    return (x | (~(~0 << n) << p)) & ~(((x >> p) & ~(~0 << n)) << p);
}

unsigned rightrot(unsigned x, int n)
{
    unsigned end, tmp = x, rot = x & ~(~0 << n);
    for (end = 0; tmp >>=1; ++end);
    return (x >> n) | (rot << (end+1-n));
}

unsigned bitcount_1(unsigned x)
{
    unsigned b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 1)
            ++b;
    return b;
}

unsigned bitcount_2(unsigned x)
{
    unsigned b;
    for (b = 0; x; x >>=1)
        b += x & 1;
    return b;
}

unsigned bitcount_3(unsigned x)
{
    unsigned b;
    for (b = 0; x; ++b)
        x &= x - 1;     /* deletes rightmost 1-bit */
    return b;
}

void print_res(unsigned in)
{
    char res1[32];
    /* printf("%s\trot %d\n%s\n\n", my_itoa(in, res1, 2), n, */
    /*         my_itoa(rightrot(in, n), res2, 2)); */
    printf("1bits(%s) = %u\n", my_itoa(in, res1, 2), bitcount_3(in));
}

int main()
{
    print_res(555456);
    print_res(789753);
    print_res(645159753);
    print_res(256153456);
}
