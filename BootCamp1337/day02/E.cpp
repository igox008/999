#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    map <int, int> mp;
    for (int i = 0;i<n;i++)
    {
        int tmp;cin >> tmp;
        mp[tmp]++;
    }
    int q;cin >> q;
    for (int i = 0;i < q;i++)
    {
        int tmp;cin >> tmp;
        if (mp[tmp] != 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}