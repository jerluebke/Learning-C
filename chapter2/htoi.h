#include <stdint.h>

static uint32_t sxtn[] = {
    1,
    16,
    256,
    4096,
    65536,
    1048576,
    16777216,
    268435456,
};

uint32_t htoi(char *hex)
{
    uint32_t res, cur, pow;
    res = cur = pow = 0;
    char *tmp = hex;
    while (*hex++ != '\0');
    hex--;
    while ((hex != tmp) && (pow < 8)) {
        hex--;
        if (*hex == 'x' || *hex == 'X')
            break;
        else if (*hex == 'a' || *hex == 'A')
            cur = 10;
        else if (*hex == 'b' || *hex == 'B')
            cur = 11;
        else if (*hex == 'c' || *hex == 'C')
            cur = 12;
        else if (*hex == 'd' || *hex == 'D')
            cur = 13;
        else if (*hex == 'e' || *hex == 'E')
            cur = 14;
        else if (*hex == 'f' || *hex == 'F')
            cur = 15;
        else
            cur = *hex - '0';
        res += sxtn[pow] * cur;
        pow++;
    }
    return res;
}
