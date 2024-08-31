#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int size)
{
    for (int i = 0;i < size;i++)
    {
        printf("%d", arr[i]);
        if (i + 1 != size)
            printf(" ");
    }
    printf("\n");
}

void ft_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void    sort(int *arr, int size)
{
    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j + 1 < size - i;j++)
        {
            if (arr[j] > arr[j + 1])
                ft_swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0;i < n;i++)
        scanf("%d", &arr[i]);
    sort(arr, n);
    print_arr(arr, n);
}