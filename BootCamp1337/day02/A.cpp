#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int t;cin >> t;
    while (t--)
    {
        int n,k; cin >> n >> k;
        vector <int> v(n);
        for (int i = 0;i < n;i++) cin >> v[i];
        vector <int> sum;
        int max = 0;
        for (int i = 0;i < n;i++)
        {
            int tmp = 0;
            for (int j = 0;j < k && j + i < n;j++)
                tmp += v[j + i];
            if (tmp > max)
                max = tmp;
        }
        cout << max << '\n';
    }
}