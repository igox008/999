#include <stdio.h>

int main()
{
    int l, b, c = 0;
    scanf("%d %d", &l, &b);
    while (1)
    {
        if (l > b)
            break ;
        l = l * 3;
        b = b * 2;
        c++;
    }
    printf("%d\n", c);
}