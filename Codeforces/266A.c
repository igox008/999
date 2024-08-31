#include <stdio.h>

int main()
{
    char s[52];int n, c = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0;s[i];i++)
    {
        if (s[i] == s[i + 1])
            c++;
    }
    printf("%d\n", c);
}