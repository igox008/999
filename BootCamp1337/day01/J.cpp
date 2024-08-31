#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

int main()
{
    int n;cin >> n;
    vector <int> arr(n);
    vector<vector <int> > teams(n, vector<int>(3, 0));
    int a = 0, b = 0, c = 0;
    // int clm = 0;
    for (int i = 0;i < n;i++)
    {
        int tmp;cin >> tmp;
        if (tmp == 1)
        {
            teams[a][0] = i + 1;
            a++;
        }
        else if (tmp == 2)
        {
            teams[b][1] = i + 1;
            b++;
        }
        else if (tmp == 3)
        {
            teams[c][2] = i + 1;
            c++;
        }
        // clm++;
    }
    int itr = min(a, min(b, c));
    cout << itr << '\n';
    for (int i = 0;i < itr;i++)
    {
        cout << teams[i][0] << " " << teams[i][1] << " " << teams[i][2] << '\n';
    }
}