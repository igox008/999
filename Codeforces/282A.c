#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        char oper[4];
        scanf("%s", oper);
        if (strchr(oper, '+') != NULL)
            c++;
        else
            c--;
    }
    printf("%d", c);
}