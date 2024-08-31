#include <stdio.h>

int main()
{
    int w;
    scanf("%d", &w);
    if (w % 2 != 0)
    {
        if ((((w / 2) + 1) % 2 == 0) && (((w / 2) % 2 == 0)))
        {
            printf("YES");
            return 0;
        }
        else
        {
            printf("NO");
            return 0;
        }
    }
    else
    {
        if (w > 2)
            printf("YES");
        else
            printf("NO");
    }
}