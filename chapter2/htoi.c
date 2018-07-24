#include <stdio.h>
#include "htoi.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        fputs("This program takes one argument...", stderr);
        return -1;
    }
    /* char *in;
     * if (argv[1][1] == 'x' || argv[1][1] == 'X')
     *     in = &argv[1][2];
     * else
     *     in = &argv[1][0];
     * printf("0x%s = %u\n", in, htoi(in)); */
    char *in = &argv[1][0];
    uint32_t dec = htoi(in);
    while (*in == '0' || *in == 'x' || *in == 'X')
        ++in;
    printf("0x%s = %u\n", in, dec);
    return 0;
}
