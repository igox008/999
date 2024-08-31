#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

void    ft_tolower(char *s)
{
    for (int i = 0; s[i];i++)
        s[i] = tolower(s[i]);
}

int main()
{
    char s1[101];
    char s2[101];
    
    scanf("%s", s1);
    scanf("%s", s2);
    ft_tolower(s1);
    ft_tolower(s2);
    int n = strcmp(s1, s2);
    printf("%d", n > 0 ? 1 : (n == 0 ? 0 : -1));
    return (0);
}