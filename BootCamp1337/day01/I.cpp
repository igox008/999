#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;cin >> n >> k;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string s;
    k = (k > 26) ? 26 : k;
    int l = 0;
    for (int i = 0;i < n;i++)
    {
        if (l == k)
            l = 0;
        s += alphabet[l];
        l++;
    }
    cout << s << '\n';
}