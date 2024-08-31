#include <stdio.h>

typedef struct 
{
    int (*fp)(const char *, ...);
}l_t;

// int ft_printf(const char * str, ...)
// {

// }
// ft_printf = (int (*)(const char *, ...))0x7fff72629370;

int main(void)
{
    l_t n;

    n.fp = (int (*)(const char *, ...))0x7fff72629370;
    n.fp("%d ss ss ss %s", 15,"wwww\n");
}
