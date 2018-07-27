#include <stdio.h>
#include "htoi.h"

#define MAX_ITER 1000000

int main(int argc, char **argv)
{
    if (argc < 2) {
        fputs("This program takes one argument...", stderr);
        return -1;
    }
    char *in = &argv[1][0];
    uint32_t dec;
    /* stress test */
    for (int i = 0; i < MAX_ITER; ++i)
        /* dec = htoi(in); */
        dec = htoi_s(in);
    while (*in == '0' || *in == 'x' || *in == 'X')
        ++in;
    printf("0x%s = %u\n", in, dec);
    return 0;
}
