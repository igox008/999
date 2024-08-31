#include <iostream>
#include <cmath>
using namespace std;

void prime_factorization(int n)
{
    cout << n << ":";

    while (n % 2 == 0)
    {
        cout << " 2";
        n /= 2;
    }
    
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            cout << " " << i;
            n /= i;
        }
    }

    if (n > 2)
        cout << " " << n;
    
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    prime_factorization(n);

    return 0;
}
