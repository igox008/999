#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main()
{
    char    str[1001];
    scanf("%s", str);
    str[0] = (isalpha(str[0])) ? toupper(str[0]) : str[0];
    printf("%s\n", str);
    return (0);
}