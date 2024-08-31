#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int all[n];
    int c = 0;
    for (int i = 0;i < n;i++)
    {
        int s;
        scanf("%d", &s);
        all[i] = s;
    }
    int bar = all[k - 1];
    for (int i = 0;i < n;i++)
        (all[i] > 0 && all[i] >= bar) && (c++);
    printf("%d\n", c);
}