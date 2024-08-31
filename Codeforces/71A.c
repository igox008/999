#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[n][110];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int len;
        if ((len = strlen(s[i])) <= 10)
            printf("%s\n", s[i]);
        else
        {
            len--;
            printf("%c%d%c\n", s[i][0], len - 1, s[i][len]);
        }
    }   
}