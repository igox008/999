#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;cin >> n;
    vector <int> v(n);
    unsigned long long moves = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> v[i];
        if (i > 0 && v[i] < v[i - 1])
        {
            moves += v[i - 1] - v[i];
            v[i] = v[i - 1];
        }
    }
    cout << moves<< '\n';
}