#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_upper(char *s)
{
    int c = 0;
    int l = 0;
    int len = strlen(s);
    for (int i = 0;s[i];i++)
    {
        if (isupper(s[i]))
            c++;
        else if (islower(s[i]))
            l++;
        if (c > len / 2)
            return (1);
        else if (l > len / 2)
            return (0);
    }
    return ((c <= l) ? 0 : 1);
}

int main()
{
    char s[102];
    scanf("%s", s);
    if (is_upper(s))
    {
        for (int i = 0;s[i];i++)
            printf("%c", (char)toupper(s[i]));
    }
    else
    {
        for (int i = 0;s[i];i++)
            printf("%c", (char)tolower(s[i]));
    }
    printf("\n");
}