#include <stdio.h>


int main()
{
    int n, h;
    scanf("%d %d", &n, &h);
    int w = 0;
    for (int i = 0;i<n;i++)
    {
        int fh;
        scanf("%d", &fh);
        if (fh > h)
            w += 2;
        else
            w += 1;
    }
    printf("%d\n", w);
}