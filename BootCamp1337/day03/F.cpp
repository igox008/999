#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int MOD = 1000000007;

unsigned long long mod_exp(unsigned long long x, unsigned long long y, unsigned long long p)
{
    unsigned long long result = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            result = (result * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return result;
}

void set_fac_inv(int n, vector<unsigned long long>& factorial, vector<unsigned long long>& inv_factorial)
{
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i)
        factorial[i] = factorial[i - 1] * i % MOD;
    inv_factorial[n] = mod_exp(factorial[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; --i)
        inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD;
}

int main()
{
    string s;cin >> s;
    
    int n = s.size();

    vector<unsigned long long> factorial(n + 1), inv_factorial(n + 1);
    set_fac_inv(n, factorial, inv_factorial);
    
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;
    
    unsigned long long result = factorial[n];
    for (const auto& entry : freq)
        result = result * inv_factorial[entry.second] % MOD;
    
    cout << result << '\n';
    
    return 0;
}
