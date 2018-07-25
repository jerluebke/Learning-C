#include <stdio.h>

/* find first occurence of any char of s2 in s1
 * stdlib-implementation: strpbrk*/
int any(char *s1, char *s2)
{
    char c1, c2;
    char *scan1, *scan2;
    for (scan1 = s1; (c1 = *s1++) != '\0';)
        for (scan2 = s2; (c2 = *scan2++) != '\0';)
            if (c1 == c2)
                return (s1-scan1);
    return -1;
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fputs("This program takes two arguments...", stderr);
        return -1;
    }
    char *s1, *s2;
    s1 = argv[1];
    s2 = argv[2];
    printf("first occurence of any char of \"%s\" in \"%s\": %d\n",
            s2, s1, any(s1, s2));
    return 0;
}
