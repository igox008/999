#include <stdio.h>

int main()
{
    char s[102];
    scanf("%s", s);
    int i = 0;
    int n = 0;
    while (s[i])
    {
        n = 1;
        if (!s[i])
            break ;
        else if (s[i] == s[i + 1])
        {
            char c = s[i++];
            while (s[i] && s[i] == c)
            {
                i++;
                n++;
            }
            // printf("%d\n", n);
            if (n >= 7)
                return (printf("YES\n"), 0);
        }
        else
            i++;
    }
    printf("NO\n");
}