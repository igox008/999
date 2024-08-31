#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int out = 0;
    for (int i = 0; i < n; i++)
    {
        int x,y, z;
        scanf("%d %d %d", &x, &y, &z);
        int c = 0;
        if (x)c++;
        if (y)c++;
        if (z)c++;
        if (c > 1)
            out++;
    }
    printf("%d", out);
}