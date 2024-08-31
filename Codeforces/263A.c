#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct 
{
    int x;
    int y;
} t_corr;

void get_xy(t_corr *c, char arr[6][10])
{
    while (arr[c->y][0] != '\0')
    {
        c->x = 0;
        while (arr[c->y][c->x])
        {
            if (arr[c->y][c->x] == '1')
                return ;
            c->x++;
        }
        c->y++;
    }
}

void    shift_x(char arr[6][10])
{
    for (int i = 0; arr[i][0] != '\0';i++)
    {
        (1) && (arr[i][1] = arr[i][2], arr[i][2] = arr[i][4], arr[i][3] = arr[i][6], arr[i][4] = arr[i][8]);
        arr[i][5] = '\0';
    }
}

int main()
{
    t_corr c;
    int moves = 0;
    c.x = 0, c.y = 0;
    char matrix[6][10];
    for (int i = 0;i<5;i++)
    {
        scanf("%[^\n]%*c", matrix[i]);
    }
    matrix[5][0] = '\0';
    shift_x(matrix);
    get_xy(&c, matrix);
    if (c.y == 2)
    {
        if (c.x > 2)
        {
            while (c.x != 2)
            {
                c.x--;
                moves++;
            }
        }
        else if (c.x < 2)
        {
            while (c.x != 2)
            {
                c.x++;
                moves++;
            }
        }
    }
    else if (c.y > 2)
    {
        while (c.y != 2)
        {
            c.y--;
            moves++;
        }
        if (c.x > 2)
        {
            while (c.x != 2)
            {
                c.x--;
                moves++;
            }
        }
        else if (c.x < 2)
        {
            while (c.x != 2)
            {
                c.x++;
                moves++;
            }
        }
    }
    else if (c.y < 2)
    {
        while (c.y != 2)
        {
            c.y++;
            moves++;
        }
        if (c.x > 2)
        {
            while (c.x != 2)
            {
                c.x--;
                moves++;
            }
        }
        else if (c.x < 2)
        {
            while (c.x != 2)
            {
                c.x++;
                moves++;
            }
        }
    }
    printf("%d", moves);
}