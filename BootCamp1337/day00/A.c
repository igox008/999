#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        int t;
        scanf("%d", &t);
        if (t >= 0)
            printf("%d", t + 2);
        else
            printf("%d", t);
        if (i + 1 != n)
            printf(" ");
    }
    printf("\n");
}
