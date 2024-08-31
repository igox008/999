#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int get_max(int a, int b)
{
    return (a > b ? a : (a != b) ? b : -1);
}

long long round_up(int m, int n)
{
    double v = ceil((double)m / n);
    return (v);
}

int main()
{
    int h, w, square;
    scanf("%d %d %d", &h, &w, &square);

    long long n = 0;
    int tmp = square;
    int max = get_max(h, w);
    if (max == -1)
    {
        n = (int)ceil((double)h / tmp);
        int j = round_up(w, square);
        if (w > square)
            printf("%lld", (long long)n * j);
        else
            printf("%lld", n);
    }
    else
    {
        n = (int)ceil((double)max / tmp);
        int f = round_up((h == max ? w : h), square);
        printf("%lld", (f != 0) ? (long long)(n * f) : n);
    }
}