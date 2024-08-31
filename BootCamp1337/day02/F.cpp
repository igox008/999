#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;cin >> n;
    vector <int> a(n);
    for (int i = 0;i<n;i++) cin >> a[i];
    int k;cin >> k;
    vector <int> b(k);
    for (int i = 0;i<k;i++)
    {
        cin >> b[i];
    }
    int i_a = 0, i_b = 0;
    while (i_a < n && i_b < k)
    {
        if (a[i_a] == b[i_b])
            i_b++;
        i_a++;
    }
    if (i_b == k)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}