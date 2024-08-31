#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned long long x, y, z;

    scanf("%llu %llu %llu", &x, &y, &z);
    if ((x && y) && (x > ULLONG_MAX / y || y > ULLONG_MAX / x))
        return (printf("Yes"), 0);
    if (x * y >= z)
        printf("Yes");
    else
        printf("No");
    return (0);
}