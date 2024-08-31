#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, k, n;
    cin >> t;
    for (int i = 0;i < t;i++)
    {
        cin >> n >> k;
        vector <int> in(n);
        int occ = 0;
        for (int j = 0;j < n;j++)
        {
            cin >> in[j];
            if (in[j] == k)
                occ++;
        }
        if (!occ)
            cout << "NO\n";
        else
            cout << "YES\n";
    } 
}