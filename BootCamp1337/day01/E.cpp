#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;cin >> s;
    int cnt = 1;
    vector <int> sizes;
    for (int i = 0;s[i];i++)
    {
        if (s[i + 1] && s[i] == s[i + 1])
            cnt++;
        else
        {
            sizes.push_back(cnt);
            cnt = 1;
        }
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    cout << sizes[0] << '\n';
}