#include "char-utils.h"
#define MAXLINE 1000

/* Input needs UNIX-newlines! 
 * i.e. '\n', NOT '\r\n' */

/* read file from stdin, strip trailing whitespace, remove empty lines and
 * print to stdout */
int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
        if (remove_trailing_ws(line, len))
            printf("%s\n", line);
    return 0;
}
