#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUUFER_SIZE 1000001

void    print_top(int *arr , int len)
{
    if (len < 0)
    {
        printf("Empty!\n");
        return ;
    }
    printf("%d\n", arr[len]);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *stck = malloc(1000000 * sizeof(int));
    int len = -1;
    for (int i = 0;i < n;i++)
    {
        int instruction;
        int push;
        scanf("%d", &instruction);
        if (instruction == 1)
        {
            scanf("%d", &push);
            len++;
            stck[len] = push;
        }
        else if (instruction == 2)
            (len >= 0) && (len--);
        else if (instruction == 3)
            print_top(stck, len);
    }
    free(stck);
}