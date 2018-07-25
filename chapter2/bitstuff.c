#include <stdio.h>

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

int main()
{
    for (int x = 10; x < 100; x+=5) {
        for (int p = 1; p < x-3; ++p)
            printf("%d\n", setbits(x, p, 3, 5));
    }
}
