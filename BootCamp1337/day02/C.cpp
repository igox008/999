#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;cin >> t;
    while (t--)
    {
        int n;cin >>n;
        vector <int> v(n);
        for (int i = 0;i<n;i++)
        {
            cin >> v[i];
        }
        int tmp = 1;
        int min = 2147483647;
        int max = 0;
        for (int i = 0;i < n;i++)
        {
            tmp = 1;
            for (int j = i;j < n;j++)
            {
                if (j + 1 !=n && v[j + 1] - v[j] <= 2)
                    tmp++;
                else
                {
                    i = j;
                    break;
                }
            }
            if (tmp < min)
                min = tmp;
            if (tmp > max)
                max = tmp;
        }
        cout << min << " " << max << '\n';
    }
}