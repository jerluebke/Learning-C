#include "char-utils.h"
#define MAXLINE 1000

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0) {
        /* reverse(line, len); */
        reverse_kr(line);
        printf("%s", line);
    }
    return 0;
}
