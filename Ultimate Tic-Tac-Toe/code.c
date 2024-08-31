#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
    bool s;
}cor;

bool is_on_edge(int x, int y)
{
    if ((y == 0 || y == 2) && (x == 0 || x == 2))
        return (true);
    return (false);
}

cor vlaid_edge(char tic[3][3])
{
    cor tmp;
    tmp.s = true;
    if (tic[2][0] == '0')
    {
        tmp.x = 0;
        tmp.y = 2;
        return (tmp);
    }
    else if (tic[0][0] == '0')
    {
        tmp.x = 0;
        tmp.y = 0;
        return (tmp);
    }
    else if (tic[0][2] == '0')
    {
        tmp.x = 2;
        tmp.y = 0;
        return (tmp);
    }
    tmp.s = false;
    tmp.x = -2, tmp.y = -2;
    return (tmp);
}

cor can_he_won(char tic[3][3], char op, char own)
{
    cor t;
    t.s = true;
    // horizontal
    for (int i = 0; i < 3; i++)
    {
        if (tic[i][0] == op && tic[i][1] == op && tic[i][2] != own)
            return (t.x = 2, t.y = i, t);
        else if(tic[i][0] != own && tic[i][1] == op && tic[i][2] == op)
            return (t.x = 0, t.y = i, t);
        else if (tic[i][0] == op && tic[i][1] != own && tic[i][2] == op)
            return (t.x = 1, t.y = i, t);
    }
    // vertical
    for (int i = 0; i < 3; i++)
    {
        if (tic[0][i] == op && tic[1][i] == op && tic[2][i] != own)
            return (t.x = i, t.y = 2, t);
        else if(tic[0][i] != own && tic[1][i] == op && tic[2][i] == op)
            return (t.x = i, t.y = 0, t);
        else if (tic[0][i] == op && tic[1][i] != own && tic[2][i] == op)
            return (t.x = i, t.y = 1, t);
    }
    // special
    if (tic[0][0] == op && tic[1][1] == op && tic[2][2] != own)
        return (t.x = 2, t.y = 2, t);
    else if (tic[0][0] == op && tic[1][1] != own && tic[2][2] == op)
        return (t.x = 1, t.y = 1, t);
    else if (tic[0][0] != own && tic[1][1] == op && tic[2][2] == op)
        return (t.x = 0, t.y = 0, t);
    else if (tic[0][1] == op && tic[1][1] == op && tic[2][0] != own)
        return (t.x = 0, t.y = 2, t);
    else if (tic[0][2] == op && tic[1][1] != own && tic[2][0] == op)
        return (t.x = 1, t.y = 1, t);
    else if (tic[0][2] != own && tic[1][1] == op && tic[2][0] == op)
        return (t.x = 2, t.y = 0, t);

    t.s = false;
    t.x = -2, t.y = -2;
    return (t);
}

int main()
{

    // game loop
    static int iter;
    char tic[3][3] = {"000", "000",  "000"};
    bool i_starte_first = false;
    while (1) {
        int opponent_row;
        int opponent_col;
        scanf("%d%d", &opponent_row, &opponent_col);
        int valid_action_count;
        scanf("%d", &valid_action_count);
        char to[3][3] = {"000", "000",  "000"};
        for (int i = 0; i < valid_action_count; i++) {
            int row;
            int col;
            to[row][col] = 'V';
            scanf("%d%d", &row, &col);
        }
        int op_y = opponent_row;
        int op_x = opponent_col;
        tic[op_x][op_y] = 'O';
        if (op_y == -1 && op_x == -1)
        {
            printf("2 2\n");
            tic[2][2] = 'X';
            i_starte_first = true;
        }
        else if (iter == 0)
        {
            if (is_on_edge(op_x, op_y))
            {
                printf("1 1\n");
                tic[1][1] = 'X';
            }
            else
            {
                printf("2 2\n");
                tic[2][2] = 'X';
            }
        }
        else
        {
            cor tmp = can_he_won(tic, 'O', 'X');
            if (tmp.s && valid_action_count > 0)
            {
                printf("%d %d\n", tmp.x, tmp.y);
                tic[tmp.y][tmp.x] = 'X';
            }
            else if (!tmp.s)
            {
                cor m = can_he_won(tic, 'X', 'O');
                cor edge = vlaid_edge(tic);
                if (m.s)
                {
                    printf("%d %d\n", m.x, m.y);
                    tic[m.y][m.x] = 'X';
                }
                else if (edge.s)
                {
                    printf("%d %d\n", edge.x, edge.y);
                    tic[edge.y][edge.x] = 'X';
                }
            }
        }
        iter++;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fprintf(stderr, "%c", tic[i][j]);
            }
            fprintf(stderr, "\n");
        }
        
    }

    return 0;
}