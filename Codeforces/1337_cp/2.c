#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h> 
#include <limits.h>

int main()
{
    int N, K;
    scanf("%d %d",&N, &K);
    char *s = malloc(INT_MAX);
    scanf("%s",s);
    int cnt = 0;
    int j = 0;
    int len;
    for (int i =0;s[i];i++)
    {
        len = 0;
        for (;s[i] != '\0' && s[i] == '1';i++)
            ;
        if (s[i] == '\0')
            break ;
        j = i;
        while (s[j] != '\0' && s[j] == '0')
        {
            len++;
            j++;
        }
        if (len >= K)
            cnt++;
    }
    free(s);
    printf("%d\n",cnt);
}