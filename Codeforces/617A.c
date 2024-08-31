#include <stdio.h>

int main()
{
    int x, c= 0;
    scanf("%d", &x);
    while (x > 0)
    {
        while (x - 5 >= 0)
            (x -= 5, c++);
        while (x - 4 >= 0)
            (x -= 4, c++);
        while (x - 3 >= 0)
            (x -= 3, c++);
        while (x - 2 >= 0)
            (x -= 2, c++);
        while (x - 1 >= 0)
            (x -= 1, c++);
    }
    printf("%d\n", c);
}