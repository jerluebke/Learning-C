#include "char-utils.h"
#define MAXLINE 1000    /* maximum input line size */

/* print longest input line */
int main()
{
    int len;    /* current line length */
    int max;    /* max length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)    /* there was a line */
        printf("%s", longest);

    return 0;
}
