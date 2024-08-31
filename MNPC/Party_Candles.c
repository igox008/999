#include <unistd.h>
#include <stdio.h>
#include <math.h>
 
long long count_digits(long long nbr)
{
    long long i = 0;
    while (nbr / 10)
    {
        nbr /= 10;
        i++;
    }
    return i+1;
}
 
long long clones(long long nbr, long long digits)
{
    long long result = 0;
    for (int i = 0; i < digits; ++i) {
        result = result * 10 + nbr;
    }
 
    return result;
    
}
 
void count(long long arr[10], long long nbr)
{
    long long i = 0;
    long long digits = count_digits(nbr);
    if (nbr < 10)
    {
        while (i < 10)
        {
            if (i <= nbr)
                arr[i] = 1;
            else
                arr[i] = 0;
            i++;
        }
        return ;
    }
 
    arr[i++] = digits - 1;
    while (i <= nbr / pow(10, digits - 1) - 1)
        arr[i++] = digits;
    if (nbr >= clones(nbr / pow(10, digits - 1), digits))
        arr[i++] = digits;
    while (i < 10)
        arr[i++] = digits - 1;
}
 
void fill(long long arr[10])
{
    long long nbr = 0;
 
    scanf("%lld", &nbr);
    count(arr, nbr);
}
 
int main()
{
    long long nbr_tests = 0;;
    long long i = 0;
    scanf("%lld", &nbr_tests);
    long long cases[nbr_tests][10];
    while (i < nbr_tests)
    {
        fill(cases[i]);
        i++;
    }
    i = 0;
    long long j;
    while (i < nbr_tests)
    {
        j = 0;
        while (j < 9)
        {
            printf("%lld ", cases[i][j]);
            j++;
        }
        printf("%lld\n", cases[i][j]);
        i++;
    }
    return 0;
}
