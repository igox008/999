#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;cin >> n;
    for (int i = 0;i < n;i++)
    {
        int k;cin >> k;
        int m_bag=0, b_bag=0;
        for (int j = 0;j < k;j++)
        {
            int cand;cin >> cand;
            if (cand % 2 == 0)
                m_bag += cand;
            else
                b_bag += cand;
        }
        if (m_bag > b_bag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}