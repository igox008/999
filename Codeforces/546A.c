#include <stdio.h>

int main()
{
    int k, n, w;
    scanf("%d %d %d", &k, &n, &w);
    int i = 0, t = 0;
    while (++i <= w)
    {
        t += k * i;
    }
    printf("%d\n", (n - t < 0) ? t - n : 0);
}