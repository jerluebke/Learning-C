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

/* takes a null-terminated string (with optional '0x') representing a hexa-
 * decimal number and return its decimal representation as an unsigned int
 * UINT32_MAX = 0xFFFFFFFF, longer input will be truncated
 * passing input containing non-hex chars is undefined behaviour */
uint32_t htoi(char *hex)
{
    uint32_t res, cur, pow;
    res = cur = pow = 0;
    char *tmp = hex;
    while (*hex++ != '\0');
    --hex;
    while ((hex != tmp) && (pow < 8)) {
        --hex;
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
        ++pow;
    }
    return res;
}

/* same as above, but with switch
 * is actually faster */
uint32_t htoi_s(char *hex)
{
    uint32_t res, cur, pow;
    res = cur = pow = 0;

    char *tmp = hex;
    while (*hex++ != '\0')
        ;
    --hex;

    while ((hex != tmp) && (pow < 8)) {
        --hex;
        switch (*hex) {
            case 'x':
            case 'X':
                goto end;
            case 'a':
            case 'A':
                cur = 10;
                break;
            case 'b' :
            case 'B':
                cur = 11;
                break;
            case 'c':
            case 'C':
                cur = 12;
                break;
            case 'd':
            case 'D':
                cur = 13;
                break;
            case 'e':
            case 'E':
                cur = 14;
                break;
            case 'f':
            case 'F':
                cur = 15;
                break;
            default:
                cur = *hex - '0';
                break;
        }
        res += sxtn[pow] * cur;
        ++pow;
    }

end:
    return res;
}
