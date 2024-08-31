#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

void    get_moves(string &path, int pos, list <string> &moves)
{
    path.erase(0, pos);
    if (path[0] == '.' && path[1] == '#')
        moves.push_back("UP\n");
    else
    {
        int len = 0;
        for (int i = 0;path[i] && path[i] == '.';i++)
            len++;
        if (len >= 3)
            moves.push_back("RIGHT\n");
        else if (len == 2)
            moves.push_back("DOWN\n");
        else
            moves.push_back("LEFT\n");
    }
}

int main()
{
    int indx;
    cin >> indx; cin.ignore();
    int nb_g;
    cin >> nb_g; cin.ignore();

    list <string> moves;
    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            string score_info;
            getline(cin, score_info);
        }
        for (int i = 0; i < nb_g; i++)
        {
            string gpu;
            int reg_0;
            int reg_1;
            int reg_2;
            int reg_3;
            int reg_4;
            int reg_5;
            int reg_6;
            cin >> gpu >> reg_0 >> reg_1 >> reg_2 >> reg_3 >> reg_4 >> reg_5 >> reg_6; cin.ignore();
            int pos = (indx == 0) ? reg_0 : ((indx == 1) ? reg_1 : reg_2);
            get_moves(gpu, pos, moves);
        }
        int t = 1;
        string prnt = "RIGHT\n";
        for (string &tmp : moves)
        {
            if (tmp == "UP\n")
            {
                cout << tmp;
                t = 0;
                break;
            }
            else
            {
                if (tmp == "LEFT\n")
                    prnt = tmp;
                else if (tmp == "DOWN\n" && prnt != "LEFT\n")
                    prnt = tmp;
            }
        }
        if (t)
            cout << prnt;
        moves.clear();
    }
}