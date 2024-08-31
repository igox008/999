#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map <string, int> mp;
    for (int i = 0;i < n;i++)
    {
        string tmp;
        cin >> tmp;
        auto it = mp.find(tmp);
        if (it != mp.end())
            it->second += 1;
        else
            mp.insert(make_pair(tmp, 1));
    }
    int j = 0;
    for (auto t : mp)
    {
        if (t.second > j)
            j = t.second;
    }
    string out;
    for (auto t : mp)
    {
        if (t.second == j)
            out = t.first;
    }
    cout << out << " " << j << "\n";
}