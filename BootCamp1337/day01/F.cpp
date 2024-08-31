#include <iostream>

using namespace std;

int main()
{
    string s;cin >> s;
    int i, j;cin >> i >> j;
    int iter = (j - i) / 2;
    for (int t = 0;t <= iter;t++)
    {
        char tmp = s[i - 1];
        s[i - 1] = s[j - 1];
        s[j - 1] = tmp;
        i++;j--;
    }
    cout << s << '\n';
}