#include <stdio.h>

/* replaces escape sequences '\n'and '\t' in s with visible strings
 * representing them
 * t is assumed to provide sufficient space (Attention: '\n' (1 char) -> '\\n'
 * (2 chars)) */
void escape(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j] = 't';
                break;
            default:
                t[j] = s[i];
                break;
        }
        ++i, ++j;
    }
}

/* replaces strings in s representing escape sequences with their actual
 * counterparts
 * just as `escape` works only for '\n' and '\t' for now */
void descape(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (s[i] != '\0') {
        switch (s[i]) {
            case '\\':
                switch (s[i+1]) {
                    case 'n':
                        t[j] = '\n';
                        ++i;
                        break;
                    case 't':
                        t[j] = '\t';
                        ++i;
                        break;
                    default:
                        t[j] = s[i];
                        break;
                }
                break;
            default:
                t[j] = s[i];
        }
        ++i, ++j;
    }
}


int main()
{
    char sample[] = "\\\nHello there!\n\tGeneral Kenobi!\n\a";
    char esc_sample[100];
    char dec_sample[100];
    escape(sample, esc_sample);
    printf("escaped: %s\n", esc_sample);
    descape(esc_sample, dec_sample);
    printf("descaped: %s\n", dec_sample);
    return 0;
}
