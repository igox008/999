#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 1000000;

vector<unsigned long long> factorial(MAXN + 1);
vector<unsigned long long> invFactorial(MAXN + 1);

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

void get_facto()
{
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    invFactorial[MAXN] = mod_exp(factorial[MAXN], MOD - 2, MOD);
    for (int i = MAXN - 1; i >= 0; --i) {
        invFactorial[i] = invFactorial[i + 1] * (i + 1) % MOD;
    }
}

unsigned long long binomial_coefficient(int a, int b)
{
    if (b > a) return 0;
    return factorial[a] * invFactorial[b] % MOD * invFactorial[a - b] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    get_facto();

    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << binomial_coefficient(a, b) << '\n';
    }

    return 0;
}
