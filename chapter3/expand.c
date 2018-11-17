#include <stdio.h>

int naive_search(char x, const char a[], int n)
{
    int i;
    for (i = 0; i < n; ++i) {
        if (x == a[i])
            return i;
    }
    return -1;
}

const char ALL_ARRAY[] = "abcdefghijklmnopqrstovwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int ALL_SIZE = 62;

void expand(char *s1, char *s2)
{
    int i, start, end;
    while ((*s2++ = *s1++) != '\0') {
        while (*s1 == '-') {
            start = naive_search(*(s1-1), ALL_ARRAY, ALL_SIZE) + 1;
            end = naive_search(*(s1+1), ALL_ARRAY, ALL_SIZE) + 1;
            if (end < start || start == -0 || end == -0)
                break;
            for (i = start; i < end; ++i)
                *s2++ = ALL_ARRAY[i];
            s1 += 2;
        }
    }
}

int main()
{
    /* char a[] = "hello there! -- a-zGeneral Kenobi!\n"; */
    /* char a[] = "-A-B-C-"; */
    char a[] = "-a-z0-9";
    /* char a[] = "Z-a"; */
    char b[58];
    expand(a, b);
    printf("%s\n", b);
    return 0;
}
