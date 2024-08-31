#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int total = 0;
    for (auto &t : v)
        total += t;
    unsigned long long n1 = 0, n2 = 0;
    for (auto &t : v)
    {
        if (n1 <= total / 2)
            n1 += t;
        else
            n2 += t;
    }
    cout << ((n1 > n2) ? n1 - n2 : n2 - n1) << '\n';
}