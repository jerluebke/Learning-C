#include "char-utils.h"
#define MAXLINE 1000

/* TODO
 *  still buggy when whitespace is wildly all over the place... */

/* read file from stdin, strip trailing whitespace, remove empty lines and
 * print to stdout */
int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
        if (remove_trailing_ws(line, len) > 0)
            printf("%s", line);
    return 0;
}
