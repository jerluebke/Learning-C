#include <stdio.h>
#include <string.h>

/* reverse string in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)     /* record sign */
        n = -n;             /* make n positive */
    i = 0;
    do {    /* write digits in reversed order in s */
        s[i++] = n % 10 + '0';  /* get next digit, +'0' -> int to char */
    } while ((n /= 10) > 0);    /* delete previous digit (shift n) */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[10];
    int n;
    /* n = 1337; */
    /* n = 420; */
    /* n = 314159265; */
    n = -2147483648;    /* doesn't work, because n -> -n is out of bounds by one */
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}
