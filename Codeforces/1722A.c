#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int c_count(char *s, char c)
{
    int i = 0;
    for (;*s;s++)
    {
        if (*s == c)
            i++;
    }
    return (i);
}

int check_it(char *s)
{
    if (c_count(s, 'T') == 1 && c_count(s, 'i') == 1
        && c_count(s, 'm') == 1 && c_count(s, 'u') == 1
        && c_count(s, 'r') == 1)
        return (1);
    return (0);
}

int main()
{
    int n;
    scanf("%d", &n);
    int prnt[n];
    for (int i = 0; i < n;i++)
    {
        int len;
        char s[101];
        scanf("%d", &len);
        scanf("%s", s);
        if (len != 5 || !check_it(s))
            prnt[i] = 0;
        else
            prnt[i] = 1;
    }
    for (int i = 0;i < n;i++)
    {
        if (prnt[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
}