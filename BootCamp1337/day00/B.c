#include <stdio.h>
#include <stdlib.h>

int is_in_arr(int *arr, int size, int find)
{
    for (int i = 0; i < size;i++)
    {
        if (arr[i] == find)
            return (1);
    }
    return (0);
}

void print_arr(int *arr, int size)
{
    printf("%d\n", size);
    for (int i = 0;i < size;i++)
    {
        printf("%d", arr[i]);
        if (i + 1 != size)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int n1, n2;
    int *arr1;
    int *arr2;

    scanf("%d", &n1);
    arr1 = malloc(n1 * sizeof(int));
    for (int i = 0;i < n1;i++)
        scanf("%d", &arr1[i]);
    scanf("%d", &n2);
    arr2 = malloc(n2 * sizeof(int));
    for (int i = 0;i < n2;i++)
        scanf("%d", &arr2[i]);
    int *arr = malloc(100 * sizeof(int));
    int size = 0;
    for (int i = 0;i < n1;i++)
    {
        if (!is_in_arr(arr2, n2, arr1[i]))
        {
            arr[size] = arr1[i];
            size++;
        }
    }
    print_arr(arr, size);
    free(arr);
    free(arr1);
    free(arr2);
}