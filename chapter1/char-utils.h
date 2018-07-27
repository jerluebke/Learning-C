/* NOTE:
 * When compiling with gcc, pass `-D_POSIX_SOURCE=0` */
#ifndef CHAR_UTILS_H
#define CHAR_UTILS_H

#include <stdio.h>


/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}


/* remove_trailing_ws: strip trailing whitespace from s and return new length
 * return 0 if line is empty or only whitespace */
int remove_trailing_ws(char s[], int len)
{
    if (len < 2)    /* only newline or empty */
        return 0;
    int i = len-1;
    while (i > 0 && (s[i-1] == ' ' || s[i-1] == '\t'))
        --i;
    if (i == 0)     /* whole line was whitespace */
        return 0;
    s[i] = '\0';
    return i;
}


/* reverse: reverse order of chars in array; assume s has a newline at the end */
void reverse(char s[], int len)
{
    int i, half;
    char tmp;
    i = 0;
    half = (len-1)/2;   /* don't look at \n, leave it in place */
    while (i < half) {
        tmp = s[len-i-2];
        s[len-i-2] = s[i];
        s[i] = tmp;
        ++i;
    }
}


#include <string.h>

/* reverse:  another more elegant version
 * example from section 3.5 */
void reverse_kr(char s[])
{
    int c, i, j;

    for (i = 0, j =  strlen(s)-1; i < j; ++i, --j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

#endif
