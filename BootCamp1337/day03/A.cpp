#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int mod = 998244353;
    int max = 100000;
    vector <long long> v(max + 1);
    int n; cin >> n;
    v[0] = 1;
    for (int i = 1;i <= max;i++)
        v[i] = (v[i - 1] * i) % mod;
    cout << v[n] << '\n';
}
