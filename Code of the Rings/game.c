#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    char m[] = "O OROFARNE LASSEMISTA CARNIMIRIE O ROWAN FAIR UPON YOUR HAIR HOW WHITE THE BLOSSOM LAY";
    // scanf("%[^\n]", m);
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    for (int i = 0; m[i]; i++)
    {
        if (m[i] >= 'A' && m[i] <= 'Z')
            m[i] += 32;
    }
    char low[29] = " abcdefghijklmnopqrstuvwxyz ";
    
    int i = 0;
    int j = 0;
    int len = 0;
    bool back = false;
    char init[31];
    int iter = 0;
    for (int l = 0; l < 31; l++)
        init[l] = ' ';
    while (m[i])
    {
        if (iter == 30)
        {
            iter = 0;
            back = true;
        }
        if (m[i] == ' ' && !back)
        {
            printf(".");
        }
        else if (!back)
        {
            if (m[i] <= 'm')
            {
                j = 0;
                if (!back)
                {
                    while (m[i] != low[j])
                    {
                        printf("+");
                        j++;
                    }
                }
                printf(".");
            }
            else if (m[i] >= 'n')
            {
                j = 27;
                while (m[i] != low[j])
                {
                    printf("-");
                    j--;
                }
                printf(".");
            }
        }
        else
        {
            if (m[i] == ' ')
            {
                if (init[iter] <= 'm' && init[iter] != ' ')
                {
                    while (init[iter] >= 'a')
                    {
                        printf("-");
                        init[iter]--;
                    }
                    // printf("-");
                }
                else if (init[iter] >= 'n' && init[iter] != ' ')
                {
                    while (init[iter] <= 'z')
                    {
                        printf("+");
                        init[iter]++;
                    }
                    // printf("+");
                }
                printf(".");
            }
            else
            {
                if (init[iter] == ' ')
                {
                    if (m[i] <= 'm' && m[i] != ' ')
                    {
                        int al = (m[i] - 'a');
                        for (int v = 0; v <= al; v++)
                        {
                            printf("+");
                        }
                    }
                    else if (m[i] >= 'n' && m[i] != ' ')
                    {
                        int al = ('z' - m[i]);
                        for (int v = 0; v <= al; v++)
                        {
                            printf("-");
                        }
                    }
                }
                else
                {
                    if (m[i] == ' ' && init[iter] != ' ')
                    {
                        if (init[iter] <= 'm')
                        {
                            int al = (init[iter] - 'a');
                            for (int v = 0; v < al;v++)
                            {
                                printf("-");
                            }
                        }
                        else if (init[iter] >= 'n')
                        {
                            int al = (init[iter] - 'a') + 1;
                            for (int v = 0; v <= al + 1;v++)
                            {
                                printf("+");
                            }
                        }
                    }
                    else
                    {
                        if (m[i] < init[iter])
                        {
                            while (m[i] != init[iter])
                            {
                                printf("-");
                                init[iter]--;
                            }
                        }
                        else if (m[i] > init[iter])
                        {
                            while (m[i] != init[iter])
                            {
                                printf("+");
                                init[iter]++;
                            }
                        }
                    }
                }
                printf(".");
            }
        }
        if (m[i + 1] != '\0')
            printf(">");
        if (!back)
            init[iter] = m[i];
        iter++;
        i++;
    }
    printf("\n");
    return 0;
}