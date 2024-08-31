#include <iostream>

using namespace std;

const int MOD = 1000000007;

unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod)
{
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main()
{
    unsigned long long N;
    cin >> N;

    cout << mod_exp(3, N, MOD) << '\n';

    return 0;
}
